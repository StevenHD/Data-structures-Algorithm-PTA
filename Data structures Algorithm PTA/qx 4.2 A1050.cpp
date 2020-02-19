// A1050. String Subtraction

//----------CODE----------

#include "C.h"

const int MAX_LEN = 10005;

//---a��b�ֱ���S1��S2---
//---һֱ��Ϊ����string�������ַ���---
//---Ҳ����Ϊ����Ҫö���ַ����е�ÿ���ַ�---
//---��������char�������������ַ���---
char a[MAX_LEN], b[MAX_LEN];

//---��¼�ַ��Ƿ��ڵڶ����ַ�������ֹ�---
bool HashTable[128];

int main() 
{
	gets_s(a);
	gets_s(b);

	//---Ϊ�˽���ʱ�临�Ӷȣ�strlen������forѭ��֮ǰ�ͼ���---
	int lenA = strlen(a);
	int lenB = strlen(b);

	//---���ڶ����ַ����е�ÿһ���ַ���hashֵ����Ϊtrue---
	for (int i = 0; i < lenB; i++)
	{
		HashTable[b[i]] = true;
	}

	//---ö�ٵ�һ���ַ����е�ÿ���ַ�---
	for (int i = 0; i < lenA; i++) 
	{
		//---�����Щ�ַ��У��е��ַ�û���ڵڶ���S2�г��ֹ��ģ������---
		if (HashTable[a[i]] == false) 
		{
			printf("%c", a[i]);
		}
	}

	return 0;
}
