// A1048. Find Coins

#include "C.h"

int a[100010];

//---left和right的初始值分别为0和n-1，key为m-a[i]---
int Bin(int left, int right, int key) 
{
	int mid;
	while (left <= right) 
	{
		//--取left和right的中点--
		mid = (left + right) / 2;

		//--如果找到了key，则返回下标mid--
		if (a[mid] == key) 
			return mid;
		else if (a[mid] > key) 
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return -1;
}

int main() 
{
	int i, n, m;
	scanf("%d%d", &n, &m);


	for (i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}

	//---排序---
	sort(a, a + n);

	for (i = 0; i < n; i++) 
	{
		//---寻找m-a[i]---
		int pos = Bin(0, n - 1, m - a[i]);

		//---找到了匹配的a[i]和m-a[i]---
		if (pos != -1 && i != pos) 
		{
			printf("%d %d\n", a[i], a[pos]);

			//--因为如果有多种方案，输出a最小的---
			//---所以从i=0开始，如果有符合条件的---
			//---输出后，直接break，不再迭代寻找解---
			break;
		}
	}

	if (i == n) 
		printf("No Solution\n");

	return 0;
}
