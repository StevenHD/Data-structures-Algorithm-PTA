// A1099. Build a Binary Search Tree

//---BST concept----
// 一个节点的左子树只包含键值小于该节点键值的节点
// 一个节点的右子树仅包含键值大于或等于该节点键值的节点
// 左右子树也必须是BST

//---题解---
// 如果题目给的是结点编号，那么使用二叉树的静态写法会比较方便

//------CODE------

#include "C.h"

const int maxn = 110;

//--二叉树的静态写法--
struct node {    
	int data;
	int lchild, rchild;  // 原先需要定义成指针的lchild和rchild，定义成了int型变量
} Node[maxn];


//--n为结点个数--
int n;

//--in为中序序列，num为已经填入 / 输出的结点个数--
int in[maxn], num = 0;                          // num的概念不太懂？


//---中序遍历，将排序好的序列依次填入二叉树结点---
void inOrder(int root) 
{
	if (root == -1) 
	{
		return;
	}

	//--这里是填入编号，比如0 1 6 2 3 7这种--
	inOrder(Node[root].lchild);  // 一开始给定的lchildID相当于给定了二叉树

	//---填入序列中的整数---
	//--这里是往编号中填入结点权值--
	Node[root].data = in[num++];    

	inOrder(Node[root].rchild);  // 填入二叉树结点，需要不断递归
}


//---输出这棵二叉查找树的层序遍历序列---
//---层序遍历---
void BFS(int root) 
{
	queue<int> q;				// 注意队列里是存地址
	q.push(root);				// 将根结点地址入队

	num = 0;
	while (!q.empty()) 
	{
		int now = q.front();    // 取出队首元素，用now来存储
		q.pop();

		printf("%d", Node[now].data);  // 访问队首元素
		num++;

		if (num < n) 
			printf(" ");

		//--左子树非空--
		if (Node[now].lchild != -1) 
			q.push(Node[now].lchild);  

		//--右子树非空--
		if (Node[now].rchild != -1) 
			q.push(Node[now].rchild);  
	}
}

int main() 
{
	int lchildID, rchildID;
	scanf("%d", &n);    // n为结点个数

	for (int i = 0; i < n; i++) 
	{
		//---输入左右孩子编号---
		scanf("%d%d", &lchildID, &rchildID);    

		Node[i].lchild = lchildID;  // 将编号赋值为结构体Node的lchild和rchild
		Node[i].rchild = rchildID;  // lchild和rchild代表的就是左右孩子
	}

	for (int i = 0; i < n; i++) 
	{
		//---输入排序前的序列---
		scanf("%d", &in[i]);        // 这个含有N个整数的序列，需要将里面的N个整数填入二叉树的结点中
	}

	//--从小到大排序，作为中序序列--
	sort(in, in + n);				// 对一棵BST而言，中序遍历是递增的，所以从小到大排序

	//---以0号结点为根结点进行中序遍历，填入整数---
	//--对给定的二叉树进行中序遍历--
	inOrder(0);

	//--inOrder结束后，二叉树的结点编号和对应权值就已经完成了--
	//---输出层序遍历序列---
	BFS(0);

	return 0;
}
