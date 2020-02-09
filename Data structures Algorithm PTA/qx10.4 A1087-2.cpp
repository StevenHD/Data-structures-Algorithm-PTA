// A1087 All Roads Lead to Rome
//------����------
// ��N�����У�M������ߣ�������Ҫ��ĳ����������ʼ���г���(������ʼ�����⣬����ÿ�����ж���һ�����Ҹ�ֵ��)
// ǰ����Ϊ"ROM"�ĳ��С�����ÿ��������Ҫ���ĵĻ��ѣ������ʼ���г������������ROM����Ҫ�����ٻ���
// ��������ٻ��ѵ�·�������������·���ж�������ѡ��·���ϳ��еġ��Ҹ�ֵ��֮����������
// ���·����Ȼ��Ψһ����ѡ��·���ϳ��е�ƽ���Ҹ�ֵ��������

//------��������------
// ��Ȩ�����Ҹ�ֵ

//------˼·-------
// �����еı�Ȩֻ�С����ѡ��ĸ����˿��Խ�����Ϊ��һ���
// Ҳ���ǰѻ������Ϊ���룬������Ҫ������㵽�յ����̾����⣬
// ��Ҫ��������·�������·��������·���ϵĵ�Ȩ֮���Լ�·���ϵ�ƽ����Ȩ
// ����ж������·������ѡ���Ȩ֮������һ��
// ����Ȩ֮����ͬ����ѡ��ƽ����Ȩ����һ��
// �������ֻʹ��Dilkstra�㷨������Dilkstra+DFS���ǿ��Ե�

//----(1)ֻʹ��Dilkstra�㷨----
// �ص���������ƽ����Ȩ������������ƽ����Ȩ��μ�¼�͵���
// ƽ����Ȩ����·���ϵĵ�Ȩ֮�ͳ���·���ϵĶ�����Ŀ������Ȩ֮��w[u]�Ѿ��а취��¼
// ��˴˴�ֻ��Ҫ�����¼����㵽����u�Ķ�Ӧ�ڵ�Ȩ֮��w[u]�����·���ϵĶ�����Ŀ
// Ҳ���ǵ�Ȩ֮��w[u]��Ӧ��·���ϵĶ�����Ŀ������������Ϊpt[maxOfVerts]
// ������ÿ����uΪ�н����ʹv��ĳ�������Ż�ʱ��pt[v]��Ӧ��ֵΪpt[u]+1

//----(2)ʹ��Dijkstra+DFS----
// Dijkstra��Ŀ�����ڰ��������·���ҳ��������ֻ��Ҫ���ǵ�һ��ߣ�ֱ������ģ��Ϳ���
// ��DFS�����������·�����ҳ�һ������·����
// ��Ȼ����ĳһ��ȷ����·��tempPath��˵��·���ϵĵ�Ȩ֮�ͣ�ƽ����Ȩ���Ǻ����׼��������
// �����·�������ȿ�����DFS�м�¼��Ҳ������Dijkstra��˳�����

//----ע���-----
// C1������������Ϊ0�Ŷ��㣬�������ඥ����Ϊ1~n-1�Ŷ���
// C2��������ʼ����ĵ�Ȩû�и�������˼���ƽ����Ȩʱ�ǲ�������ʼ����ģ�����ptҲӦ����ʼ��
// C3�������������ŵĶ�Ӧ����ʹ��mapֱ��ʵ�֣�Ҳ����ʹ���ַ���hash

//------Dijkstra+DFS��ӦCODE--------
#include "C.h"

//---��󶥵���---
const int maxOfVerts = 210;
//---����һ�������10��---
const int INF = 1000000000;

//---���嶥��������������㡢�ڽӾ��󡢵�Ȩ(�Ҹ�ֵ)---
int numsOfVerts;
int numsOfEdges;
int stPoint;
int	AdjacencyMatrix[maxOfVerts][maxOfVerts];
int nodeWeight[maxOfVerts];

//---������̾��롢���·������������Ȩ֮�͡����ƽ����Ȩ---
int shortestDistance[maxOfVerts];
int numsOfShortestPath = 0;
int sumOfMaxNodeWeight = 0;
double avgOfMaxNodeWeight = 0;

//---vis[i]==true��ʾ����i�ѷ��ʣ���ʼ��Ϊfalse---
bool vis[maxOfVerts] = { false };

//---pre��ʾ����ǰ��---
//---tempPath��ʾ��ʱ·��---
//---optimalPath��ʾ����·��---
vector<int> pre[maxOfVerts];
vector<int> tempPath;
vector<int> optimalPath;

//---��������ת��Ϊ���---
//---�����ת��Ϊ������---
map<string, int> cityToIndex;
map<int, string> indexToCity;


