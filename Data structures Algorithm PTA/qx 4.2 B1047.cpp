// B1047. ���������

//--------CODE--------

#include "C.h"

const int maxn = 1010;
//---�����ϣ���飬���洢ÿ��������ܷ�---
int hashTable[1001] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int teamID, testeeID, score;
		scanf("%d-%d %d", &teamID, &testeeID, &score);

		//---����ΪteamID�Ķ�����ܷ�������score---
		hashTable[teamID] += score;
	}

	int maxTeam, maxScore = -1;

	//---����j��1010�У�Ѱ��hashTable��������ֵ---
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