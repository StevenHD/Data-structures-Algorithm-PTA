// A1020. Tree Traversals  �������ı���

//---CODE-----

#include "C.h"

const int maxn = 50;
struct node 
{
	int data;
	node* lchild;
	node* rchild;
};

//---�������򡢺���---
int pre[maxn], in[maxn], post[maxn];

//---nΪ������---
int n;

//---��ǰ�������ĺ�����������Ϊ[postL, postR]��������������Ϊ[inL, inR]---
//---create�������ع������Ķ������ĸ�����ַ---
node* create(int postL, int postR, int inL, int inR) 
{
	if (postL > postR) 
	{
		//---postL����postR����ζ�ź������г���С�ڵ���0��������ֱ�ӷ���---
		return NULL;
	}

	//---�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����---
	node* root = new node;

	//---�½���������Ϊ������ֵ---
	root->data = post[postR];  // �������е����һ�������Ǹ����

	//---k���������е�һ��λ�ã�in[k]=post[postR]---
	//---�������ҵ������������еĸ����---
	int k;
	for (k = inL; k <= inR; k++) 
	{
		//---�������������ҵ�in[k] == pre[L]�Ľ��---
		if (in[k] == post[postR]) 
		{
			break;
		}
	}

	//---numLeftΪ�������Ľ�����---
	int numLeft = k - inL;

	//---�����������ĸ�����ַ---
	//---���õ�ַ��ֵ��root����ָ��---
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);

	//---�����������ĸ�����ַ---
	//---���õ�ַ��ֵ��root����ָ��---
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR); // root������������
																   // ��Ŷ������ĸ�����
	//---���ظ�����ַ---
	return root;
}

//---num��ʾ������Ľ�����---
int num = 0;

//***BFS������̫����***
void BFS(node* root) 
{
	//--ע��������Ǵ��ַ--
	//--�����Ƕ���һ������q--
	queue<node*> q;

	//--��������ַ���--
	q.push(root);


	while (!q.empty()) 
	{
		//---ȡ������Ԫ��---
		node* now = q.front();
		q.pop();
		
		//--���ʶ���Ԫ��--
		printf("%d", now->data);
		num++;

		if (num < n) 
			printf(" ");

		//---�������ǿ�---
		if (now->lchild != NULL) 
			q.push(now->lchild);

		//---�������ǿ�---
		if (now->rchild != NULL) 
			q.push(now->rchild);
	}
}


int main() 
{
	//---n��ʾ������---
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &post[i]);
	}

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &in[i]);
	}

	//---������֪�ĺ���������������������������---
	node* root = create(0, n - 1, 0, n - 1);

	//---�������---
	BFS(root);

	return 0;
}
