// A1086. Tree Traversals Again

//----CODE-----

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

//---n表示结点个数---
int n;

//---当前二叉树的先序序列区间为[preL,preR]---
//---中序序列区间为[inL, inR]---
//---create函数返回构建出的二叉树的根结点地址(也就是root)---
node* create(int preL, int preR, int inL, int inR) 
{
	//---若先序序列长度小于等于0，则直接返回---
	if (preL > preR) 
	{
		return NULL;
	}

	//---新建一个新的结点，用来存放当前二叉树的根结点---
	node* root = new node;

	//---新结点的数据域(root->data)为根结点的值(pre[preL]——先序遍历的左边界)---
	root->data = pre[preL];

	int k;
	for (k = inL; k <= inR; k++) 
	{
		//---在中序序列中找到in[k] == pre[preL]的结点---
		//---也就是在中序序列中找一个位置k，in[k]存储的就是二叉树的根结点的值---
		if (in[k] == pre[preL])
		{
			break;
		}
	}

	//---numLeft为左子树的个数---
	int numLeft = k - inL;

	//---等于右边create()返回左子树的根结点地址---
	//---赋值给root的左指针---
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1); // create()括号中分别是先序和中序
																 // 的左子树范围和右子树范围

	//---等于右边create()返回右子树的根结点地址---
	//---赋值给root的右指针---
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	//---返回根结点地址---
	return root;
}

//---已输出的结点个数---
int num = 0;

//---后序遍历---
void postorder(node* root) 
{
	if (root == NULL) 
	{
		return;
	}

	postorder(root->lchild);
	postorder(root->rchild);

	printf("%d", root->data);
	num++;

	if (num < n) 
		printf(" ");
}

int main() 
{
	//---n表示结点个数---
	scanf("%d", &n);

	//---str是用来表示push、pop这两个单词的---
	char str[5];

	//---定义一个int类型的栈st---
	stack<int> st;
	
	//---x表示入栈元素---
	int x;

	//---preIndex表示先序序列位置，inIndex表示中序序列位置---
	int preIndex = 0, inIndex = 0;

	//---2n表示出栈入栈共2n次---
	for (int i = 0; i < 2 * n; i++) 
	{
		//---输入Push或者Pop---
		scanf("%s", str);

		//---入栈---
		if (strcmp(str, "Push") == 0) 
		{
			scanf("%d", &x);

			//---令先序遍历pre[preIndex] = x---
			pre[preIndex++] = x;

			//---往栈st中push元素x---
			st.push(x);
		}
		else 
		{
			//---令中序遍历in[inIndex] = st.top() 等于栈顶元素---
			in[inIndex++] = st.top();

			//---栈弹出pop---
			st.pop();
		}
	}

	//---根据先序遍历和中序遍历的范围[0, n-1]建立二叉树---
	node* root = create(0, n - 1, 0, n - 1);  // main()函数中的create()的范围一直是[0,n-1]
											  // 在create()中会递归使用create()，里面的范围会具体化

	//---后序遍历---
	postorder(root);

	return 0;
}


//----Summary----
// postorder、create都是递归，也就是说求后序遍历，通过先序中序得到根结点地址都要用到递归
// 上一个题的层序遍历的BFS()函数没有用到递归