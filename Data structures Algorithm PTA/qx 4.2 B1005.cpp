// B1005. 继续(3n+1)猜想

//对任何一个自然数n，如果它是偶数，那么把它砍掉一半；
//如果它是奇数，那么把(3n + 1)砍掉一半。
//这样一直反复砍下去，最后一定在某一步得到n = 1。

//---------CODE-----------

#include "C.h"

bool cmp(int a, int b) 
{
	return a > b;
}


int main() 
{
	int n, m;
	scanf("%d", &n);

	bool HashTable[1000] = { 0 };     //1000不行就开10000，必过

	int a[110];
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);

		//---变量m就是用来存储在3n+1猜想中经历的每个数---
		m = a[i];
		while (m != 1) 
		{
			//---如果m是偶数---
			if (m % 2 == 1) 
				m = (3 * m + 1) / 2;

			//---如果m是奇数---
			else 
				m = m / 2;

			//---让经历过的每个数都标记一下，表示已覆盖---
			HashTable[m] = true;
		}
	}

	//---count是用来计算“关键数”的个数的---
	int count = 0;
	for (int i = 0; i < n; i++) 
	{
		//---这里划重点了，hashTable[a[i]]!!---
		//---false就表示没有被覆盖，那么就是“关键数”---
		if (HashTable[a[i]] == false) 
		{
			count++;
		}
	}

	sort(a, a + n, cmp);

	//---现在已经对a[]从大到小排好序了---
	for (int i = 0; i < n; i++) 
	{
		//---同理，怕排完序后，只是序号变了，但是数值没有变，hashTable看的还是a[i]中存储的数值---
		if (HashTable[a[i]] == false) 
		{
			printf("%d", a[i]);
			count--;

			//---这个划重点，我本以为count是作为for循环的条件---
			//---将count--放进if中，也是个法子---
			//---因为是先count--再判断count>0，所以最后的空格就是count-1个空格---
			if (count > 0) 
				printf(" ");
		}
	}
	return 0;
}
