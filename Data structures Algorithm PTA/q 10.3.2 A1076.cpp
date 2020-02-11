// A1076 Forwards on Weibo

//-----思路-----
// 首先考虑如何建图。因为题目给的是用户关注的情况，而不是用户被关注的情况
// 所以如果用户X关注了用户Y，则需要建立由Y指向X的有向边
// Y指向X则说明Y发布的信息X可以收到，并且可以被X转发

// 在建图完毕后，使用DFS或BFS都可以得到需要的结果
// 如果使用DFS来遍历，只要控制遍历深度不超过题目给定的层数L即可
// DFS遍历过程中 计数 访问到的结点个数
// 如果使用BFS遍历，需要把结点编号和层号建立成结构体
// 然后控制遍历层数不超过L

//------------CODE------------------

#include "C.h"

const int MAXV = 1010;

//-----结构体Node的定义----
struct Node 
{
	//---结构体中的结点的编号---
	//---结构体中的结点的层号---
	int id;
	int layer;
};


//---邻接表---
vector<Node> adjList[MAXV];

//---顶点是否已被加入过队列---
bool inQueue[MAXV] = { false };


//---stPoint为起始结点，L为层数上限---
int BFS(int stPoint, int L)
{
	//---numForward转发数初值为0---
	//---BFS队列---
	int numForward = 0;
	queue<Node> queOfBFS;

	//---定义起始结点---
	//---起始结点编号---
	//---起始结点层号为0---
	Node start;
	start.id = stPoint;
	start.layer = 0;

	//---将起始结点start 压入 队列queOfBFS---
	queOfBFS.push(start);

	//---起始结点的编号设为 已被加入过队列---
	inQueue[start.id] = true;


	while (!queOfBFS.empty()) 
	{
		//---取出队首结点---
		Node topNode = queOfBFS.front();

		//---取出后，让队首结点出队---
		queOfBFS.pop();

		//---队首结点的编号id赋值给变量u---
		int u = topNode.id;


		for (int i = 0; i < adjList[u].size(); i++) 
		{
			//---从队首结点u出发能到达的结点uNext---
			Node uNext = adjList[u][i]; //邻接表adjList存储的是什么值啊？

			//---uNext的层号等于当前结点层号+1---
			uNext.layer = topNode.layer + 1;

			//---如果uNext的编号未被加入过队列，而且uNext的层次不超过上限L---
			if (inQueue[uNext.id] == false && uNext.layer <= L)
			{
				//---将uNext加入队列---
				queOfBFS.push(uNext);    // 这个BFS队列又是干嘛的呢？什么作用啊？

				//---这个时候可以将uNext的编号设为，已被加入过队列---
				inQueue[uNext.id] = true;

				//---转发数+1---
				numForward++;
			}
		}
	}

	//---返回转发数---
	return numForward;
}

int main() 
{
	Node user;

	//---numsOfNode结点个数---
	//---maxOfLayer层数上限---
	int numsOfNode, maxOfLayer, numFollow, idFollow;
	scanf("%d%d", &numsOfNode, &maxOfLayer);

	for (int i = 1; i <= numsOfNode; i++)
	{
		//---用户编号为i---
		user.id = i;

		//---i号用户关注的人数---
		scanf("%d", &numFollow);

		for (int j = 0; j < numFollow; j++) 
		{
			//---i号用户关注的用户编号---
			scanf("%d", &idFollow);

			adjList[idFollow].push_back(user);
		}
	}

	//---查询个数---
	int numQuery, s;
	scanf("%d", &numQuery);

	for (int i = 0; i < numQuery; i++) 
	{
		//---inQueue数组初始化---
		memset(inQueue, false, sizeof(inQueue));

		//---起始结点的编号---
		scanf("%d", &s);
		int numForward = BFS(s, maxOfLayer);
		printf("%d\n", numForward);
	}
	return 0;
}
