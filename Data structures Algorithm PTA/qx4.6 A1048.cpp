// A1048. Find Coins
//------题意------
// 给出n个正整数和一个正整数m，问n个数字中是否存在一对数字a和b(a<=b)
// 使得a + b = m成立。如果有多对，输出a最小的那一对a和b

//------思路------
// 这题使用two pointers的做法
// STEP1：先使用sort函数将序列从小到大排序
// STEP2：定义两个下标i, j，初值分别为0和(n-1)，并根据a[i]+a[j]与M的大小来进行操作
//		  整体过程是i和j的相遇过程：
//		  1. 若a[i]+a[j]==M，则表明找到了一组方案，退出循环
//		  2. 若a[i]+a[j]< M，则令i加1，也就是让指标i右移一位到右边更大的数
//		  3. 若a[i]+a[j]> M，则令j减1，也就是让指标j左移一位到左边更小的数
// 上面两个操作的结束条件是 i >= j 或者 出现满足条件的a
// 结束时根据 i >= j 是否成立来确定解是否存在。

//-----注意点------
// 如果有多组答案，一定要输出最小的那一对(由循环顺序来定)


//---------CODE----------

#include "C.h"

const int maxn = 100010;
int arrayOfCoins[maxn];

//------numsOfelements为元素个数，sumOfab为所求的和-------
void twoPointers(int numsOfelements, int sumOfab)
{
	int i = 0;
	int j = numsOfelements - 1;

	while (i < j)
	{
		// 如果找到了a[i]和a[j]的和为m，退出循环
		if (arrayOfCoins[i] + arrayOfCoins[j] == sumOfab)
			break;
		else if (arrayOfCoins[i] + arrayOfCoins[j] < sumOfab)
			i++;
		else
			j--;
	}

	if (i < j)
	{
		//--- i < j 说明有解 ---
		printf("%d %d\n", arrayOfCoins[i], arrayOfCoins[j]);
	}
	else
	{
		//--- i >= j 说明无解 ---
		printf("No Solution!\n");
	}
}

int main()
{
	int N, sum;
	scanf("%d%d", &N, &sum);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arrayOfCoins[i]);
	}

	sort(arrayOfCoins, arrayOfCoins + N);
	twoPointers(N, sum);

	return 0;
}

//--------疑问以及解答-------
// 这个题有一个疑点就是为什么 i>=j 的时候，就说明无解
// 可能会有相同元素，比如2个是一样的，但是数值一样，下标是不一样的，只不过相邻罢了
// 比如 7 7 ，但是下标一样，说明同一个元素，这样就不符合题意了，题意是一对数字a和b
// 如果是 i > j 的情况，那么就会进行重复计算，之前都没有匹配，后面也不会再匹配，所以也是无解。

//--------心得----------
// 像使用while循环，就是在while()前面，定义好 int i int j这些，同时给定初值
// 然后在while(){}的body内进行i++ j--这些递增递减操作
// 也可以将 i 和 j 的大小比较作为 if 的判断条件，比如 if (i >= j) {...; printf(...);} 这种