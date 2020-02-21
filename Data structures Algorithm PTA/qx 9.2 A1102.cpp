// A1102. Invert a Binary Tree

//---CODE----

#include "C.h"

const int maxn = 110;

//---�������ľ�̬д��---
struct node 
{    
	int lchild;  // ��̬д�����ǲ���ָ��
	int rchild;
} Node[maxn];

//--��¼�Ƿ��Ǹ���㣬��ʼ���Ǹ����--
bool notRoot[maxn] = { false };    

//---nΪ��������numΪ��ǰ�Ѿ�����Ľ�����---
int n, num = 0;    

//--print����������id�ı��--
void print(int id) 
{
	//--���id--
	printf("%d", id);    

	//--�Ѿ�����Ľ�������1--
	num++;    

	//---���һ����㲻����ո�---
	if (num < n) 
		printf(" ");    
	else 
		printf("\n");
}

//--�������--
//--�������Ҳ�õ��˵ݹ�--
void inOrder(int root) 
{
	//---root��ʾ-1������---
	if (root == -1) 
	{
		return;
	}

	inOrder(Node[root].lchild);

	//---��root��lchild�����ڵ�ʱ��return��������ӡ��ǰ���root---
	print(root);

	//---��Ϊ�Ѿ���ӡ��root�ˣ������ж�rchild�ǲ���Ҫ�����´�ӡroot��---
	//--��ô��print�����ټ�һ��inOrder(rchild)�Ĵ�����Ϊ�˿������rchild����ľ�����Һ���--
	inOrder(Node[root].rchild);
}


//--�������--
void BFS(int root) 
{
	//--ע��������Ǵ��ַ--
	//--�½�һ������q--
	queue<int> q;  

	//--��������ַ���q--
	q.push(root);  

	while (!q.empty()) 
	{
		//---ȡ������Ԫ��---
		int now = q.front();  
		q.pop();

		print(now);

		//--�������ǿ�--
		if (Node[now].lchild != -1) 
			q.push(Node[now].lchild); 

		//--�������ǿ�--
		if (Node[now].rchild != -1) 
			q.push(Node[now].rchild);  
	}
}


//--������������Է�ת������--
void postOrder(int root) 
{
	if (root == -1) 
	{
		return;
	}

	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);

	swap(Node[root].lchild, Node[root].rchild);    // �������Һ���
}


//--��������ַ�ת��Ϊ-1���߽����--
int strToNum(char c) 
{
	if (c == '-') 
		//--��-����ʾû�к��ӽ�㣬��Ϊ-1--
		return -1;    
	else 
	{
		//--���c���Ǹ����--
		notRoot[c - '0'] = true;    

		// ���ؽ����
		return c - '0';    
	}
}


//--Ѱ�Ҹ������--
int findRoot() 
{
	for (int i = 0; i < n; i++) 
	{
		if (notRoot[i] == false)  // notRoot[i] = false ��ζ�Ž��i�Ǹ����
		{
			//---�Ǹ���㣬����i---
			return i;    
		}
	}
}


int main() 
{
	char lchild, rchild;
	scanf("%d", &n);    // nΪ������

	for (int i = 0; i < n; i++) 
	{
		//--���Һ���--
		scanf("%*c%c %c", &lchild, &rchild);  // ע��С����scanf("%*c")��Ҳ������%*c�Ϳ�����scanf��
											  // ����һ���ַ�  
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}

	//--��ø������--
	int root = findRoot();    

	//--�����������ת������--
	postOrder(root);   

	//--��������������--
	BFS(root);    

	//--������Ľ�������0--
	num = 0;     // ΪʲôҪ��0�������inOrder()��Ҳû���õ�num��

	//--��������������--
	inOrder(root);    

	return 0;
}

