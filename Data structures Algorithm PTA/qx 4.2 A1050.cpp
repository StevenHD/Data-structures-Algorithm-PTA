// A1050. String Subtraction

//----------CODE----------

#include "C.h"

const int MAX_LEN = 10005;

//---a和b分别是S1和S2---
//---一直以为会用string来定义字符串---
//---也许因为下面要枚举字符串中的每个字符---
//---所以用了char型数组来代替字符串---
char a[MAX_LEN], b[MAX_LEN];

//---记录字符是否在第二个字符串里出现过---
bool HashTable[128];

int main() 
{
	gets_s(a);
	gets_s(b);

	//---为了降低时间复杂度，strlen必须在for循环之前就计算---
	int lenA = strlen(a);
	int lenB = strlen(b);

	//---将第二个字符串中的每一个字符的hash值均置为true---
	for (int i = 0; i < lenB; i++)
	{
		HashTable[b[i]] = true;
	}

	//---枚举第一个字符串中的每个字符---
	for (int i = 0; i < lenA; i++) 
	{
		//---如果这些字符中，有的字符没有在第二个S2中出现过的，就输出---
		if (HashTable[a[i]] == false) 
		{
			printf("%c", a[i]);
		}
	}

	return 0;
}
