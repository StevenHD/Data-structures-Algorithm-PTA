// A1056 Mice and Rice

#include "C.h"

const int maxn = 1010;
struct mouse 
{
	//---����---
	//--����--
	//--����--
	int weight;
	int R;
}mouse[maxn];

int main() 
{
	int np, ng, order;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) 
	{
		scanf("%d", &mouse[i].weight);
	}

	//--����һ������--
	queue<int> q;
	for (int i = 0; i < np; i++) 
	{
		//--����Ŀ������˳��--
		scanf("%d", &order);

		//--��˳��������ǵı�����--
		q.push(order);
	}

	//---tempΪ��ǰ�ֵı�����������---
	//---groupΪ����---
	int temp = np, group;
	while (q.size() != 1) 
	{
		//--����group��Ҳ���ǵ�ǰ�ַ�Ϊ������б���--
		if (temp % ng == 0) 
			group = temp / ng;
		else 
			group = temp / ng + 1;

		//--ö��ÿһ�飬ѡ��������������������--
		for (int i = 0; i < group; i++) 
		{
			//--k��Ÿ���������������ı��--
			int k = q.front();
			for (int j = 0; j < ng; j++) 
			{
				//--�����һ������������NGʱ�����ã��˳�ѭ��--
				if (i * ng + j >= temp) 
					break;

				//--����������--
				int front = q.front();
				if (mouse[front].weight > mouse[k].weight) 
				{
					//--�ҳ�������������--
					k = front;
				}

				//--������������Ϊgroup+1--
				mouse[front].R = group + 1;

				//--��ֻ�������--
				q.pop();
			}
			//--��ʤ�����������--
			q.push(k);
		}

		//--groupֻ������������������������Ϊgroup--
		temp = group;
	}

	//--��������ֻʣ1ֻ����ʱ����������Ϊ1---
	mouse[q.front()].R = 1;

	//--��������������Ϣ--
	for (int i = 0; i < np; i++) 
	{
		printf("%d", mouse[i].R);

		if (i < np - 1) 
			printf(" ");
	}

	return 0;
}
