// B1039/A1092  ��������

#include "C.h"

const int MAXN = 1010;

//---hashTable�����¼��һ����ÿ����ɫ�ĸ���---
//---miss��¼ȱ�ٵ����Ӹ���---
int hashTable[80] = { 0 }; // ֮���Զ����80����Ϊ���ִ�Сд��ĸһ��62�������Կ���80������
int miss = 0;

// �����ֺ���ĸת��ΪhashTable���±�
int change(char c) 
{
	if (c >= '0' && c <= '9') 
		return c - '0';    // ����
	if (c >= 'a' && c <= 'z') 
		return c - 'a' + 10;    // Сд��ĸ
	if (c >= 'A' && c <= 'Z') 
		return c - 'A' + 36;    // ��д��ĸ
}

int main() 
{
	char whole[MAXN], target[MAXN];
	gets_s(whole);    // ��һ��
	gets_s(target);    // �ڶ���

	int len1 = strlen(whole);    // ��һ������
	int len2 = strlen(target);    // �ڶ�������

	for (int i = 0; i < len1; i++) 
	{    //---������һ��---
		int id = change(whole[i]);    // �ַ�->hashTable�±�
		hashTable[id]++;    // ����ɫ������1
	}

	//---�����ڶ���---
	for (int i = 0; i < len2; i++) 
	{    
		int id = change(target[i]);    // �ַ�->hashTable�±�
		hashTable[id]--;    // ����ɫ������1

		//--�������ɫ�ĸ���С��0--
		if (hashTable[id] < 0) 
		{    
			miss++;    // ȱ�ٵ����Ӹ�����1
		}
	}

	if (miss > 0) 
		printf("No %d\n", miss);    // ��ȱ��
	else 
		printf("Yes %d\n", len1 - len2);    // �и���

	return 0;
}
