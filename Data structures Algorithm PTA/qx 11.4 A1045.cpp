// A1045. Favorite Color Stripe
// 使用最长公共子序列LCS

#include "C.h"

//--maxc为颜色的最大种类数，maxn为颜色序列的最大长度--
const int maxc = 210;
const int maxn = 10010;

int A[maxc], B[maxn], dp[maxc][maxn];

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);

	//---读入序列A---
	for (int i = 1; i <= m; i++) 
	{
		scanf("%d", &A[i]);      // 序列A就是喜欢的颜色个数的序列。这里是2 3 1 5 6
	}

	int L;
	scanf("%d", &L);

	//---读入序列B---
	for (int i = 1; i <= L; i++) // 这里 L = 12
	{
		scanf("%d", &B[i]);      // 序列B就是给定的条纹序列。这里是2 2 4 1 5 5 6 3 1 1 5 6
	}

	//--边界--
	for (int i = 0; i <= m; i++) 
	{
		dp[i][0] = 0;
	}

	for (int j = 0; j <= L; j++) 
	{
		dp[0][j] = 0;
	}

	//---状态转移方程---
	//--最终的dp[m][L]就是答案--

	//--m表示字符串A的长度--
	for (int i = 1; i <= m; i++)   
	{
		//--L表示字符串B的长度--
		for (int j = 1; j <= L; j++) 
		{
			//--取dp[i-1][j]、dp[i][j-1]中的较大值--
			int MAX = max(dp[i - 1][j - 1], 
				max(dp[i - 1][j], dp[i][j - 1]));  // 为什么原模版中没有这一句？
												   // 原模版的更改是因为经典LCS模型的两个序列的
												   // 元素匹配必须是一一对应的，但本题中允许
												   // 公共部分产生重复元素，所以要修改一下

			if (A[i] == B[j]) 
			{
				dp[i][j] = MAX + 1;
			}

			else 
			{
				dp[i][j] = MAX;
			}
		}
	}

	//--输出答案--
	printf("%d\n", dp[m][L]);
	return 0;
}
