//  A1018. Public Bike Management

//----------CODE----------

#include "C.h"

//--最大顶点数--
const int MAXV = 510;

//--无穷大--
const int INF = 1000000000;

//--Cmax为最大容量，Sp为问题站点--
int n, m, Cmax, Sp, numPath = 0, G[MAXV][MAXV], weight[MAXV];

//--minNeed记录PBMC最少携带的数目，minRemain记录PBMC最少带回的数目--
int d[MAXV], minNeed = INF, minRemain = INF;

//--vis[i] == true表示顶点i已访问，初始均为false--
bool vis[MAXV] = { false };

//--pre表示前驱，tempPath则表示临时路径，path表示最优路径--
vector<int> pre[MAXV];
vector<int> tempPath, path;


//--s为起点--
void Dijkstra(int s) 
{
	fill(d, d + MAXV, INF);
	for (int i = 0; i <= n; i++) 
	{
		pre[i].push_back(i);
	}

	d[s] = 0;


	for (int i = 0; i <= n; i++)      // 这里写成(i<n)或(i<=n)结果没有区别
									  // 也就是循环n次和循环n+1次没有区别
	{
		int u = -1, MIN = INF;

		//--找到未访问的顶点中d[]最小的--
		for (int j = 0; j <= n; j++) 
		{
			if (vis[j] == false && d[j] < MIN) 
			{
				u = j;
				MIN = d[j];
			}
		}

		//--找不到小于INF的d[u]，说明剩下的顶点和起点s不连通--
		if (u == -1) return;

		//--标记u为已访问--
		vis[u] = true;


		for (int v = 0; v <= n; v++) 
		{
			//--如果v未访问，并且u能到达v--
			if (vis[v] == false && G[u][v] != INF) 
			{
				if (d[u] + G[u][v] < d[v]) 
				{
					//--优化d[v]--
					d[v] = d[u] + G[u][v];

					pre[v].clear();
					pre[v].push_back(u);
				}

				else if (d[u] + G[u][v] == d[v]) 
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}



void DFS(int v) 
{
	if (v == 0) 
	{
		//--递归边界，叶子结点--
		tempPath.push_back(v);

		//--路径上tempPath上需要携带的数目，需要带回的数目--
		int need = 0, remain = 0;

		//--此处必须倒着枚举--
		for (int i = tempPath.size() - 1; i >= 0; i--) 
		{
			//--当前结点编号为id--
			int id = tempPath[i];

			//--如果点权大于0，说明需要带走一部分自行车--
			if (weight[id] > 0) 
			{
				remain += weight[id];
			}

			//--如果点权不超过0，需要补给--
			else
			{
				//--如果当前持有量remain足够补给--
				if (remain > abs(weight[id])) 
				{
					//--那么就用当前持有量remain减去需要补给的量--
					remain -= abs(weight[id]);
				}

				//--如果当前持有量remain不够补给--
				else
				{
					//--不够的部分从PBMC携带--
					need += abs(weight[id]) - remain;

					//--当前持有的自行车全部用来补给，所以归0--
					remain = 0;
				}
			}
		}


		//--如果需要从PBMC携带的自行车数目可以更少--
		if (need < minNeed) 
		{
			//--那么就优化minNeed--
			minNeed = need;

			//--同时覆盖minRemain--
			minRemain = remain;

			//--还要覆盖最优路径path--
			path = tempPath;
		}

		//--如果携带数目相同，带回数目变少--
		else if (need == minNeed && remain < minRemain) 
		{
			//--那么就优化minRemain--
			minRemain = remain;

			//--还要覆盖最优路劲path--
			path = tempPath;
		}

		tempPath.pop_back();    // 为什么要删除尾元素？
		return;
	}


	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}

	tempPath.pop_back();        // 这里也要删除尾元素？  
}




int main() 
{
	scanf("%d%d%d%d", &Cmax, &n, &Sp, &m);

	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);

	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &weight[i]);

		//--点权减去容量的一半--
		weight[i] -= Cmax / 2;
	}

	for (int i = 0; i < m; i++) 
	{
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);

		G[v][u] = G[u][v];
	}


	Dijkstra(0);
	DFS(Sp);

	//---输出需要从PBMC携带的最少bike数目---
	printf("%d ", minNeed);

	//---输出仿真最优路径---
	for (int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d", path[i]);
		if (i > 0) printf("->");
	}

	//---输出需要从问题站Sp带回的最少bike数目---
	printf(" %d", minRemain);
	return 0;
}
