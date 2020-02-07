// A1048. Find Coins
//------����------
// ����n����������һ��������m����n���������Ƿ����һ������a��b(a<=b)
// ʹ��a + b = m����������ж�ԣ����a��С����һ��a��b

//------˼·------
// ����ʹ��two pointers������
// STEP1����ʹ��sort���������д�С��������
// STEP2�����������±�i, j����ֵ�ֱ�Ϊ0��(n-1)��������a[i]+a[j]��M�Ĵ�С�����в���
//		  ���������i��j���������̣�
//		  1. ��a[i]+a[j]==M��������ҵ���һ�鷽�����˳�ѭ��
//		  2. ��a[i]+a[j]< M������i��1��Ҳ������ָ��i����һλ���ұ߸������
//		  3. ��a[i]+a[j]> M������j��1��Ҳ������ָ��j����һλ����߸�С����
// �������������Ľ��������� i >= j ���� ��������������a
// ����ʱ���� i >= j �Ƿ������ȷ�����Ƿ���ڡ�

//-----ע���------
// ����ж���𰸣�һ��Ҫ�����С����һ��(��ѭ��˳������)


//---------CODE----------

#include "C.h"

const int maxn = 100010;
int arrayOfCoins[maxn];

//------numsOfelementsΪԪ�ظ�����sumOfabΪ����ĺ�-------
void twoPointers(int numsOfelements, int sumOfab)
{
	int i = 0;
	int j = numsOfelements - 1;

	while (i < j)
	{
		// ����ҵ���a[i]��a[j]�ĺ�Ϊm���˳�ѭ��
		if (arrayOfCoins[i] + arrayOfCoins[j] == sumOfab)
			break;
		else if (arrayOfCoins[i] + arrayOfCoins[j] < sumOfab)
			i++;
		else
			j--;
	}

	if (i < j)
	{
		//--- i < j ˵���н� ---
		printf("%d %d\n", arrayOfCoins[i], arrayOfCoins[j]);
	}
	else
	{
		//--- i >= j ˵���޽� ---
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

//--------�����Լ����-------
// �������һ���ɵ����Ϊʲô i>=j ��ʱ�򣬾�˵���޽�
// ���ܻ�����ͬԪ�أ�����2����һ���ģ�������ֵһ�����±��ǲ�һ���ģ�ֻ�������ڰ���
// ���� 7 7 �������±�һ����˵��ͬһ��Ԫ�أ������Ͳ����������ˣ�������һ������a��b
// ����� i > j ���������ô�ͻ�����ظ����㣬֮ǰ��û��ƥ�䣬����Ҳ������ƥ�䣬����Ҳ���޽⡣

//--------�ĵ�----------
// ��ʹ��whileѭ����������while()ǰ�棬����� int i int j��Щ��ͬʱ������ֵ
// Ȼ����while(){}��body�ڽ���i++ j--��Щ�����ݼ�����
// Ҳ���Խ� i �� j �Ĵ�С�Ƚ���Ϊ if ���ж����������� if (i >= j) {...; printf(...);} ����