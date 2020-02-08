// B1045/A1101 快速排序
// 随机选择算法

//------题意------
// 这个题只是以快速排序作为问题背景
// 本题输入一个序列，包含N个正整数，如果一个数左边的所有数都比它小，右边的所有数都比它大
// 那么称这个数为序列的一个“主元”。求序列中主元的个数。

//------样例解释------
//--------思路-------
// 直接暴力判断会超时
// 考虑大小的继承关系，假设序列为A，令数组leftMax记录序列A的每一位左边的最大数(不含本位，下同)
// 即leftMax[i]表示A[0]~A[i-1]的最大值，显然可以令leftMax[0]=0。
// 从左到右遍历序列A，由于leftMax[i-1]记录了A[0]~A[i-2]的最大值
// 因此如果A[i-1]比leftMax[i-1]大，说明leftMax[i]等于A[i-1]；
// 如果A[i-1]比leftMax[i-1]小，说明leftMax[i]等于leftMax[i-1]。

// 同样的思路，令数组rightMin记录序列A的每一位右边的最小数(不含本位)
// 即rightMin[i]表示A[i+1]~A[n-1]的最小值，显然可以令rightMin=INF(就是一个很大的数)
// 从右到左遍历序列A，由于rightMin[i+1]记录了A[i+2]~A[n-1]的最小值
// 因此如果A[i+1]比rightMin[i+1]小，说明rightMin[i]等于A[i+1]
// 如果A[i+1]比rightMin[i+1]大，说明rightMin[i]等于rightMin[i+1]

// 接下来就可以判断哪些是主元了。遍历序列A，如果leftMax[i]比A[i]小，而且rightMin[i]比A[i]大
// 那么就说明A[i]是主元。全部判断完毕后进行输出即可

//------注意点--------
// C1：直接暴力会超时
// C2：当主元个数为0时，第二行虽然没有输出主元，但必须有一个换行
// C3：这道题与B1040/A1093的思路很像，注意体会两道题的思想



//-------CODE-------
#include "C.h"

const int MAXN = 100010;
//---一个很大的数---
const int INF = 0x3fffffff;

//---sequence为序列，leftMax和rightMin就分别表示每一位左边最大的数和右边最小的数---
int sequence[MAXN];
int leftMax[MAXN];
int rightMin[MAXN];

//---allPrincipals记录所有主元，numsOfAP为主元个数
int allPrincipals[MAXN];
int numsOfAP = 0;

int main()
{
	//---序列元素个数---
	int numsOfSequence;
	scanf("%d", &numsOfSequence);

	//----输入序列元素----
	for (int i = 0; i < numsOfSequence; i++)
	{
		scanf("%d", &sequence[i]);
	}

	//---A[0]左边没有比它大的数---
	leftMax[0] = 0;
	for (int j = 1; j < numsOfSequence; j++)
	{
		// ---由j-1推得j---
		leftMax[j] = max(leftMax[j - 1], sequence[j - 1]);
	}

	//---A[n-1]右边没有比它小的数---
	rightMin[numsOfSequence - 1] = INF;
	for (int k = numsOfSequence - 2; k >= 0; k--)
	{
		// k>=0 是因为是从右到左遍历序列A的
		// 而且 这个 i 表示的就是 序列A 的每一位，就是A[i]

		//---由k+1推得k---
		rightMin[k] = min(rightMin[k + 1], sequence[k + 1]);
	}

	for (int m = 0; m < numsOfSequence; m++)
	{
		//---左边所有数比它小，右边所有数比它大---
		if (leftMax[m] < sequence[m] && rightMin[m] > sequence[m])
		{
			//---记录主元---
			allPrincipals[numsOfAP++] = sequence[m]; // 这个allPrincipals[numsOfAP++]的操作很秀
		}
	}

	//-----输出主元个数-----
	printf("%d\n", numsOfAP);
	for (int n = 0; n < numsOfAP; n++)
	{
		//---依次输出所有主元---
		printf("%d", allPrincipals[n]);

		if (n < numsOfAP - 1)
			printf(" ");
	}

	//---一定要有换行---
	printf("\n");
	return 0;  
}

//-------疑问以及解答-------
// return 0 和 return 有什么区别？ 
// return 表示理解结束函数调用，返回主调函数。即使这个函数是没要求返回值的。一般应用在void中
// 函数的执行，是操作系统调用。
// return 0;默认正确
// return -1默认错误的
// 不管默认是什么，最终都是执行函数后的返回值