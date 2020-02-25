// A1021. Deepest Root

//------CODE------

#include "C.h"

const int N = 100010;

//---邻接表---
vector<int> G[N];

//---记录每个结点是否作为某个集合的根结点---
bool isRoot[N];

int father[N];           // ?

//---findFather()函数在Union()函数中有出现---
//---findFather()的作用是查找x所在集合的根结点---
int findFather(int x) 
{
	int a = x;
	while (x != father[x]) 
	{
		x = father[x];
	}

	//--路径压缩(可不写)--
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}


//---合并a和b所在的集合---
void Union(int a, int b) 
{
	int faA = findFather(a);
	int faB = findFather(b);

	if (faA != faB) 
	{
		father[faA] = faB;
	}
}

//---并查集函数初始化---
void init(int n) 
{
	for (int i = 1; i <= n; i++) 
	{
		father[i] = i;     // father[1]=1, father[2]=2,..., father[n]=n
						   // father[]表示的是根结点吗？
	}
}


//--计算集合数目--
//--计算连通块的个数--
int calBlock(int n) 
{
	int Block = 0;

	for (int i = 1; i <= n; i++) 
	{
		//--i的根结点是findFather(i)--
		isRoot[findFather(i)] = true;
	}

	for (int i = 1; i <= n; i++) 
	{
		//--累加根结点的个数--
		Block += isRoot[i];
	}

	return Block;
}


//--定义maxH为最大高度--
int maxH = 0;

//--temp临时存放DFS的最远结点结果--
//--Ans则保存答案--
vector<int> temp, Ans;


//---u表示当前访问顶点编号，height是当前树的高度，pre表示前驱结点，也就是u的父结点---
//---Ans[0]传给形参u, 则表示“从任意一个根结点开始遍历”---
void DFS(int u, int Height, int pre) 
{
	//---如果获得了更大的树高---
	if (Height > maxH) 
	{
		//---清空temp---
		temp.clear();

		//---将当前结点u加入到temp中---
		temp.push_back(u);

		//---将最大树高赋给maxH---
		maxH = Height;
	}

	//--如果树高等于最大树高--
	else if (Height == maxH) 
	{
		//--将当前结点加入temp中--
		temp.push_back(u);
	}

	//--遍历u的所有子结点--
	for (int i = 0; i < G[u].size(); i++) 
	{
		//--由于邻接表中存放的是无向图，因此需要跳过回去的那条边--
		if (G[u][i] == pre) 
			continue;

		//--递归地访问子结点--
		DFS(G[u][i], Height + 1, u);
	}
}


int main() 
{
	//--输入n表示结点数--
	int a, b, n;
	scanf("%d", &n);

	//--并查集初始化--
	init(n);

	for (int i = 1; i < n; i++) 
	{
		//--输入顶点a和b--
		scanf("%d%d", &a, &b);

		G[a].push_back(b);       // 边a->b
		G[b].push_back(a);		 // 边b->a

		//--合并a和b的集合--
		Union(a, b);
	}

	//--计算集合数目--
	int Block = calBlock(n);

	//--如果不止一个连通块--
	if (Block != 1) 
	{
		printf("Error: %d components\n", Block);
	}

	else 
	{
		//--从1号结点开始DFS，初始高度为1--
		DFS(1, 1, -1);

		//--temp为集合A，赋值给Ans--
		Ans = temp;

		//--从任意一个根结点开始遍历--
		DFS(Ans[0], 1, -1);

		for (int i = 0; i < temp.size(); i++) 
		{
			//--此时temp为集合B，将其加到Ans中--
			Ans.push_back(temp[i]);
		}

		//--按编号从小到大排序--
		sort(Ans.begin(), Ans.end());

		printf("%d\n", Ans[0]);

		for (int i = 1; i < Ans.size(); i++) 
		{
			//--重复编号不输出--
			if (Ans[i] != Ans[i - 1]) 
			{
				printf("%d\n", Ans[i]);
			}
		}
	}

	return 0;
}
