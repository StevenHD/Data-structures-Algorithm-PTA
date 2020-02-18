// A1085. 完美数列

//---思路---
// 因为题目中涉及到了序列的最大值和最小值，所以可以先进行排序。

//------CODE------

#include "C.h"

const int maxn = 100010;

//---n表示一共有n个数、p表示参数、a[]表示序列---
int n, p, a[maxn];

//----BS函数在[i+1,n-1]范围内查找第一个大于x的数的位置----
int binarySearch(int i, long long x) 
{
	//---这个是种边界情况：序列中所有数都不超过a[i]*p的情况---
	//---比如序列1 2 3，p是3，这种情况应该输出3，因为3个数都不超过1*3---
	//--如果所有数都不大于x，返回n--
	if (a[n - 1] <= x)  // 这时候已经排过序了，所以说a[n-1]就是最大的数
						// 不过为什么要返回n呢？而不是返回n-1？
						// 难道是因为a[n-1]最多也只是等于x，只有a[n]是可能大于x的？
		return n;

	//--在[i+1,n-1]内查找--
	int l = i + 1;
	int r = n - 1;
	int mid;

	while (l < r) 
	{
		mid = (l + r) / 2;

		//--如果a[mid]<=x，说明第一个大于x的数只可能在mid后面--
		if (a[mid] <= x) 
		{
			//-- 那么左端点就记作 mid+1 --
			l = mid + 1;
		}

		else 
		{
			r = mid;
		}
	}

	//--因为在while循环结束时，l==r，所以返回l或者r都可以--
	return l;
}

int main() 
{
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}

	//---递增排序---
	sort(a, a + n);

	//---最大长度，初值为1，表示至少有一个数---
	int maxLength = 1;
	for (int i = 0; i < n; i++) 
	{
		int j = binarySearch(i, (long long)a[i] * p);

		//---更新最大长度---
		maxLength = max(maxLength, j - i); // 返回n的我明白了，因为i到j一共有(j-i+1)个数
										   // 而这里没有+1，那么刚好n-i就是距离，也就是数字多少
	}
	printf("%d\n", maxLength);

	return 0;
}
