// B1047. 编程团体赛

//--------CODE--------

#include "C.h"

const int maxn = 1010;
//---定义哈希数组，来存储每个队伍的总分---
int hashTable[1001] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int teamID, testeeID, score;
		scanf("%d-%d %d", &teamID, &testeeID, &score);

		//---令编号为teamID的队伍的总分数加上score---
		hashTable[teamID] += score;
	}

	int maxTeam, maxScore = -1;

	//---遍历j在1010中，寻找hashTable数组的最大值---
	for (int j = 0; j < maxn; j++)
	{
		if (hashTable[j] > maxScore)
		{
			maxScore = hashTable[j];
			maxTeam = j;
		}
	}

	printf("%d %d", maxTeam, maxScore);
	return 0;
}