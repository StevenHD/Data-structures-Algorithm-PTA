// A1003. Emergency 最短路径
// 16：26 -- 17：34

#include "C.h"

//---定义一个最大顶点数和无穷大---
const int MAXV = 510;
const int INF = 1000000000;


//--n为顶点数，m为边数，st和ed分别为起点和终点--
int n, m, st, ed;

//--G[][]为邻接矩阵，weight[]为点权--
int G[MAXV][MAXV], weight[MAXV];

//--d[]记录最短距离，w[]记录最大点权之和，num[]记录最短路径条数--
int d[MAXV], w[MAXV], num[MAXV];

//--vis[i] == true表示顶点i已经访问，初始值均为false--
bool vis[MAXV] = { false };

//--s表示起点--
void Dijkstra(int s) 
{
	fill(d, d + MAXV, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));

	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;

	//---循环n次---
	for (int i = 0; i < n; i++) 
	{
		//--u使d[u]最小，MIN存放该最小的d[u]--
		int u = -1, MIN = INF;

		//--找到未访问的顶点中d[]最小的--
		for (int j = 0; j < n; j++) 
		{
			if (vis[j] == false && d[j] < MIN) 
			{
				u = j;
				MIN = d[j];
			}
		}

		//--找不到小于INF的d[u]，说明剩下的顶点和起点s不连通--
		if (u == -1) 
			return;

		//--此时，标记u为已经访问--
		vis[u] = true;


		for (int v = 0; v < n; v++) 
		{
			//--如果顶点v没有被访问，顶点u可以到达v，以u为中介点可以使d[v]更优--
			if (vis[v] == false && G[u][v] != INF) 
			{
				//--以u为中介点时能令d[v]变小--
				if (d[u] + G[u][v] < d[v]) 
				{
					//--覆盖d[v]和w[v]--
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];

					//--覆盖num[v]--
					num[v] = num[u];
				}

				//--找到一条相同长度的路径--
				else if (d[u] + G[u][v] == d[v]) 
				{
					//--以u为中介点的时候点权之和更大--
					if (w[u] + weight[v] > w[v])
					{
						//--w[v]继承自w[u]--
						w[v] = w[u] + weight[v];
					}

					//--把num[]最短路径条数写在外面的原因是：
					//--最短路径条数与点权无关，所以必须写在外面--
					num[v] += num[u];       // num[u]一般是1，因为u是中介点，和s是直接相连的。
				}
			}
		}
	}
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &st, &ed);    // 输入顶点数，边数，起点和终点
	for (int i = 0; i < n; i++) 
	{
		//--读入点权--
		scanf("%d", &weight[i]);    
	}
	

	//--输入一条边的两个端点u和v--
	int u, v;

	//--初始化图G--
	fill(G[0], G[0] + MAXV * MAXV, INF);


	for (int i = 0; i < m; i++) 
	{
		//--依次输入每条边的两个顶点u和v--
		//--还有u和v之间的边权--
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}

	//--Dijkstra算法入口--
	Dijkstra(st);

	//--最短距离条数，最短路径中的最大点权--
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}

