// B1042. 字符统计

//----------CODE---------

#include "C.h"

const int maxn = 1010;

//---定义一个char型数组，来存储字符串---
char str[maxn];

//---记录a(A)~z(Z)的出现次数---
int hashTable[30] = { 0 };


int main()
{
	//---输入字符串---
	gets_s(str);

	//---字符串长度---
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			hashTable[str[i] - 'a']++;  // 可以把hashTable的[]看成是一个大广场，里面啥都能放！
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			hashTable[str[i] - 'A']++;  // 因为hashTable是int型数组，所以(str[i]-'A')的结果是整数
										// 0 1 35啊这一类什么的
		}
	}

	int idMaxEle = 0;

	//---因为一共只有26个英文字母---
	for (int j = 0; j < 26; j++)
	{
		if (hashTable[j] > hashTable[idMaxEle])  // 在这里比较每个英文字母出现的次数
			idMaxEle = j;
	}

	//---idMaxEle最大不超过26---
	printf("%c %d", 'a' + idMaxEle, hashTable[idMaxEle]);

	return 0;
}