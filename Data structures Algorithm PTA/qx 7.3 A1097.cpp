// A1097 Deduplication on a Linked List

#include "C.h"

const int maxn = 100005;
const int TABLE = 1000010;

struct Node 
{    //---���徲̬������һ����---
	int address, data, next;

	//--����������ϵ���ţ���Ч����Ϊ2*maxn--
	int order;    
}node[maxn];

//---����ֵ�Ƿ��Ѿ�����---
bool isExist[TABLE] = { false };

bool cmp(Node a, Node b) 
{
	return a.order < b.order;    // ��order��С��������
}


int main() 
{
	//--��ʼ��isExistΪfalse����ʾδ���ֹ���ǰ���Ȩֵ�ľ���ֵ--
	memset(isExist, false, sizeof(isExist));    

	for (int i = 0; i < maxn; i++) 
	{    //--��ʼ�����ڶ�����--
		 //--��ʾ��ʼʱ��Ϊ��Ч���--
		 //--������Ч������ͻᱻ���ֿ�--
		node[i].order = 2 * maxn;    
	}

	//---��ʼ��ַ��������---
	int n, begin, address;
	scanf("%d%d", &begin, &n);    
	for (int i = 0; i < n; i++) 
	{    //---�������н��---
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	//---δɾ������Ч����������ɾ������Ч������---
	int countValid = 0, countRemoved = 0, p = begin;
	while (p != -1) 
	{    //---ö��������������---
		if (!isExist[abs(node[p].data)]) 
		{    //---data�ľ���ֵ��ʱ��������---
			isExist[abs(node[p].data)] = true;    // ���Ϊ�Ѵ���
			node[p].order = countValid++;    // ��ɾ������Ŵ�0��ʼ
		}

		else
		{    //--���data�ľ���ֵ�Ѵ���--
			node[p].order = maxn + countRemoved++;    // isExist�����£���ʾ��ɾ��
													  // ��Ŵ�maxn��ʼ
		}
		p = node[p].next;    // ��һ�����
	}

	sort(node, node + maxn, cmp);    // ��order��С�������򣨵��Ĳ���

	// �����������岽��
	int count = countValid + countRemoved;    // ��Ч������
	for (int i = 0; i < count; i++)
	{
		if (i != countValid - 1 && i != count - 1) 
		{    //---�����һ�����---
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		}
		else
		{    // ���һ����㵥������ֱ��д��-1
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}
