// A1044. Shopping in Mars

//---�ص�---
// ʹ�ö��ַ���ǰ�ᣬ��Ե��������ϸ񵥵������ġ�

#include "C.h"

const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;


//---upper_bound�����ķ���ֵ��λ��---
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
	//---nΪԪ�ظ�����S��ʾ��ֵ---
	scanf("%d%d", &n, &S);
	sum[0] = 0;

	//---���forѭ����������sum[i]��---
	// S�����ֵ��ʾ����Ŀ�꣬sum[i]����Ҫ�ﵽ���Ŀ���һ�����ߡ�
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}


	//---ö����˵�---
	for (int i = 1; i <= n; i++) 
	{
		//---ͨ��ö����˵������Ҷ˵�---
		int j = upper_bound(i, n + 1, sum[i - 1] + S);

		//---���˵�����ҳɹ���ע����j-1������j��----
		if (sum[j - 1] - sum[i - 1] == S) 
		{
			//---��ӽ�S��ֵ����S---
			nearS = S;
			break;
		}

		//---���ڴ���S�ĽⲢС��nearS---
		else if (j <= n && sum[j] - sum[i - 1] < nearS) 
		{
			nearS = sum[j] - sum[i - 1];
		}
	}


	//---���ǵڶ��α���---
	//---�ڶ��α������ҵ���Щ��ֵǡ��ΪnearS�ķ��������---
	for (int i = 1; i <= n; i++) 
	{
		//--���Ҷ˵�--
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);

		//--���ҳɹ�--
		if (sum[j - 1] - sum[i - 1] == nearS) 
		{
			//--�����˵���Ҷ˵�--
			//--ע����j-1������j--
			printf("%d-%d\n", i, j - 1);
		}
	}

	return 0;
}
