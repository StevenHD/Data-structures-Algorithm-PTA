// A1087 All Roads Lead to Rome
// ֻʹ��Dijkstra

//------CODE------
#include "C.h"

//---��󶥵����������---
const int MAXV = 210;
const int INF = 1000000000;

//---numsOfVerts������, numsOfEdges������stPoint���---
//---adjacencyMatrixΪ�ڽӾ���nodeWeightΪ��Ȩ(�Ҹ�ֵ)---
int numsOfVerts;
int numsOfEdges;
int stPoint;
int adjacencyMatrix[MAXV][MAXV];
int nodeWeight[MAXV];

//---shortestDistance[]��¼��̾��롢maxNodeWeight[]��¼����Ȩ��numsOfShortestPath[]��¼���·������---
//---numsOfVertsOnShortestPath[]��pre[]��¼ǰ��---
int shortDistance[MAXV];
int maxNodeWeight[MAXV];
int numsOfShortestPath[MAXV];
int numsOfVertsOnShortestPath[MAXV];
int pre[MAXV];

//---vis[i]==true��ʾ����i�ѷ��ʣ���ֵ��Ϊfalse---
bool vis[MAXV] = { false };

//---��������ת��Ϊ���---
//---�����ת��Ϊ������---
map<string, int> cityToIndex;
map<int, string> indexToCity;

void Dijkstra(int s) {
	fill(shortDistance, shortDistance + MAXV, INF);
	memset(maxNodeWeight, 0, sizeof(maxNodeWeight));
	memset(numsOfShortestPath, 0, sizeof(numsOfShortestPath));
	memset(numsOfVertsOnShortestPath, 0, sizeof(numsOfVertsOnShortestPath));

	for (int i = 0; i < numsOfVerts; i++) 
		pre[i] = i;

	shortDistance[s] = 0;
	maxNodeWeight[s] = nodeWeight[stPoint];
	numsOfShortestPath[s] = 1;
	for (int i = 0; i < numsOfVerts; i++) 
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < numsOfVerts; j++)
		{
			if (vis[j] == false && shortDistance[j] < MIN)
			{
				u = j;
				MIN = shortDistance[j];
			}
		}

		if (u == -1) return;
		vis[u] = true;

		for (int v = 0; v < numsOfVerts; v++) 
		{
			if (vis[v] == false && adjacencyMatrix[u][v] != INF) 
			{
				if (shortDistance[u] + adjacencyMatrix[u][v] < shortDistance[v]) 
				{
					shortDistance[v] = shortDistance[u] + adjacencyMatrix[u][v];
					maxNodeWeight[v] = maxNodeWeight[u] + nodeWeight[v];
					numsOfShortestPath[v] = numsOfShortestPath[u];
					numsOfVertsOnShortestPath[v] = numsOfVertsOnShortestPath[u] + 1;
					pre[v] = u;
				}
				else if (shortDistance[u] + adjacencyMatrix[u][v] == shortDistance[v]) 
				{
					numsOfShortestPath[v] += numsOfShortestPath[u];
					if (maxNodeWeight[u] + nodeWeight[v] > maxNodeWeight[v]) 
					{
						maxNodeWeight[v] = maxNodeWeight[u] + nodeWeight[v];
						numsOfVertsOnShortestPath[v] = numsOfVertsOnShortestPath[u] + 1;
						pre[v] = u;
					}
					else if (maxNodeWeight[u] + nodeWeight[v] == maxNodeWeight[v])
					{
						double uAvg = 1.0 * (maxNodeWeight[u] + nodeWeight[v]) / (numsOfVertsOnShortestPath[u] + 1);
						double vAvg = 1.0 * maxNodeWeight[v] / numsOfVertsOnShortestPath[v];
						if (uAvg > vAvg) 
						{
							numsOfVertsOnShortestPath[v] = numsOfVertsOnShortestPath[u] + 1;
							pre[v] = u;
						}
					}
				}
			}
		}
	}
}
void printPath(int v) 
{
	if (v == 0) 
	{
		cout << indexToCity[v];
		return;
	}
	printPath(pre[v]);
	cout << "->" << indexToCity[v];
}


int main() 
{
	string start, city1, city2;
	cin >> numsOfVerts >> numsOfEdges >> start;
	cityToIndex[start] = 0;
	indexToCity[0] = start;
	for (int i = 1; i <= numsOfVerts - 1; i++) 
	{
		cin >> city1 >> nodeWeight[i];
		cityToIndex[city1] = i;
		indexToCity[i] = city1;
	}
	fill(adjacencyMatrix[0], adjacencyMatrix[0] + MAXV * MAXV, INF);

	for (int i = 0; i < numsOfEdges; i++) 
	{
		cin >> city1 >> city2;
		int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
		cin >> adjacencyMatrix[c1][c2];
		adjacencyMatrix[c2][c1] = adjacencyMatrix[c1][c2];
	}
	Dijkstra(0);

	int rom = cityToIndex["ROM"];

	printf("%d %d %d %d\n", numsOfShortestPath[rom], shortDistance[rom],
		maxNodeWeight[rom], maxNodeWeight[rom] / numsOfVertsOnShortestPath[rom]);
	printPath(rom);

	return 0;
}