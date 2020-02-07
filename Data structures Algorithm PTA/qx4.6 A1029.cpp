// A1029. Median
//-----------题意---------
// 给出两个已经递增的序列S1和S2，长度分别为N和M
// 求将它们合并成一个新的递增序列后的中位数(个数为偶数时为左半部分的最后一个数)

//--------样例解释------------
// 两个序列合并后为{9, 10, 11, 12, 13, 14, 15, 16, 17}, 共9个数，因此第5个位置的13是中位数

//---------思路-----------
// STEP1：本题类似于之前说过的序列合并问题，区别是本题不用把整个合并后的序列输出，只需要输出中位数就行。
//		  由于在给定两个子序列的长度N和M后，新序列的长度长度(N+M)就是已知的，所以中位数位置为(N+M-1)/2
//		  注意，向下取整，之所以是(N+M-1)是因为序列下标从0开始，比如长度为8时应为3，长度为9时应为4
// STEP2：设置一个计数器count，计数器初始为0。表示当前已经获取到的新序列的位数。
//		  接下来就是类似“序列合并问题”中的做法，令两个下标i和j从两个序列的首位开始，
//		  不断比较S1[i]和S2[j]的大小：
//		  (1). 如果S1[i]<S2[j]，说明新序列的当前位应为S1[i]，因此令i加1
//		  (2). 否则，说明新序列的当前位应为S2[j]，因此令j加1
//		  按上面的步骤，每确定一个当前最小的数，就令count加1，直到count增长到中位数的位置
//		  也就是(N+M-1)/2时停止。此时，S1[i]和S2[j]中的较小值即为所求的中位数。

//------注意点--------
// C1：int类型的最大值为2^31 - 1，也就是0x7fffffff。这个最大值也可以写成(1<<31)-1。
// C2：为了使代码更加简练，可以令两个序列的最后都添加一个很大的数INF(本题为int类型的最大值)
//	   这样在two pointers的扫描过程中，就可以在其中一个序列已经扫描完
//	   但是count还没有到中位数的情况下解决 访问越界 的问题
// C3：最后需要选择S1[i]与S2[j]最小值输出的原因是，当count达到中位数的位置时
//	   在while循环中还没有对S2[j]和S1[i]的大小进行判断


//------------CODE--------------
#include "C.h"

//------序列最大长度------
const int maxn = 1000010;
//------int上限-------
const int INF = 0x7fffffff;
//------两个递增序列------
int ascendingSequence1[maxn];
int ascendingSequence2[maxn];

int main()
{
	int lengthOfAS1;
	scanf("%d", &lengthOfAS1);
	for (int i = 0; i < lengthOfAS1; i++)
	{
		//----输入第一个序列-----
		scanf("%d", &ascendingSequence1[i]);
	}

	int lengthOfAS2;
	scanf("%d", &lengthOfAS2);
	for (int j = 0; j < lengthOfAS2; j++)
	{
		//-----输入第二个序列-----
		scanf("%d", &ascendingSequence2[j]);
	}

	//-----两个序列的最后一个元素设为int上限------
	ascendingSequence1[lengthOfAS1] = INF; // 数组总长度是maxn
										   // INF是最后一个元素赋值大小的问题
	ascendingSequence2[lengthOfAS2] = INF; // 下标是从0开始的，不应该是(lengthOFAS-1)吗？

	//-----medianPos为中间位置------
	int medianPos = (lengthOfAS1 + lengthOfAS2 - 1) / 2;
	//-----count计数器用来计数当前的位置数-----
	int count = 0;
	int indexOfAS1 = 0;
	int indexOfAS2 = 0;
	//-----只要count未达到medianPos，就继续循环-----
	while (count < medianPos)
	{
		//---S1[i]更小，就选择S1[i]，反之亦然
		if (ascendingSequence1[indexOfAS1] < ascendingSequence2[indexOfAS2])
			indexOfAS1++;
		else
			indexOfAS2++;

		//---count加1---
		count++;
	}

	//-----输出两个序列当前位置较小的元素-----
	if (ascendingSequence1[indexOfAS1] < ascendingSequence2[indexOfAS2])
	{
		printf("%d\n", ascendingSequence1[indexOfAS1]);
	}
	else
	{
		printf("%d\n", ascendingSequence2[indexOfAS2]);
	}

	return 0;
}

//---------疑问以及解答--------
// 之前有一个问题，就是将AS[]数组中的最后一个元素AS[length]设为inf的问题
// 之所以下标是length而不是length-1, 是因为就是要让敲进去元素的后一个元素为inf
// 假如S1={3，4}，S2={5,9,10,15},当把S1的3 4扫描完后，还没到中位数5
// 但是因为定义的是全局数组，所以S1后面的元素都是0，那么这样就一直取S1的元素，还取的是0
// 还同时越界了，因为S1本来只有2个元素，现在超过了2个，所以给S1的第3个元素设为INF可以防止访问越界
// 这个道理用到S2也同样的！