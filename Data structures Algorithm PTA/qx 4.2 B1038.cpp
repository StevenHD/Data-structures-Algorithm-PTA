// B1038. ͳ��ͬ�ɼ�ѧ��

#include "C.h"

int hashTable[110] = { 0 };

int main()
{
	int n, score, k;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score);
		hashTable[score]++;
	}

	scanf("%d", &k);

	for (int j = 0; j < k; j++)
	{
		scanf("%d", &score);
		printf("%d", hashTable[score]);

		if (j < k - 1) // ��Ϊk-1�������һ��Ҫ�����Ԫ�أ����ĺ���û�пո���
					   // �������ֻҪ k-2 ����ո�ͺ�
		{
			printf(" ");
		}
	}

	return 0;
}