// A1072. Gas Station

// ---------CODE---------

#include "C.h"

const int MAXV = 1020;
const int INF = 1000000000;

//--m为加油站数，k为边数--
//--DS为服务范围--
int n, m, k, DS, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = { false };


//---Dijkstra算法求所有顶点到起点s的最短距离---
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


//---将str[]转换为数字，若str是数字，则返回本身---
//---否则，返回去掉G之后的数，并加上n---
int getID(char str[]) 
{
	int i = 0, len = strlen(str), ID = 0;

	while (i < len) 
	{
		//--只要不是G，就转换为数字--
		if (str[i] != 'G') 
		{
			ID = ID * 10 + (str[i] - '0');
		}

		i++;
	}

	//--首位如果是G，返回n+ID--
	if (str[0] == 'G') return n + ID;

	//--首位不是G，返回ID--
	else return ID;
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &k, &DS);

	//--u和v表示一条road的左右端点，w表示边权--
	int u, v, w;

	char city1[5], city2[5]; // 这里的字符串还是用char型数组来定义的

	fill(G[0], G[0] + MAXV * MAXV, INF);


	for (int i = 0; i < k; i++) 
	{
		//--以字符串的形式读入城市编号--
		scanf("%s %s %d", city1, city2, &w);

		u = getID(city1);
		v = getID(city2);

		//--边权--
		G[v][u] = G[u][v] = w;
	}

	//--ansDis存放最大的最近距离--
	//--ansAvg存放最小的平均距离--
	//--ansID存放最终的加油站ID--
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;

	//--枚举所有的加油站--
	for (int i = n + 1; i <= n + m; i++) 
	{
		//---minDis为当前最大的最近距离，avg为平均距离---
		double minDis = INF, avg = 0;

		//---进行Dijkstra算法，求出d[]数组---
		Dijkstra(i);

		//---枚举所有据民房---
		//---求出当前的minDis和avg---
		for (int j = 1; j <= n; j++) 
		{
			//--存在距离大于DS的居民房，直接跳出--
			if (d[j] > DS)
			{
				minDis = -1;
				break;
			}

			//--更新当前最大的最近距离--
			if (d[j] < minDis) minDis = d[j];

			//--获取平均距离--
			avg += 1.0 * d[j] / n;
		}

		//--如果存在距离大于DS的居民房，则跳过该加油站--
		if (minDis == -1) continue;

		//--更新最大的最近距离--
		if (minDis > ansDis)
		{
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}

		//--更新最小平均距离--
		else if (minDis == ansDis && avg < ansAvg) 
		{
			ansID = i;
			ansAvg = avg;
		}
	}

	//--无解--

	if (ansID == -1) printf("No Solution\n");

	else
	{
		printf("G%d\n", ansID - n);
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}

	return 0;
}
