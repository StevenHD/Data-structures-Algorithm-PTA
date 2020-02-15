#include "C.h"

//---题意---
// 比如说，loading和being两个单词中，字母i的地址就是要输出的答案。
// 但是像 as 和 at 这两个就不行，首字母是不算的

//------CODE------
const int maxn = 100010;
struct NODE 
{
	//---data是数据域---
	//---next是一个int型的整数，用以存放下一个结点的地址---
	//---next事实上就是数组下标---
	char data;
	int next;

	//---flag用来表示结点是否在第一条链表中出现---
	bool flag;
}node[maxn];

int main() 
{
	for (int i = 0; i < maxn; i++) 
	{
		node[i].flag = false; // 通常刚开始，flag都会被初始化成false
	}

	int n;
	int stAddressOfFirstLL;
	int stAddressOfSecondLL;
	scanf("%d%d%d", &stAddressOfFirstLL, &stAddressOfSecondLL, &n);

	//---定义结点地址和后继结点地址---
	int addrOfNode, addrOfNextNode;
	char eachLetter;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &addrOfNode, &eachLetter, &addrOfNextNode);
		node[addrOfNode].data = eachLetter;
		node[addrOfNode].next = addrOfNextNode;
	}

	int p; // 这个p之所以不在for()里面定义，是因为这个p要在两个链表中遍历
	for (p = stAddressOfFirstLL; p != -1; p = node[p].next) 
	{
		// p的初值是首地址，只要p不等于NULL，p就不断地更新当前结点的后继结点的地址
		//---枚举第一条链表的所有结点，令其出现次数为1---
		node[p].flag = true;
	}

	for (p = stAddressOfSecondLL; p != -1; p = node[p].next) 
	{
		// 当p遍历完第一条链表的所有结点后
		// 开始从第二条链表的首地址开始，遍历所有结点
		// 因为下标p存的就是地址，所以如果node[p].flag是true
		// 说明在第一个中已经出现过
		// 那么就直接break跳出当前for循环，其实p肯定不是-1，那么printf出来即可。
		if (node[p].flag == true) 
			break;
	}

	if (p != -1) 
	{
		printf("%05d\n", p);
	}

	else 
	{
		printf("-1\n");
	}
	return 0;
}