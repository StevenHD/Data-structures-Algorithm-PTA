// A1044. Shopping in Mars

//---重点---
// 使用二分法的前提，针对的数组是严格单调递增的。

#include "C.h"

const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;


//---upper_bound函数的返回值是位置---
int upper_bound(int L, int R, int x) 
{
	int left = L, right = R, mid;

	while (left < right) 
	{
		mid = (left + right) / 2;

		if (sum[mid] > x) 
		{
			right = mid;
		}
		else 
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	//---n为元素个数，S表示和值---
	scanf("%d%d", &n, &S);
	sum[0] = 0;

	//---这个for循环是用来求sum[i]的---
	// S这个和值表示的是目标，sum[i]则是要达到这个目标的一个工具。
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}


	//---枚举左端点---
	for (int i = 1; i <= n; i++) 
	{
		//---通过枚举左端点来求右端点---
		int j = upper_bound(i, n + 1, sum[i - 1] + S);

		//---相等说明查找成功（注意是j-1而不是j）----
		if (sum[j - 1] - sum[i - 1] == S) 
		{
			//---最接近S的值就是S---
			nearS = S;
			break;
		}

		//---存在大于S的解并小于nearS---
		else if (j <= n && sum[j] - sum[i - 1] < nearS) 
		{
			nearS = sum[j] - sum[i - 1];
		}
	}


	//---这是第二次遍历---
	//---第二次遍历是找到那些和值恰好为nearS的方案并输出---
	for (int i = 1; i <= n; i++) 
	{
		//--求右端点--
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);

		//--查找成功--
		if (sum[j - 1] - sum[i - 1] == nearS) 
		{
			//--输出左端点和右端点--
			//--注意是j-1而不是j--
			printf("%d-%d\n", i, j - 1);
		}
	}

	return 0;
}
