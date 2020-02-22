// A1064. Complete Binary Search Tree

//--------CODE---------

#include "C.h"

const int maxn = 1010;

//---nΪ������---
int n;

//--number[]����������Ž��Ȩֵ--
//--CBT[]�������������ȫ������--
int number[maxn], CBT[maxn];

//--index��С����ö��number[]����--
int index = 0;

//--�������--
void inOrder(int root) 
{
	//--��ȫ����������ս��ı�־����ǰ���root�ı�Ŵ��ڽ�����n--
	//---����(root > n)�ս�㣬ֱ��return����---
	if (root > n) 
		return;

	//--���������ݹ�--
	//--���ʹ�������������ȫ����������ô����ȫ���������е��κ�һ�����(����Ϊx�����и������Ϊ1)--
	//--�����ӽ��ı��һ����2x�����Һ��ӽ��ı��һ����2x+1
	inOrder(root * 2);

	//---��һ������CBT[maxn]������CBT[1]~CBT[n]����������ȫ��������n�����--
	//--����㴦��ֵnumber[index]--
	CBT[root] = number[index++];

	//---���������ݹ�---
	inOrder(root * 2 + 1);  // root���ǽ����
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &number[i]);  // �����������ľ���ÿһ������Ȩֵ
	}

	//--��С��������--
	sort(number, number + n);

	//--1��λΪ�����--
	inOrder(1);                    // ��ȫ�������ĸ������Ϊ1


	for (int i = 1; i <= n; i++) 
	{
		//---CBT[]���鱾����ǲ���---
		printf("%d", CBT[i]);

		if (i < n) 
			printf(" ");
	}

	return 0;
}
