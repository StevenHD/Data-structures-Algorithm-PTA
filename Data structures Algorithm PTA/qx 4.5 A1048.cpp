// A1048. Find Coins

#include "C.h"

int a[100010];

//---left��right�ĳ�ʼֵ�ֱ�Ϊ0��n-1��keyΪm-a[i]---
int Bin(int left, int right, int key) 
{
	int mid;
	while (left <= right) 
	{
		//--ȡleft��right���е�--
		mid = (left + right) / 2;

		//--����ҵ���key���򷵻��±�mid--
		if (a[mid] == key) 
			return mid;
		else if (a[mid] > key) 
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return -1;
}

int main() 
{
	int i, n, m;
	scanf("%d%d", &n, &m);


	for (i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}

	//---����---
	sort(a, a + n);

	for (i = 0; i < n; i++) 
	{
		//---Ѱ��m-a[i]---
		int pos = Bin(0, n - 1, m - a[i]);

		//---�ҵ���ƥ���a[i]��m-a[i]---
		if (pos != -1 && i != pos) 
		{
			printf("%d %d\n", a[i], a[pos]);

			//--��Ϊ����ж��ַ��������a��С��---
			//---���Դ�i=0��ʼ������з���������---
			//---�����ֱ��break�����ٵ���Ѱ�ҽ�---
			break;
		}
	}

	if (i == n) 
		printf("No Solution\n");

	return 0;
}
