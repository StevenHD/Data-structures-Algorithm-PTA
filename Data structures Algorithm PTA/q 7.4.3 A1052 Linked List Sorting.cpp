// A1052 Linked List Sorting 使用静态链表搞事情

#include "C.h"
const int maxn = 100005;

struct Node 
{
	//---定义静态链表---
	//---flag=true的时候表示结点不在链表上(无效结点)---
	int address, data, next;
	bool flag; //--结点是否在链表上---
}node[maxn];

bool cmp(Node a, Node b) 
{
	if (a.flag == false || b.flag == false) 
	{
		//--因为有效结点的flag为1，无效结点的flag为0--
		//--这样可以把有效结点排到数组左端---
		//--只要a和b中有一个无效结点，就把它放到后面去--
		return a.flag > b.flag;
	}
	else 
	{
		//--如果都是有效结点，则按Key的大小排序--
		return a.data < b.data;
	}
}
int main() 
{
	for (int i = 0; i < maxn; i++) 
	{
		//--初始化，令flag均为false--
		node[i].flag = false;
	}

	//--begin表示头结点的地址---
	//--address表示除头结点外，其他每个结点的地址---
	int n, begin, address;
	scanf("%d%d", &n, &begin);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, 
			&node[address].next);			// 这里还是拿结点地址当下标
		node[address].address = address;
	}

	int count = 0, p = begin;

	//---枚举链表，对flag进行标记，同时计算count有效结点的个数---
	while (p != -1) // 变量p中存储的就是每个结点的地址
	{
		node[p].flag = true;
		count++;
		p = node[p].next; // next表示的就是下个结点的地址
	}

	//---特判，新链表中没有结点时(count=0)，输出0 -1
	if (count == 0) 
	{
		printf("0 -1");
	}
	else 
	{
		//--筛选有效结点，并按data从小到大排序--
		sort(node, node + maxn, cmp); //**为什么这里是node+maxn？maxn很大啊我记得。。。***
		
		//--输出结果--
		//--防止-1被%05d化，提前判断--
		//---也就是说注意-1的输出---
		printf("%d %05d\n", count, node[0].address); //***node[0]表示的是头结点的地址?***
													 //--对，就是排好序后第一个结点的地址!--

		for (int i = 0; i < count; i++) 
		{
			//--防止-1被%05d化，提前判断的解决方案--
			if (i != count - 1) 
			{
				printf("%05d %d %05d\n", node[i].address, 
					node[i].data, node[i + 1].address); // 因为已经排好序了
														// 所以就按for顺序来就好
			}

			//--防止-1被%05d化，提前判断的解决方案--
			else 
			{
				printf("%05d %d -1\n", node[i].address, node[i].data); 
			}
		}
	}

	return 0;
}
