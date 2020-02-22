// A1099. Build a Binary Search Tree

//---BST concept----
// һ���ڵ��������ֻ������ֵС�ڸýڵ��ֵ�Ľڵ�
// һ���ڵ����������������ֵ���ڻ���ڸýڵ��ֵ�Ľڵ�
// ��������Ҳ������BST

//---���---
// �����Ŀ�����ǽ���ţ���ôʹ�ö������ľ�̬д����ȽϷ���

//------CODE------

#include "C.h"

const int maxn = 110;

//--�������ľ�̬д��--
struct node {    
	int data;
	int lchild, rchild;  // ԭ����Ҫ�����ָ���lchild��rchild���������int�ͱ���
} Node[maxn];


//--nΪ������--
int n;

//--inΪ�������У�numΪ�Ѿ����� / ����Ľ�����--
int in[maxn], num = 0;                          // num�ĸ��̫����


//---���������������õ���������������������---
void inOrder(int root) 
{
	if (root == -1) 
	{
		return;
	}

	//--�����������ţ�����0 1 6 2 3 7����--
	inOrder(Node[root].lchild);  // һ��ʼ������lchildID�൱�ڸ����˶�����

	//---���������е�����---
	//--�������������������Ȩֵ--
	Node[root].data = in[num++];    

	inOrder(Node[root].rchild);  // �����������㣬��Ҫ���ϵݹ�
}


//---�����ö���������Ĳ����������---
//---�������---
void BFS(int root) 
{
	queue<int> q;				// ע��������Ǵ��ַ
	q.push(root);				// ��������ַ���

	num = 0;
	while (!q.empty()) 
	{
		int now = q.front();    // ȡ������Ԫ�أ���now���洢
		q.pop();

		printf("%d", Node[now].data);  // ���ʶ���Ԫ��
		num++;

		if (num < n) 
			printf(" ");

		//--�������ǿ�--
		if (Node[now].lchild != -1) 
			q.push(Node[now].lchild);  

		//--�������ǿ�--
		if (Node[now].rchild != -1) 
			q.push(Node[now].rchild);  
	}
}

int main() 
{
	int lchildID, rchildID;
	scanf("%d", &n);    // nΪ������

	for (int i = 0; i < n; i++) 
	{
		//---�������Һ��ӱ��---
		scanf("%d%d", &lchildID, &rchildID);    

		Node[i].lchild = lchildID;  // ����Ÿ�ֵΪ�ṹ��Node��lchild��rchild
		Node[i].rchild = rchildID;  // lchild��rchild����ľ������Һ���
	}

	for (int i = 0; i < n; i++) 
	{
		//---��������ǰ������---
		scanf("%d", &in[i]);        // �������N�����������У���Ҫ�������N����������������Ľ����
	}

	//--��С����������Ϊ��������--
	sort(in, in + n);				// ��һ��BST���ԣ���������ǵ����ģ����Դ�С��������

	//---��0�Ž��Ϊ�������������������������---
	//--�Ը����Ķ����������������--
	inOrder(0);

	//--inOrder�����󣬶������Ľ���źͶ�ӦȨֵ���Ѿ������--
	//---��������������---
	BFS(0);

	return 0;
}
