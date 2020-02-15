// A1097 Deduplication on a Linked List

#include "C.h"

const int maxn = 100005;
const int TABLE = 1000010;

struct Node 
{    //---定义静态链表（第一步）---
	int address, data, next;

	//--结点在链表上的序号，无效结点记为2*maxn--
	int order;    
}node[maxn];

//---绝对值是否已经出现---
bool isExist[TABLE] = { false };

bool cmp(Node a, Node b) 
{
	return a.order < b.order;    // 按order从小到大排序
}


int main() 
{
	//--初始化isExist为false，表示未出现过当前结点权值的绝对值--
	memset(isExist, false, sizeof(isExist));    

	for (int i = 0; i < maxn; i++) 
	{    //--初始化（第二步）--
		 //--表示初始时均为无效结点--
		 //--这样无效结点后面就会被区分开--
		node[i].order = 2 * maxn;    
	}

	//---起始地址，结点个数---
	int n, begin, address;
	scanf("%d%d", &begin, &n);    
	for (int i = 0; i < n; i++) 
	{    //---输入所有结点---
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	//---未删除的有效结点个数、已删除的有效结点个数---
	int countValid = 0, countRemoved = 0, p = begin;
	while (p != -1) 
	{    //---枚举链表（第三步）---
		if (!isExist[abs(node[p].data)]) 
		{    //---data的绝对值此时还不存在---
			isExist[abs(node[p].data)] = true;    // 标记为已存在
			node[p].order = countValid++;    // 不删除，编号从0开始
		}

		else
		{    //--如果data的绝对值已存在--
			node[p].order = maxn + countRemoved++;    // isExist不更新，表示被删除
													  // 编号从maxn开始
		}
		p = node[p].next;    // 下一个结点
	}

	sort(node, node + maxn, cmp);    // 按order从小到大排序（第四步）

	// 输出结果（第五步）
	int count = countValid + countRemoved;    // 有效结点个数
	for (int i = 0; i < count; i++)
	{
		if (i != countValid - 1 && i != count - 1) 
		{    //---非最后一个结点---
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		}
		else
		{    // 最后一个结点单独处理，直接写成-1
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}
