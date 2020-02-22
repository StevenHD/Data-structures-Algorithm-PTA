// A1007. Maximum Subsequence Sum  最大子序列和

//------CODE------

#include "C.h"

const int maxn = 10010;

//--a[i]存放序列，dp[i]存放以a[i]结尾的连续序列的最大和--
int a[maxn], dp[maxn];

//--s[i]表示产生dp[i]的连续序列从a的哪一个元素开始--
int s[maxn] = { 0 };

int main() 
{
	int n;
	scanf("%d", &n);

	//--flag表示数组a[]中是否全小于0--
	bool flag = false;
	for (int i = 0; i < n; i++) 
	{
		//--读入序列--
		scanf("%d", &a[i]);

		if (a[i] >= 0) 
			flag = true;
	}

	if (flag == false) 
	{
		//--如果a[]中所有数字都小于0，则输出0以及首尾元素--
		printf("0 %d %d\n", a[0], a[n - 1]);
		return 0;
	}

	//--先进行设定边界，dp[0]=a[0]，因为只有这个无法通过前面的元素得到(前面没有元素)--
	//---边界---
	dp[0] = a[0];

	for (int i = 1; i < n; i++)              // 这里和上边不同，i是从1开始的，上面是从0开始的
	{
		//--状态转移方程--
		if (dp[i - 1] + a[i] > a[i]) 
		{
			dp[i] = dp[i - 1] + a[i];
			s[i] = s[i - 1];
		}

		else 
		{
			dp[i] = a[i];
			s[i] = i;
		}
	}

	//--因为dp[i]存放的是以a[i]结尾的连续序列的最大和--
	//--所以需要遍历i得到最大的才是结果--
	int k = 0;
	for (int i = 1; i < n; i++)                       // 这里i也是从1开始的
	{
		if (dp[i] > dp[k]) 
		{
			k = i;
		}
	}
	printf("%d %d %d\n", dp[k], a[s[k]], a[k]);       // s[k]存放的是下标
	return 0;
}
