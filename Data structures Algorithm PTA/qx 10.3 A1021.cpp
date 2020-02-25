// A1021. Deepest Root

//------CODE------

#include "C.h"

const int N = 100010;

//---�ڽӱ�---
vector<int> G[N];

//---��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����---
bool isRoot[N];

int father[N];           // ?

//---findFather()������Union()�������г���---
//---findFather()�������ǲ���x���ڼ��ϵĸ����---
int findFather(int x) 
{
	int a = x;
	while (x != father[x]) 
	{
		x = father[x];
	}

	//--·��ѹ��(�ɲ�д)--
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}


//---�ϲ�a��b���ڵļ���---
void Union(int a, int b) 
{
	int faA = findFather(a);
	int faB = findFather(b);

	if (faA != faB) 
	{
		father[faA] = faB;
	}
}

//---���鼯������ʼ��---
void init(int n) 
{
	for (int i = 1; i <= n; i++) 
	{
		father[i] = i;     // father[1]=1, father[2]=2,..., father[n]=n
						   // father[]��ʾ���Ǹ������
	}
}


//--���㼯����Ŀ--
//--������ͨ��ĸ���--
int calBlock(int n) 
{
	int Block = 0;

	for (int i = 1; i <= n; i++) 
	{
		//--i�ĸ������findFather(i)--
		isRoot[findFather(i)] = true;
	}

	for (int i = 1; i <= n; i++) 
	{
		//--�ۼӸ����ĸ���--
		Block += isRoot[i];
	}

	return Block;
}


//--����maxHΪ���߶�--
int maxH = 0;

//--temp��ʱ���DFS����Զ�����--
//--Ans�򱣴��--
vector<int> temp, Ans;


//---u��ʾ��ǰ���ʶ����ţ�height�ǵ�ǰ���ĸ߶ȣ�pre��ʾǰ����㣬Ҳ����u�ĸ����---
//---Ans[0]�����β�u, ���ʾ��������һ������㿪ʼ������---
void DFS(int u, int Height, int pre) 
{
	//---�������˸��������---
	if (Height > maxH) 
	{
		//---���temp---
		temp.clear();

		//---����ǰ���u���뵽temp��---
		temp.push_back(u);

		//---��������߸���maxH---
		maxH = Height;
	}

	//--������ߵ����������--
	else if (Height == maxH) 
	{
		//--����ǰ������temp��--
		temp.push_back(u);
	}

	//--����u�������ӽ��--
	for (int i = 0; i < G[u].size(); i++) 
	{
		//--�����ڽӱ��д�ŵ�������ͼ�������Ҫ������ȥ��������--
		if (G[u][i] == pre) 
			continue;

		//--�ݹ�ط����ӽ��--
		DFS(G[u][i], Height + 1, u);
	}
}


int main() 
{
	//--����n��ʾ�����--
	int a, b, n;
	scanf("%d", &n);

	//--���鼯��ʼ��--
	init(n);

	for (int i = 1; i < n; i++) 
	{
		//--���붥��a��b--
		scanf("%d%d", &a, &b);

		G[a].push_back(b);       // ��a->b
		G[b].push_back(a);		 // ��b->a

		//--�ϲ�a��b�ļ���--
		Union(a, b);
	}

	//--���㼯����Ŀ--
	int Block = calBlock(n);

	//--�����ֹһ����ͨ��--
	if (Block != 1) 
	{
		printf("Error: %d components\n", Block);
	}

	else 
	{
		//--��1�Ž�㿪ʼDFS����ʼ�߶�Ϊ1--
		DFS(1, 1, -1);

		//--tempΪ����A����ֵ��Ans--
		Ans = temp;

		//--������һ������㿪ʼ����--
		DFS(Ans[0], 1, -1);

		for (int i = 0; i < temp.size(); i++) 
		{
			//--��ʱtempΪ����B������ӵ�Ans��--
			Ans.push_back(temp[i]);
		}

		//--����Ŵ�С��������--
		sort(Ans.begin(), Ans.end());

		printf("%d\n", Ans[0]);

		for (int i = 1; i < Ans.size(); i++) 
		{
			//--�ظ���Ų����--
			if (Ans[i] != Ans[i - 1]) 
			{
				printf("%d\n", Ans[i]);
			}
		}
	}

	return 0;
}
