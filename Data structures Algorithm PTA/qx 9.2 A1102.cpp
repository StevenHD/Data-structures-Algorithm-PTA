// A1102. Invert a Binary Tree

//---CODE----

#include "C.h"

const int maxn = 110;

//---二叉树的静态写法---
struct node 
{    
	int lchild;  // 静态写法就是不用指针
	int rchild;
} Node[maxn];

//--记录是否不是根结点，初始均是根结点--
bool notRoot[maxn] = { false };    

//---n为结点个数，num为当前已经输出的结点个数---
int n, num = 0;    

//--print函数输出结点id的编号--
void print(int id) 
{
	//--输出id--
	printf("%d", id);    

	//--已经输出的结点个数加1--
	num++;    

	//---最后一个结点不输出空格---
	if (num < n) 
		printf(" ");    
	else 
		printf("\n");
}

//--中序遍历--
//--中序遍历也用到了递归--
void inOrder(int root) 
{
	//---root表示-1不存在---
	if (root == -1) 
	{
		return;
	}

	inOrder(Node[root].lchild);

	//---当root的lchild不存在的时候，return回来，打印当前这个root---
	print(root);

	//---因为已经打印过root了，所以判断rchild是不需要再重新打印root的---
	//--那么在print后面再加一个inOrder(rchild)的代码是为了看看这个rchild还有木有左右孩子--
	inOrder(Node[root].rchild);
}


//--层序遍历--
void BFS(int root) 
{
	//--注意队列里是存地址--
	//--新建一个队列q--
	queue<int> q;  

	//--将根结点地址入队q--
	q.push(root);  

	while (!q.empty()) 
	{
		//---取出队首元素---
		int now = q.front();  
		q.pop();

		print(now);

		//--左子树非空--
		if (Node[now].lchild != -1) 
			q.push(Node[now].lchild); 

		//--右子树非空--
		if (Node[now].rchild != -1) 
			q.push(Node[now].rchild);  
	}
}


//--后序遍历，用以反转二叉树--
void postOrder(int root) 
{
	if (root == -1) 
	{
		return;
	}

	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);

	swap(Node[root].lchild, Node[root].rchild);    // 交换左右孩子
}


//--将输入的字符转换为-1或者结点编号--
int strToNum(char c) 
{
	if (c == '-') 
		//--“-”表示没有孩子结点，记为-1--
		return -1;    
	else 
	{
		//--标记c不是根结点--
		notRoot[c - '0'] = true;    

		// 返回结点编号
		return c - '0';    
	}
}


//--寻找根结点编号--
int findRoot() 
{
	for (int i = 0; i < n; i++) 
	{
		if (notRoot[i] == false)  // notRoot[i] = false 意味着结点i是根结点
		{
			//---是根结点，返回i---
			return i;    
		}
	}
}


int main() 
{
	char lchild, rchild;
	scanf("%d", &n);    // n为结点个数

	for (int i = 0; i < n; i++) 
	{
		//--左右孩子--
		scanf("%*c%c %c", &lchild, &rchild);  // 注意小技巧scanf("%*c")，也就是用%*c就可以在scanf中
											  // 接收一个字符  
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}

	//--获得根结点编号--
	int root = findRoot();    

	//--后序遍历，反转二叉树--
	postOrder(root);   

	//--输出层序遍历序列--
	BFS(root);    

	//--已输出的结点个数置0--
	num = 0;     // 为什么要置0？下面的inOrder()中也没有用到num啊

	//--输出中序遍历序列--
	inOrder(root);    

	return 0;
}

