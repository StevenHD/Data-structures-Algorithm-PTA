#include "C.h"

//---����---
// ����˵��loading��being���������У���ĸi�ĵ�ַ����Ҫ����Ĵ𰸡�
// ������ as �� at �������Ͳ��У�����ĸ�ǲ����

//------CODE------
const int maxn = 100010;
struct NODE 
{
	//---data��������---
	//---next��һ��int�͵����������Դ����һ�����ĵ�ַ---
	//---next��ʵ�Ͼ��������±�---
	char data;
	int next;

	//---flag������ʾ����Ƿ��ڵ�һ�������г���---
	bool flag;
}node[maxn];

int main() 
{
	for (int i = 0; i < maxn; i++) 
	{
		node[i].flag = false; // ͨ���տ�ʼ��flag���ᱻ��ʼ����false
	}

	int n;
	int stAddressOfFirstLL;
	int stAddressOfSecondLL;
	scanf("%d%d%d", &stAddressOfFirstLL, &stAddressOfSecondLL, &n);

	//---�������ַ�ͺ�̽���ַ---
	int addrOfNode, addrOfNextNode;
	char eachLetter;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &addrOfNode, &eachLetter, &addrOfNextNode);
		node[addrOfNode].data = eachLetter;
		node[addrOfNode].next = addrOfNextNode;
	}

	int p; // ���p֮���Բ���for()���涨�壬����Ϊ���pҪ�����������б���
	for (p = stAddressOfFirstLL; p != -1; p = node[p].next) 
	{
		// p�ĳ�ֵ���׵�ַ��ֻҪp������NULL��p�Ͳ��ϵظ��µ�ǰ���ĺ�̽��ĵ�ַ
		//---ö�ٵ�һ����������н�㣬������ִ���Ϊ1---
		node[p].flag = true;
	}

	for (p = stAddressOfSecondLL; p != -1; p = node[p].next) 
	{
		// ��p�������һ����������н���
		// ��ʼ�ӵڶ���������׵�ַ��ʼ���������н��
		// ��Ϊ�±�p��ľ��ǵ�ַ���������node[p].flag��true
		// ˵���ڵ�һ�����Ѿ����ֹ�
		// ��ô��ֱ��break������ǰforѭ������ʵp�϶�����-1����ôprintf�������ɡ�
		if (node[p].flag == true) 
			break;
	}

	if (p != -1) 
	{
		printf("%05d\n", p);
	}

	else 
	{
		printf("-1\n");
	}
	return 0;
}