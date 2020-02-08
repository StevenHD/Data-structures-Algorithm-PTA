// B1045/A1101 ��������
// ���ѡ���㷨

//------����------
// �����ֻ���Կ���������Ϊ���ⱳ��
// ��������һ�����У�����N�������������һ������ߵ�������������С���ұߵ���������������
// ��ô�������Ϊ���е�һ������Ԫ��������������Ԫ�ĸ�����

//------��������------
//--------˼·-------
// ֱ�ӱ����жϻᳬʱ
// ���Ǵ�С�ļ̳й�ϵ����������ΪA��������leftMax��¼����A��ÿһλ��ߵ������(������λ����ͬ)
// ��leftMax[i]��ʾA[0]~A[i-1]�����ֵ����Ȼ������leftMax[0]=0��
// �����ұ�������A������leftMax[i-1]��¼��A[0]~A[i-2]�����ֵ
// ������A[i-1]��leftMax[i-1]��˵��leftMax[i]����A[i-1]��
// ���A[i-1]��leftMax[i-1]С��˵��leftMax[i]����leftMax[i-1]��

// ͬ����˼·��������rightMin��¼����A��ÿһλ�ұߵ���С��(������λ)
// ��rightMin[i]��ʾA[i+1]~A[n-1]����Сֵ����Ȼ������rightMin=INF(����һ���ܴ����)
// ���ҵ����������A������rightMin[i+1]��¼��A[i+2]~A[n-1]����Сֵ
// ������A[i+1]��rightMin[i+1]С��˵��rightMin[i]����A[i+1]
// ���A[i+1]��rightMin[i+1]��˵��rightMin[i]����rightMin[i+1]

// �������Ϳ����ж���Щ����Ԫ�ˡ���������A�����leftMax[i]��A[i]С������rightMin[i]��A[i]��
// ��ô��˵��A[i]����Ԫ��ȫ���ж���Ϻ�����������

//------ע���--------
// C1��ֱ�ӱ����ᳬʱ
// C2������Ԫ����Ϊ0ʱ���ڶ�����Ȼû�������Ԫ����������һ������
// C3���������B1040/A1093��˼·����ע������������˼��



//-------CODE-------
#include "C.h"

const int MAXN = 100010;
//---һ���ܴ����---
const int INF = 0x3fffffff;

//---sequenceΪ���У�leftMax��rightMin�ͷֱ��ʾÿһλ������������ұ���С����---
int sequence[MAXN];
int leftMax[MAXN];
int rightMin[MAXN];

//---allPrincipals��¼������Ԫ��numsOfAPΪ��Ԫ����
int allPrincipals[MAXN];
int numsOfAP = 0;

int main()
{
	//---����Ԫ�ظ���---
	int numsOfSequence;
	scanf("%d", &numsOfSequence);

	//----��������Ԫ��----
	for (int i = 0; i < numsOfSequence; i++)
	{
		scanf("%d", &sequence[i]);
	}

	//---A[0]���û�б��������---
	leftMax[0] = 0;
	for (int j = 1; j < numsOfSequence; j++)
	{
		// ---��j-1�Ƶ�j---
		leftMax[j] = max(leftMax[j - 1], sequence[j - 1]);
	}

	//---A[n-1]�ұ�û�б���С����---
	rightMin[numsOfSequence - 1] = INF;
	for (int k = numsOfSequence - 2; k >= 0; k--)
	{
		// k>=0 ����Ϊ�Ǵ��ҵ����������A��
		// ���� ��� i ��ʾ�ľ��� ����A ��ÿһλ������A[i]

		//---��k+1�Ƶ�k---
		rightMin[k] = min(rightMin[k + 1], sequence[k + 1]);
	}

	for (int m = 0; m < numsOfSequence; m++)
	{
		//---�������������С���ұ�������������---
		if (leftMax[m] < sequence[m] && rightMin[m] > sequence[m])
		{
			//---��¼��Ԫ---
			allPrincipals[numsOfAP++] = sequence[m]; // ���allPrincipals[numsOfAP++]�Ĳ�������
		}
	}

	//-----�����Ԫ����-----
	printf("%d\n", numsOfAP);
	for (int n = 0; n < numsOfAP; n++)
	{
		//---�������������Ԫ---
		printf("%d", allPrincipals[n]);

		if (n < numsOfAP - 1)
			printf(" ");
	}

	//---һ��Ҫ�л���---
	printf("\n");
	return 0;  
}

//-------�����Լ����-------
// return 0 �� return ��ʲô���� 
// return ��ʾ�������������ã�����������������ʹ���������ûҪ�󷵻�ֵ�ġ�һ��Ӧ����void��
// ������ִ�У��ǲ���ϵͳ���á�
// return 0;Ĭ����ȷ
// return -1Ĭ�ϴ����
// ����Ĭ����ʲô�����ն���ִ�к�����ķ���ֵ