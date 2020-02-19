// B1033. 旧键盘打字

//---------CODE---------

#include "C.h"
const int maxn = 100010;

//---hashTable为散列数组，用来记录键盘上的字符是否完好---
bool hashTable[256];
char str[maxn];

int main() 
{
	//---赋值操作，true表示所有键都完好---
	memset(hashTable, true, sizeof(hashTable));

	//---读入所有失效的键位---
	gets_s(str);
	int len = strlen(str);

	for (int i = 0; i < len; i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			//---将大写字母都转换成小写字母---
			str[i] = str[i] - 'A' + 'a';
		}

		//---因为hashTable是char型的，所以str[i]应该也是char型字符，不过都是小写a b c d---
		hashTable[str[i]] = false;  // 怎么感觉这个str[i]在hashTable里面显示的是整数？
	}

	//---读入欲输入的字符串---
	//---这个str和上面呢个不一样---
	gets_s(str);
	len = strlen(str);

	for (int i = 0; i < len; i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			//---如果是大写字母，则化为小写字母---
			int low = str[i] - 'A' + 'a';  // low是int型变量，所以low应该是整数
			if (hashTable[low] == true && hashTable['+'] == true) 
			{
				printf("%c", str[i]);
			}
		}
		else if (hashTable[str[i]] == true) 
		{
			printf("%c", str[i]);
		}
	}
	printf("\n");
	return 0;
}


//------答疑-------
// hashTable[]中的都是整数，从0开始
// hashTable[0] hT[1]这些
// str[i]的类型是char，但是值都是43'+'这种，后面带字符。
// 但我感觉传入ht中时，是整数形式。
// 那看来char型数组，也可以存放整数？

// 我调试了一下，hashTable[55]=false,hashTable[56]=true
// 所以猜测是对的，至于str[i]=43'+'这种，可能只是呢样写的吧
// 最后hashTable[str[i]]中传进去的还是hashTable[43]