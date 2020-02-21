// A1043. Is it a Binary Search Tree

///---CODE---

#include "C.h"

struct node 
{
	//---数据域---
	int data;

	//---指针域---
	node* left, * right;
};

void insert(node*& root, int data)  // insert函数也用到了递归 (插入结点数据)
									// 为什么root的类型是node* &？
{
	//--到达空结点时，即为需要插入的位置--
	if (root == NULL) 
	{
		root = new node;

		root->data = data;

		//--新建结点的时候要注意将其左右子结点地址设为NULL--
		//--这句不能漏--
		root->left = root->right = NULL;

		return;
	}

	//--插在左子树--
	if (data < root->data)  // 左边的data是初始输入的data，也就是题干的data(结点插入顺序)
							// 右边的root->data的呢个data我没太明白
		insert(root->left, data);

	//--插在右子树--
	else 
		insert(root->right, data);
}

//---先序遍历，结果存在vi中---
void preOrder(node* root, vector<int>& vi) // vi是vector容器
{
	if (root == NULL) 
		return;

	vi.push_back(root->data);

	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

//---镜像树先序遍历，结果存在vi中---
void preOrderMirror(node* root, vector<int>& vi) 
{
	if (root == NULL) 
		return;

	vi.push_back(root->data);
	
	preOrderMirror(root->right, vi);  // 先序和镜像先序的唯一区别是，这里先指向了right
									  // 先指向right，right就可以先判断NULL，先拿到data
	preOrderMirror(root->left, vi);
}

//---后序遍历，结果存在vi中---
void postOrder(node* root, vector<int>& vi) 
{
	if (root == NULL) 
		return;

	postOrder(root->left, vi);		  // 后序遍历则是先递归postOrder，然后再push_back数据
									  // 也就是说直到left、right都为NULL了后，才往里面push数据
	postOrder(root->right, vi);

	vi.push_back(root->data);
}

//---镜像树后序遍历，结果存在vi中---
void postOrderMirror(node* root, vector<int>& vi) 
{
	if (root == NULL) 
		return;

	postOrderMirror(root->right, vi);  // 区别还是right和left先后，不赘述了
	postOrderMirror(root->left, vi);

	vi.push_back(root->data);
}

//---origin为初始序列、pre、post为先序、后序，preM、postM为镜像树先序、后序---
vector<int> origin, pre, preM, post, postM;


int main() 
{
	int n, data;

	//--定义头结点--
	node* root = NULL;  // 初期，root->data的数值是0？

	//--输入结点个数n--
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &data);

		//--将数据加入origin--
		origin.push_back(data);

		//--将data插入二叉树--
		insert(root, data);
	}

	//--求先序序列--
	preOrder(root, pre);

	//--求镜像树的先序序列--
	preOrderMirror(root, preM);

	//--求后序序列--
	postOrder(root, post);

	//--求镜像树的后序序列--
	postOrderMirror(root, postM);

	//---初始序列等于先序序列---
	if (origin == pre) 
	{
		printf("YES\n");

		for (int i = 0; i < post.size(); i++)  // 为什么是post的size?
		{
			printf("%d", post[i]);

			if (i < post.size() - 1) 
				printf(" ");
		}
	}

	//---初始序列等于镜像先序序列---
	else if (origin == preM) 
	{
		printf("YES\n");

		for (int i = 0; i < postM.size(); i++) // 为什么是postM的size?
		{
			printf("%d", postM[i]);

			if (i < postM.size() - 1) 
				printf(" ");
		}
	}

	//--否则输出No--
	else 
	{
		printf("NO\n");
	}
	return 0;
}


//----答疑-----
// insert()括号中的root类型是 node* &
// preOrder呢四个括号中的root类型是 node*
// root本来就是 node* 类型的
// 所以在pre, preM, post, postM中，root值本身没有改变
// 只是靠root来产生4个序列，序列存储在4个vector(pre, preM, post, postM)中
// 然而insert中，root被重新定义了，数据域和指针域都改变了，还不断地递归insert()
// 所以说insert()中传入参数是用的 node* &