// A1030 Travel Plan
//----题意----
// 有N个城市，编号为0~N-1、M条道路（无向边）、并给出M条道路的距离属性与花费属性
// 现在给定起点S和终点D，求从起点到终点的最短路径、最短距离、以及花费
// 注意：如果有多条最短路径，则选择花费最小的那条

//----思路----
// 本题除了求最短距离外，还要求 最短路径、以及 最短路径上的最小花费之和

//---Dijkstra算法---
#include "C.h"

const int MAXV = 510;
const int INF = 1000000000;

int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV], pre[MAXV];
bool vis[MAXV] = { false };

void Dijkstra(int s) 
{
	fill(d, d + MAXV, INF);
	fill(c, c + MAXV, INF);

	for (int i = 0; i < n; i++) pre[i] = i;

	//---起点s到达自身的距离为0---
	//---起点s到达自身的花费为0---
	d[s] = 0;
	c[s] = 0;

	for (int i = 0; i < n; i++) 
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) 
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		if (u == -1) 
			return;

		vis[u] = true;
		for (int v = 0; v < n; v++) 
		{
			if (vis[v] == false && G[u][v] != INF) 
			{
				if (d[u] + G[u][v] < d[v]) 
				{
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v]) 
				{
					if (c[u] + cost[u][v] < c[v])
					{
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

//---打印路径---
void DFS(int v) 
{
	if (v == st) 
	{
		printf("%d ", v);
		return;
	}

	DFS(pre[v]);
	printf("%d ", v);
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &st, &ed);

	int u, v;
	//---初始化图G---
	fill(G[0], G[0] + MAXV * MAXV, INF);

	for (int i = 0; i < m; i++) 
	{
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);

		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}

	//---Dijkstra算法入口---
	//---打印路径---
	Dijkstra(st);
	DFS(ed);

	//---最短距离、最短路径下的最小花费---
	printf("%d %d\n", d[ed], c[ed]);
	return 0;
}
