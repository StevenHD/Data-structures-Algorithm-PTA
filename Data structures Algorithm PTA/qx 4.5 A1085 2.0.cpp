// A1085. 完美数列
// 二分查找，使用upper_bound函数


//--------CODE----------

#include "C.h"

const int maxn = 100010;
int n, p, a[maxn];

int main() 
{
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int ans = 1;
	for (int i = 0; i < n; i++) 
	{
		//---后面要减一个a，是因为前面给参数的时候first last都有a---
		//---因为upperbound函数需要用在一个 有序数组 中，a[]就是呢个有序数组---
		int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);

	return 0;
}
