// two pointers A1089 Insert or Merge
//-------题目描述--------
// 根据Wiki，
// 插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。
// 每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。
// 如此这般的迭代，知道全部元素有序。

// 归并排序进行如下迭代操作：首先将 原始序列 看作N个只包含一个元素的 有序子序列
// 然后每次迭代归并 两个相邻的有序子序列，直到最后只剩下一个 有序的序列
// 现有一个 原始序列 和 由排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

//---------题意------------
// 给出一个初始序列，可以将它使用IS和MS进行排序。
// 现在给出一个序列，问它是由插入排序还是归并排序产生的，并输出下一步将会产生的序列

//------样例解释----------
// 样例1：
// 第二个序列是第一个序列依次插入3、1、2、8、7后生成的序列，所以是插入排序
// 下一个序列为插入5后生成的序列，即1 2 3 5 7 8 9 4 6 0
// 样例2：
// 第一个序列执行归并排序的第一步，两两分组进行排序，即可得到第二个序列
// 因此是归并排序，下一个序列是四四分组进行排序的结果，即 1 2 3 8 4 5 7 9 0 6


//--------思路----------
// 本题需要直接模拟 插入排序 和 归并排序 的每一步过程，其中 归并排序 使用非递归形式会更方便。
// 整体做法为：先进行插入排序。如果执行过程中发现与给定序列吻合，那么说明是插入排序
// 确定是 插入排序 后，计算出下一步的序列后结束算法；
// 如果确定不是 插入排序 后，那么一定是 归并排序，模拟 归并排序 的过程
// 如果执行过程中发现与给定序列吻合，那么就计算出下一步的序列后结束算法。

//--------注意点---------
// C1：由于数据范围较小，所以 归并排序 中可以不写合并函数，而直接用sort代替
// C2：这里有一个trap：初始序列不参与是否与目标序列相同的比较，i.e. 
// 题目中说的中间序列是不包括初始序列的。
// 不考虑这个trap会导致某个数据产生双解，这个是什么意思？我没太懂。


//---------CODE-----------

#include "C.h"

const int numsOfPositiveInterger = 111;

int originArray[numsOfPositiveInterger];
int backupOfOriginArray[numsOfPositiveInterger];
int targetArray[numsOfPositiveInterger];
//----元素个数------
int numsOfElements;

//------判断数组A和数组B是否相同-------
bool isSame(int A[], int B[])
{
	for (int i = 0; i < numsOfElements; i++)
	{
		if (A[i] != B[i]) // 数组中每一个元素进行枚举比较
			return false;
	}
	return true;
}

//------输出数组---------
//---bool showArray(int C[])---
void showArray(int C[])
{
	for (int j = 0; j < numsOfElements; j++)
	{
		printf("%d", C[j]);
		if (j < numsOfElements - 1)
			printf(" ");
	}
	printf("\n");
}


//--------插入排序---------
bool insertSort()
{
	//-------记录是否存在数组中间步骤与targetArray相同--------
	bool flagOfIS = false;
	//---------进行n-1趟排序-----------
	for (int orderIndex = 1; orderIndex < numsOfElements; orderIndex++)
	{
		// IS的目标就是让原先的有序序列是[1,orderIndex-1]增加到[1,orderIndex]
		if (orderIndex != 1 && isSame(backupOfOriginArray, targetArray))
		{
			//-----中间步骤与目标数组相同，且不是初始序列------
			flagOfIS = true; //中间步骤就是backupOfOriginArray，orderIndex=1表示初始序列
		}

		//------以下为插入部分-------
		//------temp临时存放backupOfOriginArray[orderIndex]------
		//------l从k开始往前枚举-------

		//----------插入排序的输出讲解(p100~101)----------
		//---假设序列A中有6个元素A[1]~A[6]---
		//---令k从2到6枚举，进行(6-1)趟操作---
		//---假设某一趟时，序列A的前4个元素A[1]~A[4]已经有序(4就等于orderIndex-1)---
		//---然而，范围[5,6](=[orderIndex,n])还是无序的---
		//---那么，该趟就从范围[1, 4]中寻找一个位置idOfPosition，使得A[5](无序序列的第一个元素)插入位置idOfPosition(假设为2)后---
		//---范围[1,5]是有序的(之前是[1,4]为有序)---
		//---其中插入过程中，A[2]~A[4]会后移一位到A[3]~A[5]---
		//(对应A[idOfPosition]~A[orderIndex-1]后移一位到A[idOfPosition+1]~A[orderIndex])---
		//---这样，有序序列多了一个元素([1,4]变成[1,5])，无序序列少了一个元素([5,6]变为[6])

		int temp = backupOfOriginArray[orderIndex];
		int idOfPosition = orderIndex;

		while (idOfPosition > 0 && backupOfOriginArray[idOfPosition - 1] > temp)
		{
			// 把backupOfOriginArray[l-1]后移一位到b[l]
			backupOfOriginArray[idOfPosition] = backupOfOriginArray[idOfPosition - 1];
			idOfPosition--;
		}

		backupOfOriginArray[idOfPosition] = temp;
		if (flagOfIS == true)
		{
			//-----如果flag等于true，则说明已达到目标数组，返回true------
			return true;
		}
	}

	//------无法达到目标数组，则返回false--------
	return false;
}


