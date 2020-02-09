// A1087 All Roads Lead to Rome
//------题意------
// 有N个城市，M条无向边，现在需要从某个给定的起始城市出发(除了起始城市外，其他每个城市都有一个“幸福值”)
// 前往名为"ROM"的城市。给出每条边所需要消耗的花费，求从起始城市出发，到达城市ROM所需要的最少花费
// 并输出最少花费的路径，如果这样的路径有多条，则选择路径上城市的“幸福值”之和最大的那条
// 如果路径仍然不唯一，则选择路径上城市的平均幸福值最大的那条

//------样例解释------
// 点权就是幸福值

//------思路-------
// 本题中的边权只有“花费”的概念，因此可以将它作为第一标尺
// 也就是把花费理解为距离，除了需要求解从起点到终点的最短距离外，
// 还要求输出最短路径、最短路径条数、路径上的点权之和以及路径上的平均点权
// 如果有多条最短路径，则选择点权之和最大的一条
// 若点权之和相同，则选择平均点权最大的一条
// 本题可以只使用Dilkstra算法或者是Dilkstra+DFS都是可以的

//----(1)只使用Dilkstra算法----
// 重点是如何求解平均点权，我们来看看平均点权如何记录和递推
// 平均点权等于路径上的点权之和除以路径上的顶点数目，而点权之和w[u]已经有办法记录
// 因此此处只需要额外记录从起点到顶点u的对应于点权之和w[u]的最短路径上的顶点数目
// 也就是点权之和w[u]对应的路径上的顶点数目，不妨将它设为pt[maxOfVerts]
// 这样，每当以u为中介点能使v的某个数据优化时，pt[v]均应赋值为pt[u]+1

//----(2)使用Dijkstra+DFS----
// Dijkstra的目的在于把所有最短路径找出来，因此只需要考虑第一标尺，直接套用模板就可以
// 而DFS将从所有最短路径中找出一条最优路径。
// 显然，对某一条确定的路径tempPath来说，路径上的点权之和，平均点权都是很容易计算出来的
// 而最短路径条数既可以在DFS中记录，也可以在Dijkstra中顺带求解

//----注意点-----
// C1：建议把起点设为0号顶点，而把其余顶点设为1~n-1号顶点
// C2：由于起始顶点的点权没有给出，因此计算平均点权时是不计算起始顶点的，数组pt也应当初始化
// C3：城市名称与编号的对应可以使用map直接实现，也可以使用字符串hash

//------Dijkstra+DFS对应CODE--------
#include "C.h"

//---最大顶点数---
const int maxOfVerts = 210;
//---定义一个无穷大，10亿---
const int INF = 1000000000;

//---定义顶点数、边数、起点、邻接矩阵、点权(幸福值)---
int numsOfVerts;
int numsOfEdges;
int stPoint;
int	AdjacencyMatrix[maxOfVerts][maxOfVerts];
int nodeWeight[maxOfVerts];

//---定义最短距离、最短路径条数、最大点权之和、最大平均点权---
int shortestDistance[maxOfVerts];
int numsOfShortestPath = 0;
int sumOfMaxNodeWeight = 0;
double avgOfMaxNodeWeight = 0;

//---vis[i]==true表示顶点i已访问，初始均为false---
bool vis[maxOfVerts] = { false };

//---pre表示的是前驱---
//---tempPath表示临时路径---
//---optimalPath表示最优路径---
vector<int> pre[maxOfVerts];
vector<int> tempPath;
vector<int> optimalPath;

//---将城市名转换为编号---
//---将编号转换为城市名---
map<string, int> cityToIndex;
map<int, string> indexToCity;


