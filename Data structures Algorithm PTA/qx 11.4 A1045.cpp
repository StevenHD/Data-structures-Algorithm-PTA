// A1045. Favorite Color Stripe
// ʹ�������������LCS

#include "C.h"

//--maxcΪ��ɫ�������������maxnΪ��ɫ���е���󳤶�--
const int maxc = 210;
const int maxn = 10010;

int A[maxc], B[maxn], dp[maxc][maxn];

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);

	//---��������A---
	for (int i = 1; i <= m; i++) 
	{
		scanf("%d", &A[i]);      // ����A����ϲ������ɫ���������С�������2 3 1 5 6
	}

	int L;
	scanf("%d", &L);

	//---��������B---
	for (int i = 1; i <= L; i++) // ���� L = 12
	{
		scanf("%d", &B[i]);      // ����B���Ǹ������������С�������2 2 4 1 5 5 6 3 1 1 5 6
	}

	//--�߽�--
	for (int i = 0; i <= m; i++) 
	{
		dp[i][0] = 0;
	}

	for (int j = 0; j <= L; j++) 
	{
		dp[0][j] = 0;
	}

	//---״̬ת�Ʒ���---
	//--���յ�dp[m][L]���Ǵ�--

	//--m��ʾ�ַ���A�ĳ���--
	for (int i = 1; i <= m; i++)   
	{
		//--L��ʾ�ַ���B�ĳ���--
		for (int j = 1; j <= L; j++) 
		{
			//--ȡdp[i-1][j]��dp[i][j-1]�еĽϴ�ֵ--
			int MAX = max(dp[i - 1][j - 1], 
				max(dp[i - 1][j], dp[i][j - 1]));  // Ϊʲôԭģ����û����һ�䣿
												   // ԭģ��ĸ�������Ϊ����LCSģ�͵��������е�
												   // Ԫ��ƥ�������һһ��Ӧ�ģ�������������
												   // �������ֲ����ظ�Ԫ�أ�����Ҫ�޸�һ��

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

	//--�����--
	printf("%d\n", dp[m][L]);
	return 0;
}
