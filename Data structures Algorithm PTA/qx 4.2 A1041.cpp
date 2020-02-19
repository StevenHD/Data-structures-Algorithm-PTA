// A1041. Be Unique

//-------------CDOE--------------

#include "C.h"

//---a[]Ϊ��������֣�hashTable[]Ϊɢ������---
int a[100001];
int HashTable[10001] = { 0 };

int main() 
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		//---��ǰ�������Ϊa[i]---
		scanf("%d", &a[i]);

		//---����a[i]���ֵĴ�����1---
		HashTable[a[i]]++;
	}

	//---����ans�Ǵ�ŵ�һ�γ��ֵ���������ֻ��һ��������---
	int ans = -1;
	for (int i = 0; i < n; i++) 
	{
		//---hashTable[a[i]]���Ϊ1��˵��a[i]ֻ������һ��---
		if (HashTable[a[i]] == 1) 
		{
			//---��ô�𰸾���a[i]��ֱ���˳�forѭ��---
			ans = a[i];
			break;
		}
	}

	//---ansΪ-1˵���Ҳ���ֻ������һ�ε����֣����"None"---
	if (ans == -1) 
		printf("None");
	else 
		printf("%d\n", ans);

	return 0;
}
