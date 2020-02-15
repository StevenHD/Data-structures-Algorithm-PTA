// B1025/A1074  反转链表
#include "C.h"

const int maxn = 100010;
struct Node 
{
	//--定义静态链表--
	int address, data, next;
	int order;
}node[maxn];


bool cmp(Node a, Node b) 
{
	//--order表示结点在链表中的序号(从0开始)，其中无效结点为maxn--
	if (a.order == -1 || b.order == -1) 
	{
		return a.order > b.order;
	}
	else 
	{
		//--如果结点均有效，则对结点按order从小到大排序--
		return a.order < b.order; 
	}
}


int main() 
{
	for (int i = 0; i < maxn; i++) 
	{
		//--令order的初值均为-1，表示初始时所有结点为无效结点--
		node[i].order = -1;
	}

	//--begin表示链表首地址--
	//--n表示结点的个数--
	//--K表示步长--
	int begin, n, K, address;
	scanf("%d%d%d", &begin, &n, &K);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	//--count计算有效结点的数目--
	int p = begin, count = 0;

	//---遍历链表找出单链表的所有有效结点---
	while (p != -1) // 对于链表的遍历通常使用while，因为判断条件是address为-1
	{
		//--结点在单链表中的序号order由count赋值--
		//--所以序号order和count是同步的，都是1 2 3 4 5.....
		node[p].order = count++;

		//--下一个结点--
		p = node[p].next;
	}

	//--按单链表从头到尾顺序排列--
	sort(node, node + maxn, cmp);

	//--有效结点为前count个结点--
	//--为了书写方便，把count赋给n--
	n = count;

	//--单链表已经形成--
	for (int i = 0; i < n / K; i++) 
		//--- 枚举完整的 n/K 块 ---
	{
		for (int j = (i + 1) * K - 1; j > i* K; j--) 
		{
			//--第i块倒着输出--
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}

		//--接下来是每一块的最后一个结点的next地址的处理--
		printf("%05d %d ", node[i * K].address, node[i * K].data);

		//---如果不是最后一块---
		//---就指向下一块的最后一个结点---
		if (i < n / K - 1) 
		{
			printf("%05d\n", node[(i + 2) * K - 1].address);
		}

		//---如果是最后一块---
		else 
		{
			//--还恰好是最后一个结点，则输出-1--
			if (n % K == 0) 
			{
				printf("-1\n");
			}

			//--剩下不完整的块按原先的顺序输出--
			else 
			{
				printf("%05d\n", node[(i + 1) * K].address);
				for (int i = n / K * K; i < n; i++) 
				{
					printf("%05d %d ", node[i].address, node[i].data);
					if (i < n - 1) 
					{
						printf("%05d\n", node[i + 1].address);
					}
					else 
					{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
