// A1064. Complete Binary Search Tree

//--------CODE---------

#include "C.h"

const int maxn = 1010;

//---n为结点个数---
int n;

//--number[]数组用来存放结点权值--
//--CBT[]数组用来存放完全二叉树--
int number[maxn], CBT[maxn];

//--index从小到大枚举number[]数组--
int index = 0;

//--中序遍历--
void inOrder(int root) 
{
	//--完全二叉树到达空结点的标志：当前结点root的编号大于结点个数n--
	//---所以(root > n)空结点，直接return返回---
	if (root > n) 
		return;

	//--往左子树递归--
	//--如果使用数组来存放完全二叉树，那么对完全二叉树当中的任何一个结点(设编号为x，其中根结点编号为1)--
	//--其左孩子结点的编号一定是2x，而右孩子结点的编号一定是2x+1
	inOrder(root * 2);

	//---开一个数组CBT[maxn]，其中CBT[1]~CBT[n]按层序存放完全二叉树的n个结点--
	//--根结点处赋值number[index]--
	CBT[root] = number[index++];

	//---往右子树递归---
	inOrder(root * 2 + 1);  // root就是结点编号
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &number[i]);  // 输入样例给的就是每一个结点的权值
	}

	//--从小到大排序--
	sort(number, number + n);

	//--1号位为根结点--
	inOrder(1);                    // 完全二叉树的根结点编号为1


	for (int i = 1; i <= n; i++) 
	{
		//---CBT[]数组本身就是层序---
		printf("%d", CBT[i]);

		if (i < n) 
			printf(" ");
	}

	return 0;
}
