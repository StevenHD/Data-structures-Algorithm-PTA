// A1068. Find More Coins

//----------CODE----------

#include "C.h"

const int maxn = 10010;
const int maxv = 110;

//--w[i]为钱币的价值--
int w[maxn], dp[maxv] = { 0 };

//--bool型数组choice[i][v]，用来记录计算dp[i][v]是选择了哪个策略--
//--如果在状态转移时选择了dp[i-1][v]，那么记choice[i][v]=0（也就是不妨第i件物品）--
//--如果选择了dp[i-1][v-w[i]]+c[i], 那么记choice[i][v]=1(也就是放第i件物品)--
//---flag[i]==true表示第i件物品放入背包，false表示不放入背包---
bool choice[maxn][maxv], flag[maxn];

//--从大到小排序--
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
		//--w[i]表示face values of the coins--
		scanf("%d", &w[i]);
	}

	//---逆序排列---
	sort(w + 1, w + n + 1, cmp);

	for (int i = 1; i <= n; i++) 
	{
		for (int v = m; v >= w[i]; v--) 
		{
			//--以下是状态转移方程--
			//---等于时也要放---
			if (dp[v] <= dp[v - w[i]] + w[i]) 
			{
				dp[v] = dp[v - w[i]] + w[i];

				//---计算dp[i][v]时放入第i件物品---
				choice[i][v] = 1;
			}
			else 
				//---计算dp[i][v]时选择不放入第i件物品---
				choice[i][v] = 0;
		}
	}


	//---无解---
	if (dp[m] != m) 
		printf("No Solution");

	else 
	{
		//---记录最优路径---
		//--k从第n件物品开始枚举，num为放入背包的物品件数--
		int k = n, num = 0;
		int v = m;              // v = m 没太懂什么意思？

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
		
		//--输出方案--
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
