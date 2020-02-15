// B1025/A1074  ��ת����
#include "C.h"

const int maxn = 100010;
struct Node 
{
	//--���徲̬����--
	int address, data, next;
	int order;
}node[maxn];


bool cmp(Node a, Node b) 
{
	//--order��ʾ����������е����(��0��ʼ)��������Ч���Ϊmaxn--
	if (a.order == -1 || b.order == -1) 
	{
		return a.order > b.order;
	}
	else 
	{
		//--���������Ч����Խ�㰴order��С��������--
		return a.order < b.order; 
	}
}


int main() 
{
	for (int i = 0; i < maxn; i++) 
	{
		//--��order�ĳ�ֵ��Ϊ-1����ʾ��ʼʱ���н��Ϊ��Ч���--
		node[i].order = -1;
	}

	//--begin��ʾ�����׵�ַ--
	//--n��ʾ���ĸ���--
	//--K��ʾ����--
	int begin, n, K, address;
	scanf("%d%d%d", &begin, &n, &K);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	//--count������Ч������Ŀ--
	int p = begin, count = 0;

	//---���������ҳ��������������Ч���---
	while (p != -1) // ��������ı���ͨ��ʹ��while����Ϊ�ж�������addressΪ-1
	{
		//--����ڵ������е����order��count��ֵ--
		//--�������order��count��ͬ���ģ�����1 2 3 4 5.....
		node[p].order = count++;

		//--��һ�����--
		p = node[p].next;
	}

	//--���������ͷ��β˳������--
	sort(node, node + maxn, cmp);

	//--��Ч���Ϊǰcount�����--
	//--Ϊ����д���㣬��count����n--
	n = count;

	//--�������Ѿ��γ�--
	for (int i = 0; i < n / K; i++) 
		//--- ö�������� n/K �� ---
	{
		for (int j = (i + 1) * K - 1; j > i* K; j--) 
		{
			//--��i�鵹�����--
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}

		//--��������ÿһ������һ������next��ַ�Ĵ���--
		printf("%05d %d ", node[i * K].address, node[i * K].data);

		//---����������һ��---
		//---��ָ����һ������һ�����---
		if (i < n / K - 1) 
		{
			printf("%05d\n", node[(i + 2) * K - 1].address);
		}

		//---��������һ��---
		else 
		{
			//--��ǡ�������һ����㣬�����-1--
			if (n % K == 0) 
			{
				printf("-1\n");
			}

			//--ʣ�²������Ŀ鰴ԭ�ȵ�˳�����--
			else 
			{
				printf("%05d\n", node[(i + 1) * K].address);
				for (int i = n / K * K; i < n; i++) 
				{
					printf("%05d %d ", node[i].address, node[i].data);
					if (i < n - 1) 
					{
						printf("%05d\n", node[i + 1].address);
					}
					else 
					{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
