// A1068. Find More Coins

//----------CODE----------

#include "C.h"

const int maxn = 10010;
const int maxv = 110;

//--w[i]ΪǮ�ҵļ�ֵ--
int w[maxn], dp[maxv] = { 0 };

//--bool������choice[i][v]��������¼����dp[i][v]��ѡ�����ĸ�����--
//--�����״̬ת��ʱѡ����dp[i-1][v]����ô��choice[i][v]=0��Ҳ���ǲ�����i����Ʒ��--
//--���ѡ����dp[i-1][v-w[i]]+c[i], ��ô��choice[i][v]=1(Ҳ���Ƿŵ�i����Ʒ)--
//---flag[i]==true��ʾ��i����Ʒ���뱳����false��ʾ�����뱳��---
bool choice[maxn][maxv], flag[maxn];

//--�Ӵ�С����--
bool cmp(int a, int b) 
{
	return a > b;
}

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) 
	{
		//--w[i]��ʾface values of the coins--
		scanf("%d", &w[i]);
	}

	//---��������---
	sort(w + 1, w + n + 1, cmp);

	for (int i = 1; i <= n; i++) 
	{
		for (int v = m; v >= w[i]; v--) 
		{
			//--������״̬ת�Ʒ���--
			//---����ʱҲҪ��---
			if (dp[v] <= dp[v - w[i]] + w[i]) 
			{
				dp[v] = dp[v - w[i]] + w[i];

				//---����dp[i][v]ʱ�����i����Ʒ---
				choice[i][v] = 1;
			}
			else 
				//---����dp[i][v]ʱѡ�񲻷����i����Ʒ---
				choice[i][v] = 0;
		}
	}


	//---�޽�---
	if (dp[m] != m) 
		printf("No Solution");

	else 
	{
		//---��¼����·��---
		//--k�ӵ�n����Ʒ��ʼö�٣�numΪ���뱳������Ʒ����--
		int k = n, num = 0;
		int v = m;              // v = m û̫��ʲô��˼��

		while (k >= 0) 
		{
			if (choice[k][v] == 1)
			{
				flag[k] = true;
				v -= w[k];
				num++;
			}

			else 
				flag[k] = false;

			k--;
		}
		
		//--�������--
		for (int i = n; i >= 1; i--) 
		{
			if (flag[i] == true) 
			{
				printf("%d", w[i]);
				num--;

				if (num > 0) 
					printf(" ");
			}
		}
	}

	return 0;
}
