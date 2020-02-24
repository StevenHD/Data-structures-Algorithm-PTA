// A1040. Longest Symmetric String  ��Գ��ַ���

//----------CODE----------
#include "C.h"

const int maxn = 1010;

//---����һ���ַ����顣�ַ������С���ٿ���1001---
char S[maxn];

int dp[maxn][maxn];

int main() 
{
	gets_s(S);
	int len = strlen(S), ans = 1;

	//---dp�����ʼ��Ϊ0---
	memset(dp, 0, sizeof(dp));

	//--�߽�--
	for (int i = 0; i < len; i++) 
	{
		dp[i][i] = 1;

		if (i < len - 1) 
		{
			if (S[i] == S[i + 1]) 
			{
				dp[i][i + 1] = 1;

				//--��ʼ��ʱע�⵱ǰ������Ӵ��ĳ���--
				ans = 2;   // һ���Ӵ����и�aa���ͱ�ʾ����Ϊ2
			}
		}
	}


	//--״̬ת�Ʒ���--
	//-ö���Ӵ��ĳ���-
	for (int L = 3; L <= len; L++) 
	{
		//-ö���Ӵ�����ʼ�˵�-
		for (int i = 0; i + L - 1 < len; i++) 
		{
			//-�Ӵ����Ҷ˵�-
			int j = i + L - 1;

			if (S[i] == S[j] && dp[i + 1][j - 1] == 1)  // dp[i + 1][j - 1] == 1��ʾS[i]~S[j]�ǻ����Ӵ�
			{
				dp[i][j] = 1;

				//--����������Ӵ�����--
				ans = L;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
