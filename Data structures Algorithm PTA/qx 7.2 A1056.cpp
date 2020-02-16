// A1056 Mice and Rice

#include "C.h"

const int maxn = 1010;
struct mouse 
{
	//---老鼠---
	//--质量--
	//--排名--
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

	//--定义一个队列--
	queue<int> q;
	for (int i = 0; i < np; i++) 
	{
		//--按题目给出的顺序--
		scanf("%d", &order);

		//--按顺序把老鼠们的标号入队--
		q.push(order);
	}

	//---temp为当前轮的比赛总老鼠数---
	//---group为组数---
	int temp = np, group;
	while (q.size() != 1) 
	{
		//--计算group，也就是当前轮分为几组进行比赛--
		if (temp % ng == 0) 
			group = temp / ng;
		else 
			group = temp / ng + 1;

		//--枚举每一组，选出该组老鼠中质量最大的--
		for (int i = 0; i < group; i++) 
		{
			//--k存放该组质量最大的老鼠的编号--
			int k = q.front();
			for (int j = 0; j < ng; j++) 
			{
				//--在最后一组老鼠数不足NG时起作用，退出循环--
				if (i * ng + j >= temp) 
					break;

				//--队首老鼠编号--
				int front = q.front();
				if (mouse[front].weight > mouse[k].weight) 
				{
					//--找出质量最大的老鼠--
					k = front;
				}

				//--该轮老鼠排名为group+1--
				mouse[front].R = group + 1;

				//--这只老鼠出队--
				q.pop();
			}
			//--把胜利的老鼠晋级--
			q.push(k);
		}

		//--group只老鼠晋级，因此下轮总老鼠数为group--
		temp = group;
	}

	//--当队列中只剩1只老鼠时，令其排名为1---
	mouse[q.front()].R = 1;

	//--输出所有老鼠的信息--
	for (int i = 0; i < np; i++) 
	{
		printf("%d", mouse[i].R);

		if (i < np - 1) 
			printf(" ");
	}

	return 0;
}
