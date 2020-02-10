// A1003 Emergency

//-----题意-----
// 给出N个城市，M条无向边。每个城市中都有一定数目的救援小组，所有边的边权已知。
// 现在给出起点和终点，求从起点到终点的最短路径条数
// 及最短路径上的救援小组数目之和
// 如果有多条最短路径，则输出数目之和最大的

//-----思路-----
// 本题在求解最短距离的同时，还需要求解另外两个信息：
// 最短路径条数和最短路径上的最大点权之和
// 令w[u]表示从起点s到达顶点u可以得到的最大点权之和，初始为0
// 令num[u]表示从起点s到达顶点u的最短路径条数，初始化时只有num[s]为1，其余num[u]均为0
// 这样在更新d[v]的同时也更新这两个数组

//-----注意点-----
// C1：注意输出的第一个数是最短路径条数，而不是最短距离
// C2：注意题目读入的顶点下标范围是0~n-1，且边是无向边
// C3：最短路径条数的依据仅仅是第一标尺，距离，和点权无关

//------CODE------
#include "C.h"

//---最大顶点数---
//---无穷大---
const int MAXV = 510;
const int INF = 1000000000;


//---numsOfVerts为顶点数、numsOfEdges为边数---
//---stPoint和edPoint分别为起点和终点---
//---adjacencyMatrix[][]为邻接矩阵，nodeWeight为点权---
//---shortestDistance[]记录最短距离、maxSumOfNodeWeight[]记录最大点权之和---
//---numsOfShortestPath[]记录最短路径条数---

int numsOfVerts;
int numsOfEdges;

int stPoint;
int edPoint;

int adjacencyMatrix[MAXV][MAXV];
int nodeWeight[MAXV];

int shortestDistance[MAXV];
int maxSumOfNodeWeight[MAXV];

int numsOfShortestPath[MAXV];


bool vis[MAXV] = { false };

void Dijkstra(int s) 
{
	//---s为起点---
	fill(shortestDistance, shortestDistance + MAXV, INF);

	/*memset(numsOfShortestPath, 0, sizeof(numsOfShortestPath));*/
	fill(numsOfShortestPath, numsOfShortestPath + sizeof(numsOfShortestPath), 0);

	/*memset(maxSumOfNodeWeight, 0, sizeof(maxSumOfNodeWeight));*/
	fill(maxSumOfNodeWeight, maxSumOfNodeWeight + sizeof(maxSumOfNodeWeight), 0);

	shortestDistance[s] = 0;
	maxSumOfNodeWeight[s] = nodeWeight[s];
	numsOfShortestPath[s] = 1;

	for (int i = 0; i < numsOfVerts; i++) 
	{
		int u = -1;  // 为什么很多变量的初值都爱给-1?
		int MIN = INF;

		for (int j = 0; j < numsOfVerts; j++) 
		{
			if (vis[j] == false && shortestDistance[j] < MIN) 
			{
				u = j;
				MIN = shortestDistance[j];
			}
		}

		if (u == -1) 
			return;

		vis[u] = true;

		for (int v = 0; v < numsOfVerts; v++)  // 为什么v的初值不设为1，因为起点s是0？
		{
			if (vis[v] == false && adjacencyMatrix[u][v] != INF) 
			{
				if (shortestDistance[u] + adjacencyMatrix[u][v] < shortestDistance[v]) 
				{
					//---当以u为中介点时能令shortDistance[v]变小的时候---
					//---覆盖更新shortDistance[v]---
					//---覆盖更新maxSumOfNodeWeight[v]---
					shortestDistance[v] = shortestDistance[u] + adjacencyMatrix[u][v];
					maxSumOfNodeWeight[v] = maxSumOfNodeWeight[u] + nodeWeight[v];

					//---覆盖更新最短路径条数---
					numsOfShortestPath[v] = numsOfShortestPath[u];
				}

				else if (shortestDistance[u] + adjacencyMatrix[u][v] == shortestDistance[v]) 
				{
					//---找到一条相同长度的路径---
					//---以u为中介点时点权之和更大---
					if (maxSumOfNodeWeight[u] + nodeWeight[v] > maxSumOfNodeWeight[v]) 
					{
						//---maxSumOfNodeWeight[v]继承自maxSumOfNodeWeight[u]---
						// u是v的前驱结点
						maxSumOfNodeWeight[v] = maxSumOfNodeWeight[u] + nodeWeight[v];
					}

					//---最短路径条数与点权无关，但是与最短距离有关，所以必须写在这里---
					numsOfShortestPath[v] += numsOfShortestPath[u]; // 两条路径距离一样的时候
																	// 需要存储路径条数多的呢个
				}
			}
		}
	}
}

int main() 
{
	scanf("%d %d %d %d", &numsOfVerts, &numsOfEdges, &stPoint, &edPoint);
	for (int i = 0; i < numsOfVerts; i++) 
	{
		//---读入点权---
		scanf("%d", &nodeWeight[i]);
	}

	int u, v;
	//---初始化图G，也就是adjacencyMatrix图
	fill(adjacencyMatrix[0], adjacencyMatrix[0] + MAXV * MAXV, INF);

	for (int j = 0; j < numsOfEdges; j++)
	{
		scanf("%d%d", &u, &v);

		//---读入边权---
		scanf("%d", &adjacencyMatrix[u][v]); // 看来邻接矩阵存储的就是边权

		adjacencyMatrix[v][u] = adjacencyMatrix[u][v];
	}

	//---Dijkstra算法入口---
	Dijkstra(stPoint);

	//---最短距离条数、最短路径中的最大点权---
	printf("%d %d\n", numsOfShortestPath[edPoint], maxSumOfNodeWeight[edPoint]);
	return 0;
}
