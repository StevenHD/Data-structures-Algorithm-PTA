// A1098. Insertion or Heap Sort ����������
// ÿ���ظ�����һ������Ԫ�أ�����һ�����������б�

//---����---
// ���Ŀ������������е�����Ԫ�أ���˵���� ��������
// ���Ŀ�����������û�е�����Ԫ�أ���˵������ ��������
// ��ʱ�۲�Ŀ���������ұ��Ƿ�������������Ԫ�أ������3��Ԫ��������������
// ��ô˵��Ŀ����������3�ζѵ����õ���


//------CODE-------

#include "C.h"

const int N = 111;

//--ԭʼ���飬ԭʼ���鱸�ݣ�Ŀ������--
int origin[N], tempOri[N], changed[N];    
int n;    // Ԫ�ظ���


//--�ж�����A������B�Ƿ���ͬ--
bool isSame(int A[], int B[]) 
{    
	for (int i = 1; i <= n; i++) 
	{
		if (A[i] != B[i]) 
			return false;
	}
	return true;
}


//--�������--
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


//--��������--
bool insertSort() 
{    
	//--��¼�Ƿ���������м䲽����changed������ͬ--
	bool flag = false;   
	for (int i = 2; i <= n; i++)                  // Ϊʲôi��2��ʼ��
												  // main()�������벿���Ǵ�i=1��ʼ��
	{    
		//--����n-1������--
		if (i != 2 && isSame(tempOri, changed)) 
		{
			//-�м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ����-
			flag = true;    
		}

		//-���벿��ֱ����sort����-
		//--������tempOri����͸ı��ˣ�Ҳ����tempOri��ǰ����һ�����������һ���������������--
		sort(tempOri, tempOri + i + 1);            // Ϊʲô�������ķ�Χ��(temp + i + 1)?

		if (flag == true) 
		{
			return true;    // ���flagΪtrue����˵���ѴﵽĿ�����飬����true
		}
	}
	return false;    // �޷��ﵽĿ�����飬����false
}


//--��heap������[low, high]��Χ���е���--
//--����lowΪ���������������±꣬highһ��Ϊ�ѵ����һ��Ԫ�ص������±�--

void downAdjust(int low, int high)  // [1, i-1]
{
	//--iΪ��������㣬jΪ������--
	int i = low, j = i * 2;         // �Ҽǵ���ȫ�������У������Ϊx�����ӵı��Ҳ��2x 

	// ���ں��ӽ��
	// ����Һ��Ӵ��ڣ����Һ��ӵ�ֵ��������
	while (j <= high) 
	{    
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j]) 
		{
			//-��j�洢�Һ����±�-
			j = j + 1;    
		}

		//--�������������Ȩֵ�ȸ��״�--
		if (tempOri[j] > tempOri[i]) 
		{
			swap(tempOri[j], tempOri[i]);      // �������Ȩֵ�ĺ����븸��

			//--��iΪj����jΪi�����ӣ�������һ��--
			i = j;                             
			j = i * 2;
		}

		else 
		{
			break;                             // ���ӵ�Ȩֵ���ȸ���С����������
		}
	}
}


//--������--
void heapSort() 
{    
	bool flag = false;                // flag��ʾ�Ƿ���������м䲽����changed������ͬ
	for (int i = n / 2; i >= 1; i--) 
	{
		//--����--
		downAdjust(i, n);                // downAdjust����˼�� �µ�
	}

	for (int i = n; i > 1; i--) 
	{
		if (i != n && isSame(tempOri, changed)) 
		{
			flag = true;                 // �м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ����
										 // ��Ϊ��ʼ�����ǲ�����Ƚ��Ƿ���Ŀ��������ͬ��
										 // ����i!=n�������i!=2����ʾ�ȽϵĲ��ǳ�ʼ����
		}

		//-����heap[i]��Ѷ�-
		swap(tempOri[i], tempOri[1]);     // tempOri[i]����heap[i]��tempOri[1]���ǶѶ�  
		downAdjust(1, i - 1);             // �����Ѷ�

		if (flag == true) 
		{
			//--�ѴﵽĿ�����飬����true--
			showArray(tempOri);    
			return;
		}
	}
}


int main() 
{
	//---n��ʾԪ�ظ���---
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		//-������ʼ����-
		scanf("%d", &origin[i]);  

		//--tempOri����Ϊ���ݣ�������tempOri�Ͻ���--
		tempOri[i] = origin[i];    
	}


	for (int i = 1; i <= n; i++) 
	{
		//--����Ŀ������--
		scanf("%d", &changed[i]);    
	}

	//--��������������ҵ�Ŀ������--
	if (insertSort()) 
	{    
		printf("Insertion Sort\n");
		showArray(tempOri);
	}

	else 
	{    // ����˴�ʱһ���Ƕ�����
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++) 
		{
			tempOri[i] = origin[i];    // ��ԭtempOri����
		}
		heapSort();    // ������
	}

	return 0;
}