//---形参s表示起点---
void Dijkstra(int s) {
	fill(shortestDistance, shortestDistance + maxOfVerts, INF);
	// fill函数是按照单元赋值，将一个区间的元素都赋同一个值
	// 例如int数组：fill(arr, arr + n, 要填入的内容)
	// 上句code则是将INF填入到shortestDistance数组中

	for (int i = 0; i < numsOfVerts; i++) 
	{
		pre[i].push_back(i); // 往前驱数组中不断地添加顶点verts
	} 

	shortestDistance[s] = 0; // 起点的最短距离为0，很好理解

	//---循环n次---
	//---u使shortestDistance[u]最小---
	//---MIN存放该最小的shortDistance[u]---
	for (int j = 0; j < numsOfVerts; j++) 
	{
		int u = -1;
		int MIN = INF;

		//---找到未访问的顶点中shortDistance[]最小的---
		for (int k = 0; k < numsOfVerts; k++) {
			if (vis[k] == false && shortestDistance[k] < MIN) {
				u = k;
				MIN = shortestDistance[k];
			}
		}

		//---找不到小于INF的shortDistance[u]，说明剩下的顶点和起点s不连通---
		if (u == -1) 
			return;

		//---标记u为已访问---
		vis[u] = true; // u的具体含义是什么？
		for (int v = 0; v < numsOfVerts; v++) 
		{
			//---如果v未访问 && u能到达v---
			if (vis[v] == false && AdjacencyMatrix[u][v] != INF) 
			{
				//---以u为中介点，使shortDistance[v]更小---
				if (shortestDistance[u] + AdjacencyMatrix[u][v] < shortestDistance[v]) 
				{
					//---优化shortDistance[v]---
					shortestDistance[v] = shortestDistance[u] + AdjacencyMatrix[u][v];

					//---清空pre[v]---
					//---u为v的前驱---
					pre[v].clear();
					pre[v].push_back(u);
				}
				//---找到相同长度的路径---
				else if (shortestDistance[u] + AdjacencyMatrix[u][v] == shortestDistance[v]) 
				{
					// 邻接矩阵AM和最短距离矩阵之间是什么关系呢？
					//---u为v的前驱之一---
					pre[v].push_back(u);
				}
			}
		}
	}
}

//---形参v为当前结点---
void DFS(int v) 
{
	//---递归边界，到达叶子结点（路径起点）---
	if (v == stPoint) 
	{
		tempPath.push_back(v);
		//---最短路径条数加1---
		//---临时路径tempPath的点权之和---
		numsOfShortestPath++;
		int tempSNW = 0;

		//---倒着访问---
		for (int i = tempPath.size() - 2; i >= 0; i--) 
		{
			//---当前结点---
			//---增加结点id的点权(注意不是i)---
			int id = tempPath[i];
			tempSNW += nodeWeight[id];
		}

		//---tempNW表示临时平均点权---
		double tempAvgNW = 1.0 * tempSNW / (tempPath.size() - 1);

		//---如果当前路径的点权之和更大---
		//---优化最大点权和---
		//---覆盖最大平均点权---
		//---覆盖最优路径---
		if (tempSNW > sumOfMaxNodeWeight) {
			sumOfMaxNodeWeight = tempSNW;
			avgOfMaxNodeWeight = tempAvgNW;
			optimalPath = tempPath;
		}
		else if (tempSNW == sumOfMaxNodeWeight && tempAvgNW > avgOfMaxNodeWeight) 
		{
			//---点权之和相同，当前路径的平均点权最大---
			//---优化最大平均点权---
			//---覆盖最优路径---
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
	cin >> numsOfVerts >> numsOfEdges >> start; // 手动输入顶点数和边数

	cityToIndex[start] = 0; // 这个其实定义的是两个map变量
	indexToCity[0] = start; // 编号0对应的就是起点start

	for (int i = 1; i <= numsOfVerts - 1; i++) 
	{
		cin >> city1 >> nodeWeight[i]; // 点权也是我们手动输入的
		cityToIndex[city1] = i;		   // 之所以定义一个city1，一个city2，是因为一共就3个点
		indexToCity[i] = city1;		   // start, city1, city2这三个点
									   // 这一行就是在不断地用城市匹配编号
	}

	//---初始化图G---
	fill(AdjacencyMatrix[0], AdjacencyMatrix[0] + maxOfVerts * maxOfVerts, INF);
	// 为啥是增加的 跨度 最大顶点数的平方呢？因为图G是一个正方形吗？

	for (int j = 0; j < numsOfEdges; j++) 
	{
		cin >> city1 >> city2;
		int c1 = cityToIndex[city1];
		int c2 = cityToIndex[city2];
		cin >> AdjacencyMatrix[c1][c2];
		AdjacencyMatrix[c2][c1] = AdjacencyMatrix[c1][c2];
	}
	//---Dijkstra算法入口---
	Dijkstra(0); // 0表示起点

	int rom = cityToIndex["ROM"];
	//---获取最优路径---
	DFS(rom);	 // rom则表示当前的结点

	printf("%d %d %d %d\n", numsOfShortestPath, 
		shortestDistance[rom], sumOfMaxNodeWeight, (int)avgOfMaxNodeWeight);
	// print出最短路径的数量、最短路径的大小、最大点权之和、最大平均点权

	//---倒着输出路径上的结点---
	for (int k = optimalPath.size() - 1; k >= 0; k--) 
	{
		cout << indexToCity[optimalPath[k]];
		if (k > 0) 
			cout << "->";
	}
	return 0;
}
