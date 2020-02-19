// B1043. 输出PATest

#include "C.h"

const int maxn = 10010;

//---定义字符串和字典---

char str[maxn];
char dict[6] = { 'P', 'A', 'T', 'e', 's', 't' };

//---定义一个hashTable[]来记录PATest这6个字符的个数---
int hashTable[6] = { 0 };

int main()
{
	//---输入字符串---
	gets_s(str);

	//---定义长度len，sum则是来决定总共需要输出的字符个数---
	int len = strlen(str);
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		//---遍历dict字典---
		for (int j = 0; j < 6; j++)
		{
			//---str[i]在字典中的下标为j---
			/*if (str[i] = dict[j])*/ //应该输入两个等于号 ==
			if (str[i] == dict[j])
			{
				//---P A T e s t 分别对应了j中的 0 1 2 3 4 5---
				hashTable[j]++;

				//---不要忘了sum，sum的需要输出的字符的个数，记得符合情况的不断加1---
				sum++;
			}
		}
	}

	//---当输出的字符个数变成0时退出while循环---
	while (sum > 0)
	{
		//---遍历hash数组---
		for (int k = 0; k < 6; k++)
		{
			//---hashTable[0]就对应的是dict[0]就对应的是'P'---
			//---逻辑是这样，如果P的个数大于0，输出P，然后P的个数减1，总输出个数也减1---
			//---然后k++，就由P换成了A，以此类推---
			//---这样子就可以保证输出的字符顺序一定是PATest---
			//---for循环一次最多输出一串PATest---
			//---但是sum只要大于0，就会重新开始for循环，这样就不断输出PATestPATest这种---
			if (hashTable[k] > 0)
			{
				printf("%c", dict[k]);
				hashTable[k]--;
				sum--;
			}
		}
	}

	return 0;
}