// A1041. Be Unique

//-------------CDOE--------------

#include "C.h"

//---a[]为输入的数字，hashTable[]为散列数组---
int a[100001];
int HashTable[10001] = { 0 };

int main() 
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		//---当前输入的数为a[i]---
		scanf("%d", &a[i]);

		//---数字a[i]出现的次数加1---
		HashTable[a[i]]++;
	}

	//---变量ans是存放第一次出现的在序列中只有一个的数字---
	int ans = -1;
	for (int i = 0; i < n; i++) 
	{
		//---hashTable[a[i]]如果为1，说明a[i]只出现了一次---
		if (HashTable[a[i]] == 1) 
		{
			//---那么答案就是a[i]，直接退出for循环---
			ans = a[i];
			break;
		}
	}

	//---ans为-1说明找不到只出现了一次的数字，输出"None"---
	if (ans == -1) 
		printf("None");
	else 
		printf("%d\n", ans);

	return 0;
}