//---------归并排序----------
void mergeSort()
{
	//------记录是否存在数组中间步骤与目标数组targerArray相同-------
	bool flagOfMS = false;

	//-----以下为归并排序部分------
	//------step为组内元素个数，step/2为左子区间元素个数，注意等号可以不取(？是因为不可能等于吗)--------
	for (int step = 2; step / 2 <= numsOfElements; step *= 2)
	{
		if (step != 2 && isSame(backupOfOriginArray, targetArray))
		{
			// 中间部分与目标数组相同；
			// 且 step != 2 表示不是初始序列
			flagOfMS = true;
		}

		//------每step个元素一组，组内[m, min(m+step, n)]进行排序------
		//------这种写法针对这道题，可以输出MS的某一趟结束的序列------
		// 这个[m, min(m+step, n)]中的min(m+step, n)没太懂。。。。
		for (int m = 0; m < numsOfElements; m += step)
		{
			sort(backupOfOriginArray + m, backupOfOriginArray + min(m + step, numsOfElements));
		}

		//----已到达目标数组，输出backup原始数组-----
		if (flagOfMS == true)
		{
			showArray(backupOfOriginArray);
			return; // 光一个return表示什么？
		}
	}
}


int main()
{
	scanf("%d", &numsOfElements);
	for (int i = 0; i < numsOfElements; i++)
	{
		//-----输入起始数组------
		scanf("%d", &originArray[i]);
		//----backup原始数组为备份，排序过程是在backup上进行的-----
		backupOfOriginArray[i] = originArray[i]; // 为什么要对数组进行备份呢？
	}

	for (int j = 0; j < numsOfElements; j++)
	{
		scanf("%d", &targetArray[j]);
	}

	//---------如果插入排序中找到了目标数组-----------
	if (insertSort())
	{
		printf("Insertion Sort\n");
		showArray(backupOfOriginArray);
	}
	else
	{
		//-----到达此处时一定是归并排序-------
		printf("Merge Sort\n");
		for (int k = 0; k < numsOfElements; k++)
		{
			//------还原back原始数组-------
			backupOfOriginArray[k] = originArray[k]; // 之所以要弄个备份的是因为，备份的在IS中会用到
													 // 如果在IS中没有验证成功，那么就要在MS中重新验证
													 // 但是这时候备份已经被污染了
													 // 这时候就用原始数组把备份重新还原就好
													 // 其实我感觉也可以一个用备份一个用原始
													 // 但是有点麻烦不是吗
		}

		//----归并排序------
		mergeSort();
	}
	return 0;
}

//-------------复习一下插入排序和归并排序-------------
// 先看看归并排序，归排和快排的核心思想都是 分治 的思想，代码通过 递归 来实现。
// 理解MS的重点是理解 递推公式 和 merge()合并函数
// 理解QS的重点是理解 递推公式 和 partition()分区函数
// MS是一种在任何情况下时度都比较稳定的排序算法，但是缺点也是MS不是原地排序算法，空度也高，为O(n)
// MS的核心思想：如果要用MS排序一个数组，我们要先把数组从中间分成前后两部分，
// 然后对前后两部分分别排序，再将排好序的两部分合并到一起(合并到一起的时候也要排序的哦)，这样整个数组就有序了
// 本次代码中关于MS使用的是2路归并排序，核心就是——如何将两个有序序列合并为一个有序序列。

//---------------序列合并问题----------------
// 那么我们来看看序列合并问题，比如说现在有两个递增序列A和B，要求把这俩合并为一个递增序列C
// 为了解决这个问题，我们可以设置两个下标i和j，初值均为0，i表示指向序列A的第一个元素，j则是指向序列B的第一个元素
// 然后根据A[i]和B[j]的大小来决定哪一个放入序列C：
// 如果A[i]<B[j]，把A[i]加入序列C中，并让i加1(也就是i右移一位)
// 如果A[i]>B[j]，把B[j]加入序列C中，并让j加1(也就是j右移一位)
// 如果A[i]==B[j]，则任意选一个加入到序列C中，并让对应的下标i或j加1
// 上述操作的结束标志是：直到i、j中的一个到达序列末端为止，然后将另一个序列的所有剩余元素依次加入到序列C中
// 最后return返回序列C的长度

//----------------MS的非递归实现--------------
// 2-路归并排序的非递归实现主要考虑这样一点：每次分组时，组内元素个数上限都是2^n,也就是2的幂次
// 所以思路是这样：令步长step的初值为2，然后将数组中每step个元素作为一组，对组内部进行排序
// 也就是每一组都是从左往右数，左step/2个元素与右step/2个元素合并，如果元素个数小于step/2，不操作
// 然后再令step乘以2，重复上面的操作
// 直到 ***step/2*** 个元素超过元素总个数n，因为加入元素个数是N，那么2^x=N,或者最趋近于N，x就是一共要搞几趟(假如8个数)
// 然后之所以是***step/2***，是因为超过元素个数时，step=2^(x+1)，所以超过了n就代表趟数走够了