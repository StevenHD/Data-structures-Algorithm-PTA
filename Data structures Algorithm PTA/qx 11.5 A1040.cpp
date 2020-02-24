// A1040. Longest Symmetric String  最长对称字符串

//----------CODE----------
#include "C.h"

const int maxn = 1010;

//---定义一个字符数组。字符数组大小至少开成1001---
char S[maxn];

int dp[maxn][maxn];

int main() 
{
	gets_s(S);
	int len = strlen(S), ans = 1;

	//---dp数组初始化为0---
	memset(dp, 0, sizeof(dp));

	//--边界--
	for (int i = 0; i < len; i++) 
	{
		dp[i][i] = 1;

		if (i < len - 1) 
		{
			if (S[i] == S[i + 1]) 
			{
				dp[i][i + 1] = 1;

				//--初始化时注意当前最长回文子串的长度--
				ans = 2;   // 一个子串中有个aa，就表示长度为2
			}
		}
	}


	//--状态转移方程--
	//-枚举子串的长度-
	for (int L = 3; L <= len; L++) 
	{
		//-枚举子串的起始端点-
		for (int i = 0; i + L - 1 < len; i++) 
		{
			//-子串的右端点-
			int j = i + L - 1;

			if (S[i] == S[j] && dp[i + 1][j - 1] == 1)  // dp[i + 1][j - 1] == 1表示S[i]~S[j]是回文子串
			{
				dp[i][j] = 1;

				//--更新最长回文子串长度--
				ans = L;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
