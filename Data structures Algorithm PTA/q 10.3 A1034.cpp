// DFS和BFS在树的遍历中和图的遍历中都有应用
// A1034 Head Of a Gang

//-----题意-----
// 人与人之间的通话长度，可以将它视为无向边
// 将这些通话分为若干组，每个组的总边权设为该组内的所有通话的长度之和
// 每个人的点权设为该人参与的通话长度之和
// 给定一个阈值K，只要一个组的总边权超过K，成员人数超过2(>2)，则将该组视为Gang
// 而该组内点权最大的人视为头目
// 要求输出Gang的个数，并按头目姓名字典序从小到大的顺序输出每个Gang的头目姓名和成员人数

//-----思路------
// STEP1：首先要解决的问题是姓名与编号的对应关系。
//		  一是可以使用map直接建立字符串与整型的映射关系
//		  二是使用字符串hash的方法将字符串转换为整型
// STEP2：至于如果获得每个人的点权，可以在读入时就进行处理
//		  假设A与B的通话时长为T，那么A和B的点权分别增加T
// STEP3：进行图的遍历，使用DFS遍历每个连通块，目的是获取每个连通块的头目
//		  头目就是连通块内点权最大的结点，还要获得 成员个数、总边权
// STEP4：通过STEP3可以获得连通块的总边权totalValue。如果totalValue大于给定的阈值K
//		  而且成员人数大于2，则说明该连通块是一个 Gang ，将该Gang的信息存储下来
//		  可以定义 map<string, int>来建立团伙头目的姓名与成员人数的映射关系
//		  map中的元素是自动按键从小到大排序

//-----注意点-----
// C1：由于通话记录的条数最多有1000条，这意味着不同的人可能有2000人，所以数组大小必须在2000以上
// C2
// C3


//-------------------CODE-----------------------

#include "C.h"

//---总人数，要大于2000---
const int maxn = 2010;
//---定义一个无穷大---
const int INF = 1000000000; // 不过这个INF好像没有用处

//---定义map变量---
//---编号对应姓名---
map<int, string> intToString;
//---姓名对应编号---
map<string, int> stringToInt;
//---head对应人数---
map<string, int> Gang;

//---adjacencyMatrix和nodeWeight---
int adjacencyMatrix[maxn][maxn] = { 0 };
int nodeWeight[maxn] = { 0 };

//---边数numsOfEdges、阈值K、总人数totalNumsOfPeople---
//---标记是否被访问---
int numsOfEdges;
int K;
int totalNumsOfPeople = 0;
bool vis[maxn] = { false };


//----DFS函数访问单个连通块，indexOfNowVisit为当前访问的编号----
//----head为头目、indexOfMember为成员编号，totalValue为连通块的总边权----

//---DFS函数的目的就是进行图的遍历，获取每个连通块的头目 成员个数 总边权---
void DFS(int indexOfNowVisit, int& head, int& indexOfMember, int& totalValue) 
{
	//---成员人数加1---
	indexOfMember++; // 为什么成员人数要加1？
	//---标记nowVisit已访问---
	vis[indexOfNowVisit] = true;

	if (nodeWeight[indexOfNowVisit] > nodeWeight[head]) // indexOfNowVisit是当前访问节点的编号
	{
		//---当前访问结点的点权大于头目的点权，则更新头目---
		head = indexOfNowVisit;
	}

	//---对所有人进行枚举---
	for (int i = 0; i < totalNumsOfPeople; i++)
	{
		//---邻接矩阵表示的就是图的边，下面if判断表示的是如果从nowVisit的这个结点可以到达i这个人---
		if (adjacencyMatrix[indexOfNowVisit][i] > 0)
		{
			//---邻接矩阵中存储的就是 边权 ---
			//---如果nowVisit和i是连通的，则 连通块的总边权totalValue 增加 该边权 ---
			totalValue += adjacencyMatrix[indexOfNowVisit][i];

			//---删除这条边，双向的，删除就是让边权为0，就是删除---
			adjacencyMatrix[indexOfNowVisit][i] = adjacencyMatrix[i][indexOfNowVisit] = 0;
			// 这个和Dijkstra算法有区别的，区别在于 0 和 INF 的使用

			if (vis[i] == false) 
			{
				//---如果i未被访问，则递归访问i---
				DFS(i, head, indexOfMember, totalValue); // 这里明明在for循环的单次循环中，怎么递归呢？
			}
		}
	}
}


//---DFS函数可以获得连通块的总边权totalValue---
//---DFSTrave函数中可以通过totalValue和K的比对，还有成员人数的信息，来判断连通块是不是一个团伙---

//---DFSTrave函数则是遍历整个图，获取每个连通块的信息---
//---一个连通块就对应一个团伙，要将该团伙的信息存储下来---

void DFSTrave() 
{
	//---对所有人进行枚举---
	for (int i = 0; i < totalNumsOfPeople; i++) 
	{
		//---如果i这个人没有被访问---
		if (vis[i] == false) 
		{
			//---头目、成员数、总边权---
			int head = i, numMember = 0, totalValue = 0; // 为什么要让head等于i？

			//---遍历i所在的连通块---
			DFS(i, head, numMember, totalValue);

			//---成员数大于2而且总边权大于k---
			if (numMember > 2 && totalValue > K) 
			{
				//---该head对应的小弟人数---
				Gang[intToString[head]] = numMember;
			}
		}
	}
}


//----change函数返回姓名str对应的编号----
int change(string str) 
{
	//---如果str已经出现过---
	//---则返回str的编号---
	if (stringToInt.find(str) != stringToInt.end())  // 这句话能表示什么？str是否出现过？
	{
		return stringToInt[str];
	}

	//---如果str没有出现过---
	else
	{
		//---str的编号为totalNumsOfPeople---
		stringToInt[str] = totalNumsOfPeople; // totalNumsOfPeople表示总人数的

		//---totalNumsOfPeople对应str---
		intToString[totalNumsOfPeople] = str;

		//---总人数加1---
		return totalNumsOfPeople++;
	}
}

int main() 
{
	int nw;
	string str1, str2;
	cin >> numsOfEdges >> K;

	// 枚举每一条边
	for (int i = 0; i < numsOfEdges; i++)
	{
		//---输入每条边的两个端点和点权nw---
		cin >> str1 >> str2 >> nw;

		//---将str1转换为编号id1---
		//---将str2转换为编号id2---
		int id1 = change(str1);
		int id2 = change(str2);

		//---id1的点权增加nw---
		//---id2的点权增加nw---
		nodeWeight[id1] += nw;
		nodeWeight[id2] += nw;

		//---边id1->id2的边权增加nw---
		//---边id2->id1的边权增加nw---
		adjacencyMatrix[id1][id2] += nw;
		adjacencyMatrix[id2][id1] += nw;
	}

	//---DFSTrave遍历整个图的所有团伙(连通块)，还获取Gang的信息---
	DFSTrave();

	//---Gang的个数---
	cout << Gang.size() << endl;   // 输出团伙的数量

	map<string, int>::iterator it; // 遍历搞一个迭代器，不过为什么用迭代器呢？
								   // 也许因为Gang是容器map类型的吧

	//---遍历所有Gang---
	for (it = Gang.begin(); it != Gang.end(); it++)
	{
		//---输出信息---
		cout << it->first << " " << it->second << endl;
	} 
	// it->first是当前映射的键，也就是string 头目的名字
	// it->secode是当前映射的值，也就是 int 成员的数量

	return 0;
}
