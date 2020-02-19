// B1039/A1092  到底买不买

#include "C.h"

const int MAXN = 1010;

//---hashTable数组记录第一串中每种颜色的个数---
//---miss记录缺少的珠子个数---
int hashTable[80] = { 0 }; // 之所以定义成80是因为数字大小写字母一共62个，所以开个80的数组
int miss = 0;

// 将数字和字母转换为hashTable的下标
int change(char c) 
{
	if (c >= '0' && c <= '9') 
		return c - '0';    // 数字
	if (c >= 'a' && c <= 'z') 
		return c - 'a' + 10;    // 小写字母
	if (c >= 'A' && c <= 'Z') 
		return c - 'A' + 36;    // 大写字母
}

int main() 
{
	char whole[MAXN], target[MAXN];
	gets_s(whole);    // 第一串
	gets_s(target);    // 第二串

	int len1 = strlen(whole);    // 第一串长度
	int len2 = strlen(target);    // 第二串长度

	for (int i = 0; i < len1; i++) 
	{    //---遍历第一串---
		int id = change(whole[i]);    // 字符->hashTable下标
		hashTable[id]++;    // 该颜色个数加1
	}

	//---遍历第二串---
	for (int i = 0; i < len2; i++) 
	{    
		int id = change(target[i]);    // 字符->hashTable下标
		hashTable[id]--;    // 该颜色个数减1

		//--如果该颜色的个数小于0--
		if (hashTable[id] < 0) 
		{    
			miss++;    // 缺少的珠子个数加1
		}
	}

	if (miss > 0) 
		printf("No %d\n", miss);    // 有缺少
	else 
		printf("Yes %d\n", len1 - len2);    // 有富余

	return 0;
}
