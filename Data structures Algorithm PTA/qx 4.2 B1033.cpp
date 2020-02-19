// B1033. �ɼ��̴���

//---------CODE---------

#include "C.h"
const int maxn = 100010;

//---hashTableΪɢ�����飬������¼�����ϵ��ַ��Ƿ����---
bool hashTable[256];
char str[maxn];

int main() 
{
	//---��ֵ������true��ʾ���м������---
	memset(hashTable, true, sizeof(hashTable));

	//---��������ʧЧ�ļ�λ---
	gets_s(str);
	int len = strlen(str);

	for (int i = 0; i < len; i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			//---����д��ĸ��ת����Сд��ĸ---
			str[i] = str[i] - 'A' + 'a';
		}

		//---��ΪhashTable��char�͵ģ�����str[i]Ӧ��Ҳ��char���ַ�����������Сдa b c d---
		hashTable[str[i]] = false;  // ��ô�о����str[i]��hashTable������ʾ����������
	}

	//---������������ַ���---
	//---���str�������ظ���һ��---
	gets_s(str);
	len = strlen(str);

	for (int i = 0; i < len; i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			//---����Ǵ�д��ĸ����ΪСд��ĸ---
			int low = str[i] - 'A' + 'a';  // low��int�ͱ���������lowӦ��������
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


//------����-------
// hashTable[]�еĶ�����������0��ʼ
// hashTable[0] hT[1]��Щ
// str[i]��������char������ֵ����43'+'���֣�������ַ���
// ���Ҹо�����ht��ʱ����������ʽ��
// �ǿ���char�����飬Ҳ���Դ��������

// �ҵ�����һ�£�hashTable[55]=false,hashTable[56]=true
// ���Բ²��ǶԵģ�����str[i]=43'+'���֣�����ֻ������д�İ�
// ���hashTable[str[i]]�д���ȥ�Ļ���hashTable[43]