// B1043. ���PATest

#include "C.h"

const int maxn = 10010;

//---�����ַ������ֵ�---

char str[maxn];
char dict[6] = { 'P', 'A', 'T', 'e', 's', 't' };

//---����һ��hashTable[]����¼PATest��6���ַ��ĸ���---
int hashTable[6] = { 0 };

int main()
{
	//---�����ַ���---
	gets_s(str);

	//---���峤��len��sum�����������ܹ���Ҫ������ַ�����---
	int len = strlen(str);
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		//---����dict�ֵ�---
		for (int j = 0; j < 6; j++)
		{
			//---str[i]���ֵ��е��±�Ϊj---
			/*if (str[i] = dict[j])*/ //Ӧ�������������ں� ==
			if (str[i] == dict[j])
			{
				//---P A T e s t �ֱ��Ӧ��j�е� 0 1 2 3 4 5---
				hashTable[j]++;

				//---��Ҫ����sum��sum����Ҫ������ַ��ĸ������ǵ÷�������Ĳ��ϼ�1---
				sum++;
			}
		}
	}

	//---��������ַ��������0ʱ�˳�whileѭ��---
	while (sum > 0)
	{
		//---����hash����---
		for (int k = 0; k < 6; k++)
		{
			//---hashTable[0]�Ͷ�Ӧ����dict[0]�Ͷ�Ӧ����'P'---
			//---�߼������������P�ĸ�������0�����P��Ȼ��P�ĸ�����1�����������Ҳ��1---
			//---Ȼ��k++������P������A���Դ�����---
			//---�����ӾͿ��Ա�֤������ַ�˳��һ����PATest---
			//---forѭ��һ��������һ��PATest---
			//---����sumֻҪ����0���ͻ����¿�ʼforѭ���������Ͳ������PATestPATest����---
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