// B1042. �ַ�ͳ��

//----------CODE---------

#include "C.h"

const int maxn = 1010;

//---����һ��char�����飬���洢�ַ���---
char str[maxn];

//---��¼a(A)~z(Z)�ĳ��ִ���---
int hashTable[30] = { 0 };


int main()
{
	//---�����ַ���---
	gets_s(str);

	//---�ַ�������---
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			hashTable[str[i] - 'a']++;  // ���԰�hashTable��[]������һ����㳡������ɶ���ܷţ�
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			hashTable[str[i] - 'A']++;  // ��ΪhashTable��int�����飬����(str[i]-'A')�Ľ��������
										// 0 1 35����һ��ʲô��
		}
	}

	int idMaxEle = 0;

	//---��Ϊһ��ֻ��26��Ӣ����ĸ---
	for (int j = 0; j < 26; j++)
	{
		if (hashTable[j] > hashTable[idMaxEle])  // ������Ƚ�ÿ��Ӣ����ĸ���ֵĴ���
			idMaxEle = j;
	}

	//---idMaxEle��󲻳���26---
	printf("%c %d", 'a' + idMaxEle, hashTable[idMaxEle]);

	return 0;
}