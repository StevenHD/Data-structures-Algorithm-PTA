// B1038. 统计同成绩学生

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

		if (j < k - 1) // 因为k-1就是最后一个要输出的元素，它的后面没有空格了
					   // 所以最后只要 k-2 输出空格就好
		{
			printf(" ");
		}
	}

	return 0;
}