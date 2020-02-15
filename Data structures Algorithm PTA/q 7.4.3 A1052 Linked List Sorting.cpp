// A1052 Linked List Sorting ʹ�þ�̬���������

#include "C.h"
const int maxn = 100005;

struct Node 
{
	//---���徲̬����---
	//---flag=true��ʱ���ʾ��㲻��������(��Ч���)---
	int address, data, next;
	bool flag; //--����Ƿ���������---
}node[maxn];

bool cmp(Node a, Node b) 
{
	if (a.flag == false || b.flag == false) 
	{
		//--��Ϊ��Ч����flagΪ1����Ч����flagΪ0--
		//--�������԰���Ч����ŵ��������---
		//--ֻҪa��b����һ����Ч��㣬�Ͱ����ŵ�����ȥ--
		return a.flag > b.flag;
	}
	else 
	{
		//--���������Ч��㣬��Key�Ĵ�С����--
		return a.data < b.data;
	}
}
int main() 
{
	for (int i = 0; i < maxn; i++) 
	{
		//--��ʼ������flag��Ϊfalse--
		node[i].flag = false;
	}

	//--begin��ʾͷ���ĵ�ַ---
	//--address��ʾ��ͷ����⣬����ÿ�����ĵ�ַ---
	int n, begin, address;
	scanf("%d%d", &n, &begin);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, 
			&node[address].next);			// ���ﻹ���ý���ַ���±�
		node[address].address = address;
	}

	int count = 0, p = begin;

	//---ö��������flag���б�ǣ�ͬʱ����count��Ч���ĸ���---
	while (p != -1) // ����p�д洢�ľ���ÿ�����ĵ�ַ
	{
		node[p].flag = true;
		count++;
		p = node[p].next; // next��ʾ�ľ����¸����ĵ�ַ
	}

	//---���У���������û�н��ʱ(count=0)�����0 -1
	if (count == 0) 
	{
		printf("0 -1");
	}
	else 
	{
		//--ɸѡ��Ч��㣬����data��С��������--
		sort(node, node + maxn, cmp); //**Ϊʲô������node+maxn��maxn�ܴ��Ҽǵá�����***
		
		//--������--
		//--��ֹ-1��%05d������ǰ�ж�--
		//---Ҳ����˵ע��-1�����---
		printf("%d %05d\n", count, node[0].address); //***node[0]��ʾ����ͷ���ĵ�ַ?***
													 //--�ԣ������ź�����һ�����ĵ�ַ!--

		for (int i = 0; i < count; i++) 
		{
			//--��ֹ-1��%05d������ǰ�жϵĽ������--
			if (i != count - 1) 
			{
				printf("%05d %d %05d\n", node[i].address, 
					node[i].data, node[i + 1].address); // ��Ϊ�Ѿ��ź�����
														// ���ԾͰ�for˳�����ͺ�
			}

			//--��ֹ-1��%05d������ǰ�жϵĽ������--
			else 
			{
				printf("%05d %d -1\n", node[i].address, node[i].data); 
			}
		}
	}

	return 0;
}
