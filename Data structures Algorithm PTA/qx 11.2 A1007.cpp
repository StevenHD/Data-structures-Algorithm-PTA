// A1007. Maximum Subsequence Sum  ��������к�

//------CODE------

#include "C.h"

const int maxn = 10010;

//--a[i]������У�dp[i]�����a[i]��β���������е�����--
int a[maxn], dp[maxn];

//--s[i]��ʾ����dp[i]���������д�a����һ��Ԫ�ؿ�ʼ--
int s[maxn] = { 0 };

int main() 
{
	int n;
	scanf("%d", &n);

	//--flag��ʾ����a[]���Ƿ�ȫС��0--
	bool flag = false;
	for (int i = 0; i < n; i++) 
	{
		//--��������--
		scanf("%d", &a[i]);

		if (a[i] >= 0) 
			flag = true;
	}

	if (flag == false) 
	{
		//--���a[]���������ֶ�С��0�������0�Լ���βԪ��--
		printf("0 %d %d\n", a[0], a[n - 1]);
		return 0;
	}

	//--�Ƚ����趨�߽磬dp[0]=a[0]����Ϊֻ������޷�ͨ��ǰ���Ԫ�صõ�(ǰ��û��Ԫ��)--
	//---�߽�---
	dp[0] = a[0];

	for (int i = 1; i < n; i++)              // ������ϱ߲�ͬ��i�Ǵ�1��ʼ�ģ������Ǵ�0��ʼ��
	{
		//--״̬ת�Ʒ���--
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

	//--��Ϊdp[i]��ŵ�����a[i]��β���������е�����--
	//--������Ҫ����i�õ����Ĳ��ǽ��--
	int k = 0;
	for (int i = 1; i < n; i++)                       // ����iҲ�Ǵ�1��ʼ��
	{
		if (dp[i] > dp[k]) 
		{
			k = i;
		}
	}
	printf("%d %d %d\n", dp[k], a[s[k]], a[k]);       // s[k]��ŵ����±�
	return 0;
}
