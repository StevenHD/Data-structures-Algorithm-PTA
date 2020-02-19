// A1048. Find Coins

//-------CODE--------

#include "C.h"

const int N = 1005;

//---定义一个全局变量hash表----
int HashTable[N];

int main() 
{
	//---n个元素，m为目标和---
	int n, m, a;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) 
	{
		//---在输入a的时候，就开始对hashTable[a]进行处理了---
		scanf("%d", &a);
		++HashTable[a];
	}

	//---枚举1~1005中的每一个数字i，若i存在于数列且m-i存在于数列，则说明找到了一对---
	for (int i = 0; i < N; i++) 
	{
		//---如果没有的话，说明hashTable[i]是0，0就意味着false---
		if (HashTable[i] && HashTable[m - i]) 
		{
			if (i == m - i && HashTable[i] <= 1) 
			{
				//---如果i和m-i是相等的，但是i出现的次数当前小于1次---
				//---就直接continue，进入下次迭代，说明当前这个i不符合题意，换个i(让i+1)---
				continue;
			}

			//---如果i和m-i都有，还不一样，次数也没有只有一次，就直接print---
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}

	//---只要有一例符合的，上面的for循环就会打印出来，然后return 0结束---
	//---所以说，要是没结束，说明没有一例符合，那么久 No solution---
	printf("No Solution\n");
	return 0;
}