// A1043. Is it a Binary Search Tree

///---CODE---

#include "C.h"

struct node 
{
	//---������---
	int data;

	//---ָ����---
	node* left, * right;
};

void insert(node*& root, int data)  // insert����Ҳ�õ��˵ݹ� (����������)
									// Ϊʲôroot��������node* &��
{
	//--����ս��ʱ����Ϊ��Ҫ�����λ��--
	if (root == NULL) 
	{
		root = new node;

		root->data = data;

		//--�½�����ʱ��Ҫע�⽫�������ӽ���ַ��ΪNULL--
		//--��䲻��©--
		root->left = root->right = NULL;

		return;
	}

	//--����������--
	if (data < root->data)  // ��ߵ�data�ǳ�ʼ�����data��Ҳ������ɵ�data(������˳��)
							// �ұߵ�root->data���ظ�data��û̫����
		insert(root->left, data);

	//--����������--
	else 
		insert(root->right, data);
}

//---����������������vi��---
void preOrder(node* root, vector<int>& vi) // vi��vector����
{
	if (root == NULL) 
		return;

	vi.push_back(root->data);

	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

//---����������������������vi��---
void preOrderMirror(node* root, vector<int>& vi) 
{
	if (root == NULL) 
		return;

	vi.push_back(root->data);
	
	preOrderMirror(root->right, vi);  // ����;��������Ψһ�����ǣ�������ָ����right
									  // ��ָ��right��right�Ϳ������ж�NULL�����õ�data
	preOrderMirror(root->left, vi);
}

//---����������������vi��---
void postOrder(node* root, vector<int>& vi) 
{
	if (root == NULL) 
		return;

	postOrder(root->left, vi);		  // ������������ȵݹ�postOrder��Ȼ����push_back����
									  // Ҳ����˵ֱ��left��right��ΪNULL�˺󣬲�������push����
	postOrder(root->right, vi);

	vi.push_back(root->data);
}

//---����������������������vi��---
void postOrderMirror(node* root, vector<int>& vi) 
{
	if (root == NULL) 
		return;

	postOrderMirror(root->right, vi);  // ������right��left�Ⱥ󣬲�׸����
	postOrderMirror(root->left, vi);

	vi.push_back(root->data);
}

//---originΪ��ʼ���С�pre��postΪ���򡢺���preM��postMΪ���������򡢺���---
vector<int> origin, pre, preM, post, postM;


int main() 
{
	int n, data;

	//--����ͷ���--
	node* root = NULL;  // ���ڣ�root->data����ֵ��0��

	//--���������n--
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &data);

		//--�����ݼ���origin--
		origin.push_back(data);

		//--��data���������--
		insert(root, data);
	}

	//--����������--
	preOrder(root, pre);

	//--����������������--
	preOrderMirror(root, preM);

	//--���������--
	postOrder(root, post);

	//--�������ĺ�������--
	postOrderMirror(root, postM);

	//---��ʼ���е�����������---
	if (origin == pre) 
	{
		printf("YES\n");

		for (int i = 0; i < post.size(); i++)  // Ϊʲô��post��size?
		{
			printf("%d", post[i]);

			if (i < post.size() - 1) 
				printf(" ");
		}
	}

	//---��ʼ���е��ھ�����������---
	else if (origin == preM) 
	{
		printf("YES\n");

		for (int i = 0; i < postM.size(); i++) // Ϊʲô��postM��size?
		{
			printf("%d", postM[i]);

			if (i < postM.size() - 1) 
				printf(" ");
		}
	}

	//--�������No--
	else 
	{
		printf("NO\n");
	}
	return 0;
}


//----����-----
// insert()�����е�root������ node* &
// preOrder���ĸ������е�root������ node*
// root�������� node* ���͵�
// ������pre, preM, post, postM�У�rootֵ����û�иı�
// ֻ�ǿ�root������4�����У����д洢��4��vector(pre, preM, post, postM)��
// Ȼ��insert�У�root�����¶����ˣ��������ָ���򶼸ı��ˣ������ϵصݹ�insert()
// ����˵insert()�д���������õ� node* &