//---�β�s��ʾ���---
void Dijkstra(int s) {
	fill(shortestDistance, shortestDistance + maxOfVerts, INF);
	// fill�����ǰ��յ�Ԫ��ֵ����һ�������Ԫ�ض���ͬһ��ֵ
	// ����int���飺fill(arr, arr + n, Ҫ���������)
	// �Ͼ�code���ǽ�INF���뵽shortestDistance������

	for (int i = 0; i < numsOfVerts; i++) 
	{
		pre[i].push_back(i); // ��ǰ�������в��ϵ���Ӷ���verts
	} 

	shortestDistance[s] = 0; // ������̾���Ϊ0���ܺ����

	//---ѭ��n��---
	//---uʹshortestDistance[u]��С---
	//---MIN��Ÿ���С��shortDistance[u]---
	for (int j = 0; j < numsOfVerts; j++) 
	{
		int u = -1;
		int MIN = INF;

		//---�ҵ�δ���ʵĶ�����shortDistance[]��С��---
		for (int k = 0; k < numsOfVerts; k++) {
			if (vis[k] == false && shortestDistance[k] < MIN) {
				u = k;
				MIN = shortestDistance[k];
			}
		}

		//---�Ҳ���С��INF��shortDistance[u]��˵��ʣ�µĶ�������s����ͨ---
		if (u == -1) 
			return;

		//---���uΪ�ѷ���---
		vis[u] = true; // u�ľ��庬����ʲô��
		for (int v = 0; v < numsOfVerts; v++) 
		{
			//---���vδ���� && u�ܵ���v---
			if (vis[v] == false && AdjacencyMatrix[u][v] != INF) 
			{
				//---��uΪ�н�㣬ʹshortDistance[v]��С---
				if (shortestDistance[u] + AdjacencyMatrix[u][v] < shortestDistance[v]) 
				{
					//---�Ż�shortDistance[v]---
					shortestDistance[v] = shortestDistance[u] + AdjacencyMatrix[u][v];

					//---���pre[v]---
					//---uΪv��ǰ��---
					pre[v].clear();
					pre[v].push_back(u);
				}
				//---�ҵ���ͬ���ȵ�·��---
				else if (shortestDistance[u] + AdjacencyMatrix[u][v] == shortestDistance[v]) 
				{
					// �ڽӾ���AM����̾������֮����ʲô��ϵ�أ�
					//---uΪv��ǰ��֮һ---
					pre[v].push_back(u);
				}
			}
		}
	}
}

//---�β�vΪ��ǰ���---
void DFS(int v) 
{
	//---�ݹ�߽磬����Ҷ�ӽ�㣨·����㣩---
	if (v == stPoint) 
	{
		tempPath.push_back(v);
		//---���·��������1---
		//---��ʱ·��tempPath�ĵ�Ȩ֮��---
		numsOfShortestPath++;
		int tempSNW = 0;

		//---���ŷ���---
		for (int i = tempPath.size() - 2; i >= 0; i--) 
		{
			//---��ǰ���---
			//---���ӽ��id�ĵ�Ȩ(ע�ⲻ��i)---
			int id = tempPath[i];
			tempSNW += nodeWeight[id];
		}

		//---tempNW��ʾ��ʱƽ����Ȩ---
		double tempAvgNW = 1.0 * tempSNW / (tempPath.size() - 1);

		//---�����ǰ·���ĵ�Ȩ֮�͸���---
		//---�Ż�����Ȩ��---
		//---�������ƽ����Ȩ---
		//---��������·��---
		if (tempSNW > sumOfMaxNodeWeight) {
			sumOfMaxNodeWeight = tempSNW;
			avgOfMaxNodeWeight = tempAvgNW;
			optimalPath = tempPath;
		}
		else if (tempSNW == sumOfMaxNodeWeight && tempAvgNW > avgOfMaxNodeWeight) 
		{
			//---��Ȩ֮����ͬ����ǰ·����ƽ����Ȩ���---
			//---�Ż����ƽ����Ȩ---
			//---��������·��---
			avgOfMaxNodeWeight = tempAvgNW;
			optimalPath = tempPath;
		}
		tempPath.pop_back();
		return;
	}

	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) 
	{
		DFS(pre[v][i]);
	}

	tempPath.pop_back();
}

int main() 
{
	string start;
	string city1;
	string city2;
	cin >> numsOfVerts >> numsOfEdges >> start; // �ֶ����붥�����ͱ���

	cityToIndex[start] = 0; // �����ʵ�����������map����
	indexToCity[0] = start; // ���0��Ӧ�ľ������start

	for (int i = 1; i <= numsOfVerts - 1; i++) 
	{
		cin >> city1 >> nodeWeight[i]; // ��ȨҲ�������ֶ������
		cityToIndex[city1] = i;		   // ֮���Զ���һ��city1��һ��city2������Ϊһ����3����
		indexToCity[i] = city1;		   // start, city1, city2��������
									   // ��һ�о����ڲ��ϵ��ó���ƥ����
	}

	//---��ʼ��ͼG---
	fill(AdjacencyMatrix[0], AdjacencyMatrix[0] + maxOfVerts * maxOfVerts, INF);
	// Ϊɶ�����ӵ� ��� ��󶥵�����ƽ���أ���ΪͼG��һ����������

	for (int j = 0; j < numsOfEdges; j++) 
	{
		cin >> city1 >> city2;
		int c1 = cityToIndex[city1];
		int c2 = cityToIndex[city2];
		cin >> AdjacencyMatrix[c1][c2];
		AdjacencyMatrix[c2][c1] = AdjacencyMatrix[c1][c2];
	}
	//---Dijkstra�㷨���---
	Dijkstra(0); // 0��ʾ���

	int rom = cityToIndex["ROM"];
	//---��ȡ����·��---
	DFS(rom);	 // rom���ʾ��ǰ�Ľ��

	printf("%d %d %d %d\n", numsOfShortestPath, 
		shortestDistance[rom], sumOfMaxNodeWeight, (int)avgOfMaxNodeWeight);
	// print�����·�������������·���Ĵ�С������Ȩ֮�͡����ƽ����Ȩ

	//---�������·���ϵĽ��---
	for (int k = optimalPath.size() - 1; k >= 0; k--) 
	{
		cout << indexToCity[optimalPath[k]];
		if (k > 0) 
			cout << "->";
	}
	return 0;
}
