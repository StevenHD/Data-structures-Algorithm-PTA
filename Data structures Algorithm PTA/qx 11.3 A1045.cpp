// A1045. Favorite Color Stripe  最喜欢的彩色条纹

//----------CODE----------

#include "C.h"

//---最大颜色数---
const int maxc = 210;

//--最大L--
const int maxn = 10010;

//---将喜欢的颜色序列映射为递增序列，不喜欢的颜色映射为-1---
int HashTable[maxc];

//---最长不下降子序列的原数组A和DP数组---
int A[maxn], dp[maxn];


int main() 
{
	int n, m, x;
	scanf("%d%d", &n, &m);

	//--整个HashTable数组初始化为-1--
	memset(HashTable, -1, sizeof(HashTable));

	//--m表示喜欢的颜色个数下标--
	//--比如一共5个颜色，m就是0 1 2 3 4--
	for (int i = 0; i < m; i++) 
	{
		//--x表示最喜欢的颜色对应的数字，这里显示为2 3 1 5 6--
		scanf("%d", &x);

		//---将喜欢的颜色按顺序映射到递增序列0 1 2 ... m-1---
		HashTable[x] = i;
	}


	//--num存放颜色序列中，Eva喜欢的颜色的总数--
	//--L表示给定的原序列长度--
	int L, num = 0;
	scanf("%d", &L);                   // 这里L表示12

	for (int i = 0; i < L; i++) 
	{
		scanf("%d", &x);
		if (HashTable[x] >= 0) 
		{
			//--如果是喜欢的颜色--
			//--加入到A数组中--
			A[num++] = HashTable[x];   // num和A[]的概念还不是很清楚？
									   // A[]是给定的stripe序列中颜色是Eva最喜欢
									   // 的颜色对应的Hash值
									   // Hash值的大小也是按scanf输入顺序来定的
									   // A[0]=0,A[1]=0,A[2]=2,A[3]=3,A[4]=3,A[5]=4
									   // A[6]=1,A[7]=2,A[8]=2,A[9]=3,A[10]=4
									   // 因为原序列长度是12，里面对应的颜色有最喜欢颜色只有
									   // 11个，所以A[]的长度是11，也就是num的大小
									   // A[]数组存储的就是每个喜欢颜色对应的Hash值
		}
	}


	//---以下为LIS的模板---
	
	//--记录最大的dp[i]--
	int ans = -1;  

	//--按顺序计算出dp[i]的值--
	for (int i = 0; i < num; i++) 
	{
		//--边界初始条件(即先假设每个元素都自成一个序列)--
		dp[i] = 1;
		for (int j = 0; j < i; j++) 
		{
			if (A[j] <= A[i] && dp[i] < dp[j] + 1) 
			{
				//--状态转移方程，用以更新dp[i]--
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
