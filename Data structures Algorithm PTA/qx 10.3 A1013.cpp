// A1012. Battle over cities

//---------CODE---------

#include "C.h"

const int N = 1111;

//--G[N]是邻接表--
vector<int> G[N];

//--标记顶点i是否已被访问--
bool vis[N];

//--当前需要删除的顶点编号--
int currentPoint;

//--dfs(v)遍历顶点v所在的连通块--
void dfs(int v) 
{
	//--当遍历到已删除顶点v时，返回--
	//--其实这样就起到了一个“删除结点”的作用，而不必真的删除数据结构中的结点--
	if (v == currentPoint) 
		return;
	
	//--标记顶点v已被访问--
	vis[v] = true;              // 顶点v被访问的标志就是作为形参进入dfs()函数

	//---遍历顶点v的所有邻接点(顶点v所有出边的终点)---
	//---这里是体现删除顶点V2后，剩下两个顶点V3、V1后，看它们是否连通，来看是否需要添加额外的边---
	for (int e = 0; e < G[v].size(); e++)  // 这里我改成了e，表示终点，顶点v有size()条边
										   // 那么顶点v就会有size()个终点(e)，用下标e来遍历
										   // 这里定义的G[]的size是1111
	{
		//---如果顶点G[v][i]未被访问---
		if (vis[G[v][e]] == false)         // 如果顶点v的一条边的终点e号顶点还没有被访问
										   // 那么就递归地用dfs()函数访问G[v][e]这个顶点
		{
			//---访问顶点G[v][i]---
			dfs(G[v][e]);
		}
	}
}

int n, m, k;

int main() 
{
	//---分别输入顶点数、边数、查询数---
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) 
	{
		int a, b;

		//---m条边，每条边的两个顶点a, b---
		scanf("%d%d", &a, &b);

		//---以下分别是a->b和b->a---
		G[a].push_back(b);
		G[b].push_back(a);
	}

	//---k次查询---
	for (int query = 0; query < k; query++) 
	{
		//---输入欲删除的顶点编号---
		scanf("%d", &currentPoint);

		//---初始化vis数组为false---
		memset(vis, false, sizeof(vis));     // vis[]初值均为false表示所有顶点都还没被访问

		//---定义一个变量来表示连通块的个数，初值为0---
		int block = 0;                       // 假设初始没有连通块

		//---枚举每一个顶点---
		//---n表示顶点数---
		for (int i = 1; i <= n; i++) 
		{
			//---如果当前没有被删除，也没有被访问过---
			if (i != currentPoint && vis[i] == false) 
			{
				//---遍历顶点i所在的连通块---
				dfs(i);

				//---连通块个数加1---
				block++;
			}
		}

		//---输出的连通块个数减1，表示需要增加的边---
		printf("%d\n", block - 1);
	}
	return 0;
}
