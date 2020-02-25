// A1003. Emergency ���·��
// 16��26 -- 17��34

#include "C.h"

//---����һ����󶥵����������---
const int MAXV = 510;
const int INF = 1000000000;


//--nΪ��������mΪ������st��ed�ֱ�Ϊ�����յ�--
int n, m, st, ed;

//--G[][]Ϊ�ڽӾ���weight[]Ϊ��Ȩ--
int G[MAXV][MAXV], weight[MAXV];

//--d[]��¼��̾��룬w[]��¼����Ȩ֮�ͣ�num[]��¼���·������--
int d[MAXV], w[MAXV], num[MAXV];

//--vis[i] == true��ʾ����i�Ѿ����ʣ���ʼֵ��Ϊfalse--
bool vis[MAXV] = { false };

//--s��ʾ���--
void Dijkstra(int s) 
{
	fill(d, d + MAXV, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));

	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;

	//---ѭ��n��---
	for (int i = 0; i < n; i++) 
	{
		//--uʹd[u]��С��MIN��Ÿ���С��d[u]--
		int u = -1, MIN = INF;

		//--�ҵ�δ���ʵĶ�����d[]��С��--
		for (int j = 0; j < n; j++) 
		{
			if (vis[j] == false && d[j] < MIN) 
			{
				u = j;
				MIN = d[j];
			}
		}

		//--�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ--
		if (u == -1) 
			return;

		//--��ʱ�����uΪ�Ѿ�����--
		vis[u] = true;


		for (int v = 0; v < n; v++) 
		{
			//--�������vû�б����ʣ�����u���Ե���v����uΪ�н�����ʹd[v]����--
			if (vis[v] == false && G[u][v] != INF) 
			{
				//--��uΪ�н��ʱ����d[v]��С--
				if (d[u] + G[u][v] < d[v]) 
				{
					//--����d[v]��w[v]--
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];

					//--����num[v]--
					num[v] = num[u];
				}

				//--�ҵ�һ����ͬ���ȵ�·��--
				else if (d[u] + G[u][v] == d[v]) 
				{
					//--��uΪ�н���ʱ���Ȩ֮�͸���--
					if (w[u] + weight[v] > w[v])
					{
						//--w[v]�̳���w[u]--
						w[v] = w[u] + weight[v];
					}

					//--��num[]���·������д�������ԭ���ǣ�
					//--���·���������Ȩ�޹أ����Ա���д������--
					num[v] += num[u];       // num[u]һ����1����Ϊu���н�㣬��s��ֱ�������ġ�
				}
			}
		}
	}
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &st, &ed);    // ���붥�����������������յ�
	for (int i = 0; i < n; i++) 
	{
		//--�����Ȩ--
		scanf("%d", &weight[i]);    
	}
	

	//--����һ���ߵ������˵�u��v--
	int u, v;

	//--��ʼ��ͼG--
	fill(G[0], G[0] + MAXV * MAXV, INF);


	for (int i = 0; i < m; i++) 
	{
		//--��������ÿ���ߵ���������u��v--
		//--����u��v֮��ı�Ȩ--
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}

	//--Dijkstra�㷨���--
	Dijkstra(st);

	//--��̾������������·���е�����Ȩ--
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}

