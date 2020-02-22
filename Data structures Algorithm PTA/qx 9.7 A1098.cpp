// A1098. Insertion or Heap Sort 插入或堆排序
// 每次重复消耗一个输入元素，生成一个排序的输出列表

//---技巧---
// 如果目标序列最左边有递增的元素，则说明是 插入排序
// 如果目标序列最左边没有递增的元素，则说明不是 插入排序
// 这时观察目标序列最右边是否有连续递增的元素，如果有3个元素是连续递增的
// 那么说明目标序列是由3次堆调整得到的


//------CODE-------

#include "C.h"

const int N = 111;

//--原始数组，原始数组备份，目标数组--
int origin[N], tempOri[N], changed[N];    
int n;    // 元素个数


//--判断数组A和数组B是否相同--
bool isSame(int A[], int B[]) 
{    
	for (int i = 1; i <= n; i++) 
	{
		if (A[i] != B[i]) 
			return false;
	}
	return true;
}


//--输出数组--
void showArray(int A[]) 
{    
	for (int i = 1; i <= n; i++) 
	{
		printf("%d", A[i]);

		if (i < n) 
			printf(" ");
	}
	printf("\n");
}


//--插入排序--
bool insertSort() 
{    
	//--记录是否存在数组中间步骤与changed数组相同--
	bool flag = false;   
	for (int i = 2; i <= n; i++)                  // 为什么i从2开始？
												  // main()函数输入部分是从i=1开始的
	{    
		//--进行n-1趟排序--
		if (i != 2 && isSame(tempOri, changed)) 
		{
			//-中间步骤与目标相同，且不是初始序列-
			flag = true;    
		}

		//-插入部分直接用sort代替-
		//--在这里tempOri数组就改变了，也就是tempOri往前走了一步，变成了下一步将会产生的序列--
		sort(tempOri, tempOri + i + 1);            // 为什么这个排序的范围是(temp + i + 1)?

		if (flag == true) 
		{
			return true;    // 如果flag为true，则说明已达到目标数组，返回true
		}
	}
	return false;    // 无法达到目标数组，返回false
}


//--对heap数组在[low, high]范围进行调整--
//--其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标--

void downAdjust(int low, int high)  // [1, i-1]
{
	//--i为欲调整结点，j为其左孩子--
	int i = low, j = i * 2;         // 我记得完全二叉树中，结点编号为x的左孩子的编号也是2x 

	// 存在孩子结点
	// 如果右孩子存在，且右孩子的值大于左孩子
	while (j <= high) 
	{    
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j]) 
		{
			//-让j存储右孩子下标-
			j = j + 1;    
		}

		//--如果孩子中最大的权值比父亲大--
		if (tempOri[j] > tempOri[i]) 
		{
			swap(tempOri[j], tempOri[i]);      // 交换最大权值的孩子与父亲

			//--令i为j、令j为i的左孩子，进入下一层--
			i = j;                             
			j = i * 2;
		}

		else 
		{
			break;                             // 孩子的权值均比父亲小，调整结束
		}
	}
}


//--堆排序--
void heapSort() 
{    
	bool flag = false;                // flag表示是否存在数组中间步骤与changed数组相同
	for (int i = n / 2; i >= 1; i--) 
	{
		//--建堆--
		downAdjust(i, n);                // downAdjust的意思是 下调
	}

	for (int i = n; i > 1; i--) 
	{
		if (i != n && isSame(tempOri, changed)) 
		{
			flag = true;                 // 中间步骤与目标相同，且不是初始序列
										 // 因为初始序列是不参与比较是否与目标序列相同的
										 // 所以i!=n和上面的i!=2都表示比较的不是初始序列
		}

		//-交换heap[i]与堆顶-
		swap(tempOri[i], tempOri[1]);     // tempOri[i]就是heap[i]，tempOri[1]就是堆顶  
		downAdjust(1, i - 1);             // 调整堆顶

		if (flag == true) 
		{
			//--已达到目标数组，返回true--
			showArray(tempOri);    
			return;
		}
	}
}


int main() 
{
	//---n表示元素个数---
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		//-输入起始数组-
		scanf("%d", &origin[i]);  

		//--tempOri数组为备份，排序在tempOri上进行--
		tempOri[i] = origin[i];    
	}


	for (int i = 1; i <= n; i++) 
	{
		//--输入目标序列--
		scanf("%d", &changed[i]);    
	}

	//--如果插入排序中找到目标数组--
	if (insertSort()) 
	{    
		printf("Insertion Sort\n");
		showArray(tempOri);
	}

	else 
	{    // 到达此处时一定是堆排序
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++) 
		{
			tempOri[i] = origin[i];    // 还原tempOri数组
		}
		heapSort();    // 堆排序
	}

	return 0;
}
