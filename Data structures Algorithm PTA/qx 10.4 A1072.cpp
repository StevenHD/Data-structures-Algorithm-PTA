// A1072. Gas Station

// ---------CODE---------

#include "C.h"

const int MAXV = 1020;
const int INF = 1000000000;

//--mΪ����վ����kΪ����--
//--DSΪ����Χ--
int n, m, k, DS, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = { false };


//---Dijkstra�㷨�����ж��㵽���s����̾���---
void Dijkstra(int s) 
{
	memset(vis, false, sizeof(vis));
	fill(d, d + MAXV, INF);
	d[s] = 0;

	for (int i = 0; i < n + m; i++)
	{
		int u = -1, MIN = INF;

		for (int j = 1; j <= n + m; j++) 
		{
			if (vis[j] == false && d[j] < MIN) 
			{
				u = j;
				MIN = d[j];
			}
		}


		if (u == -1) return;

		vis[u] = true;

		for (int v = 1; v <= n + m; v++)
		{
			if (vis[v] == false && G[u][v] != INF) 
			{
				if (d[u] + G[u][v] < d[v]) 
				{
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}


//---��str[]ת��Ϊ���֣���str�����֣��򷵻ر���---
//---���򣬷���ȥ��G֮�������������n---
int getID(char str[]) 
{
	int i = 0, len = strlen(str), ID = 0;

	while (i < len) 
	{
		//--ֻҪ����G����ת��Ϊ����--
		if (str[i] != 'G') 
		{
			ID = ID * 10 + (str[i] - '0');
		}

		i++;
	}

	//--��λ�����G������n+ID--
	if (str[0] == 'G') return n + ID;

	//--��λ����G������ID--
	else return ID;
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &k, &DS);

	//--u��v��ʾһ��road�����Ҷ˵㣬w��ʾ��Ȩ--
	int u, v, w;

	char city1[5], city2[5]; // ������ַ���������char�������������

	fill(G[0], G[0] + MAXV * MAXV, INF);


	for (int i = 0; i < k; i++) 
	{
		//--���ַ�������ʽ������б��--
		scanf("%s %s %d", city1, city2, &w);

		u = getID(city1);
		v = getID(city2);

		//--��Ȩ--
		G[v][u] = G[u][v] = w;
	}

	//--ansDis��������������--
	//--ansAvg�����С��ƽ������--
	//--ansID������յļ���վID--
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;

	//--ö�����еļ���վ--
	for (int i = n + 1; i <= n + m; i++) 
	{
		//---minDisΪ��ǰ����������룬avgΪƽ������---
		double minDis = INF, avg = 0;

		//---����Dijkstra�㷨�����d[]����---
		Dijkstra(i);

		//---ö�����о���---
		//---�����ǰ��minDis��avg---
		for (int j = 1; j <= n; j++) 
		{
			//--���ھ������DS�ľ��񷿣�ֱ������--
			if (d[j] > DS)
			{
				minDis = -1;
				break;
			}

			//--���µ�ǰ�����������--
			if (d[j] < minDis) minDis = d[j];

			//--��ȡƽ������--
			avg += 1.0 * d[j] / n;
		}

		//--������ھ������DS�ľ��񷿣��������ü���վ--
		if (minDis == -1) continue;

		//--���������������--
		if (minDis > ansDis)
		{
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}

		//--������Сƽ������--
		else if (minDis == ansDis && avg < ansAvg) 
		{
			ansID = i;
			ansAvg = avg;
		}
	}

	//--�޽�--

	if (ansID == -1) printf("No Solution\n");

	else
	{
		printf("G%d\n", ansID - n);
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}

	return 0;
}
