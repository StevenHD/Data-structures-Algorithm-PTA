// A1020. Tree Traversals  二叉树的遍历

//---CODE-----

#include "C.h"

const int maxn = 50;
struct node 
{
	int data;
	node* lchild;
	node* rchild;
};

//---先序、中序、后序---
int pre[maxn], in[maxn], post[maxn];

//---n为结点个数---
int n;

//---当前二叉树的后序序列区间为[postL, postR]，中序序列区间为[inL, inR]---
//---create函数返回构建出的二叉树的根结点地址---
node* create(int postL, int postR, int inL, int inR) 
{
	if (postL > postR) 
	{
		//---postL大于postR，意味着后序序列长度小于等于0，这样就直接返回---
		return NULL;
	}

	//---新建一个新的结点，用来存放当前二叉树的根结点---
	node* root = new node;

	//---新结点的数据域为根结点的值---
	root->data = post[postR];  // 后序序列的最后一个结点就是根结点

	//---k是中序序列的一个位置，in[k]=post[postR]---
	//---这样就找到了中序序列中的根结点---
	int k;
	for (k = inL; k <= inR; k++) 
	{
		//---在中序序列中找到in[k] == pre[L]的结点---
		if (in[k] == post[postR]) 
		{
			break;
		}
	}

	//---numLeft为左子树的结点个数---
	int numLeft = k - inL;

	//---返回左子树的根结点地址---
	//---将该地址赋值给root的左指针---
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);

	//---返回右子树的根结点地址---
	//---将该地址赋值给root的右指针---
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR); // root这个结点是用来
																   // 存放二叉树的根结点的
	//---返回根结点地址---
	return root;
}

//---num表示已输出的结点个数---
int num = 0;

//***BFS函数不太懂？***
void BFS(node* root) 
{
	//--注意队列里是存地址--
	//--这里是定义一个队列q--
	queue<node*> q;

	//--将根结点地址入队--
	q.push(root);


	while (!q.empty()) 
	{
		//---取出队首元素---
		node* now = q.front();
		q.pop();
		
		//--访问队首元素--
		printf("%d", now->data);
		num++;

		if (num < n) 
			printf(" ");

		//---左子树非空---
		if (now->lchild != NULL) 
			q.push(now->lchild);

		//---右子树非空---
		if (now->rchild != NULL) 
			q.push(now->rchild);
	}
}


int main() 
{
	//---n表示结点个数---
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &post[i]);
	}

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &in[i]);
	}

	//---根据已知的后序遍历和中序遍历，建立二叉树---
	node* root = create(0, n - 1, 0, n - 1);

	//---层序遍历---
	BFS(root);

	return 0;
}
