// A1003 Emergency

//-----����-----
// ����N�����У�M������ߡ�ÿ�������ж���һ����Ŀ�ľ�ԮС�飬���бߵı�Ȩ��֪��
// ���ڸ��������յ㣬�����㵽�յ�����·������
// �����·���ϵľ�ԮС����Ŀ֮��
// ����ж������·�����������Ŀ֮������

//-----˼·-----
// �����������̾����ͬʱ������Ҫ�������������Ϣ��
// ���·�����������·���ϵ�����Ȩ֮��
// ��w[u]��ʾ�����s���ﶥ��u���Եõ�������Ȩ֮�ͣ���ʼΪ0
// ��num[u]��ʾ�����s���ﶥ��u�����·����������ʼ��ʱֻ��num[s]Ϊ1������num[u]��Ϊ0
// �����ڸ���d[v]��ͬʱҲ��������������

//-----ע���-----
// C1��ע������ĵ�һ���������·����������������̾���
// C2��ע����Ŀ����Ķ����±귶Χ��0~n-1���ұ��������
// C3�����·�����������ݽ����ǵ�һ��ߣ����룬�͵�Ȩ�޹�

//------CODE------
#include "C.h"

//---��󶥵���---
//---�����---
const int MAXV = 510;
const int INF = 1000000000;


//---numsOfVertsΪ��������numsOfEdgesΪ����---
//---stPoint��edPoint�ֱ�Ϊ�����յ�---
//---adjacencyMatrix[][]Ϊ�ڽӾ���nodeWeightΪ��Ȩ---
//---shortestDistance[]��¼��̾��롢maxSumOfNodeWeight[]��¼����Ȩ֮��---
//---numsOfShortestPath[]��¼���·������---

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
	//---sΪ���---
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
		int u = -1;  // Ϊʲô�ܶ�����ĳ�ֵ������-1?
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

		for (int v = 0; v < numsOfVerts; v++)  // Ϊʲôv�ĳ�ֵ����Ϊ1����Ϊ���s��0��
		{
			if (vis[v] == false && adjacencyMatrix[u][v] != INF) 
			{
				if (shortestDistance[u] + adjacencyMatrix[u][v] < shortestDistance[v]) 
				{
					//---����uΪ�н��ʱ����shortDistance[v]��С��ʱ��---
					//---���Ǹ���shortDistance[v]---
					//---���Ǹ���maxSumOfNodeWeight[v]---
					shortestDistance[v] = shortestDistance[u] + adjacencyMatrix[u][v];
					maxSumOfNodeWeight[v] = maxSumOfNodeWeight[u] + nodeWeight[v];

					//---���Ǹ������·������---
					numsOfShortestPath[v] = numsOfShortestPath[u];
				}

				else if (shortestDistance[u] + adjacencyMatrix[u][v] == shortestDistance[v]) 
				{
					//---�ҵ�һ����ͬ���ȵ�·��---
					//---��uΪ�н��ʱ��Ȩ֮�͸���---
					if (maxSumOfNodeWeight[u] + nodeWeight[v] > maxSumOfNodeWeight[v]) 
					{
						//---maxSumOfNodeWeight[v]�̳���maxSumOfNodeWeight[u]---
						// u��v��ǰ�����
						maxSumOfNodeWeight[v] = maxSumOfNodeWeight[u] + nodeWeight[v];
					}

					//---���·���������Ȩ�޹أ���������̾����йأ����Ա���д������---
					numsOfShortestPath[v] += numsOfShortestPath[u]; // ����·������һ����ʱ��
																	// ��Ҫ�洢·����������ظ�
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
		//---�����Ȩ---
		scanf("%d", &nodeWeight[i]);
	}

	int u, v;
	//---��ʼ��ͼG��Ҳ����adjacencyMatrixͼ
	fill(adjacencyMatrix[0], adjacencyMatrix[0] + MAXV * MAXV, INF);

	for (int j = 0; j < numsOfEdges; j++)
	{
		scanf("%d%d", &u, &v);

		//---�����Ȩ---
		scanf("%d", &adjacencyMatrix[u][v]); // �����ڽӾ���洢�ľ��Ǳ�Ȩ

		adjacencyMatrix[v][u] = adjacencyMatrix[u][v];
	}

	//---Dijkstra�㷨���---
	Dijkstra(stPoint);

	//---��̾������������·���е�����Ȩ---
	printf("%d %d\n", numsOfShortestPath[edPoint], maxSumOfNodeWeight[edPoint]);
	return 0;
}
