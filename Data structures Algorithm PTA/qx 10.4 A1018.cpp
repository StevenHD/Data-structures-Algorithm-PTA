//  A1018. Public Bike Management

//----------CODE----------

#include "C.h"

//--��󶥵���--
const int MAXV = 510;

//--�����--
const int INF = 1000000000;

//--CmaxΪ���������SpΪ����վ��--
int n, m, Cmax, Sp, numPath = 0, G[MAXV][MAXV], weight[MAXV];

//--minNeed��¼PBMC����Я������Ŀ��minRemain��¼PBMC���ٴ��ص���Ŀ--
int d[MAXV], minNeed = INF, minRemain = INF;

//--vis[i] == true��ʾ����i�ѷ��ʣ���ʼ��Ϊfalse--
bool vis[MAXV] = { false };

//--pre��ʾǰ����tempPath���ʾ��ʱ·����path��ʾ����·��--
vector<int> pre[MAXV];
vector<int> tempPath, path;


//--sΪ���--
void Dijkstra(int s) 
{
	fill(d, d + MAXV, INF);
	for (int i = 0; i <= n; i++) 
	{
		pre[i].push_back(i);
	}

	d[s] = 0;


	for (int i = 0; i <= n; i++)      // ����д��(i<n)��(i<=n)���û������
									  // Ҳ����ѭ��n�κ�ѭ��n+1��û������
	{
		int u = -1, MIN = INF;

		//--�ҵ�δ���ʵĶ�����d[]��С��--
		for (int j = 0; j <= n; j++) 
		{
			if (vis[j] == false && d[j] < MIN) 
			{
				u = j;
				MIN = d[j];
			}
		}

		//--�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ--
		if (u == -1) return;

		//--���uΪ�ѷ���--
		vis[u] = true;


		for (int v = 0; v <= n; v++) 
		{
			//--���vδ���ʣ�����u�ܵ���v--
			if (vis[v] == false && G[u][v] != INF) 
			{
				if (d[u] + G[u][v] < d[v]) 
				{
					//--�Ż�d[v]--
					d[v] = d[u] + G[u][v];

					pre[v].clear();
					pre[v].push_back(u);
				}

				else if (d[u] + G[u][v] == d[v]) 
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}



void DFS(int v) 
{
	if (v == 0) 
	{
		//--�ݹ�߽磬Ҷ�ӽ��--
		tempPath.push_back(v);

		//--·����tempPath����ҪЯ������Ŀ����Ҫ���ص���Ŀ--
		int need = 0, remain = 0;

		//--�˴����뵹��ö��--
		for (int i = tempPath.size() - 1; i >= 0; i--) 
		{
			//--��ǰ�����Ϊid--
			int id = tempPath[i];

			//--�����Ȩ����0��˵����Ҫ����һ�������г�--
			if (weight[id] > 0) 
			{
				remain += weight[id];
			}

			//--�����Ȩ������0����Ҫ����--
			else
			{
				//--�����ǰ������remain�㹻����--
				if (remain > abs(weight[id])) 
				{
					//--��ô���õ�ǰ������remain��ȥ��Ҫ��������--
					remain -= abs(weight[id]);
				}

				//--�����ǰ������remain��������--
				else
				{
					//--�����Ĳ��ִ�PBMCЯ��--
					need += abs(weight[id]) - remain;

					//--��ǰ���е����г�ȫ���������������Թ�0--
					remain = 0;
				}
			}
		}


		//--�����Ҫ��PBMCЯ�������г���Ŀ���Ը���--
		if (need < minNeed) 
		{
			//--��ô���Ż�minNeed--
			minNeed = need;

			//--ͬʱ����minRemain--
			minRemain = remain;

			//--��Ҫ��������·��path--
			path = tempPath;
		}

		//--���Я����Ŀ��ͬ��������Ŀ����--
		else if (need == minNeed && remain < minRemain) 
		{
			//--��ô���Ż�minRemain--
			minRemain = remain;

			//--��Ҫ��������·��path--
			path = tempPath;
		}

		tempPath.pop_back();    // ΪʲôҪɾ��βԪ�أ�
		return;
	}


	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}

	tempPath.pop_back();        // ����ҲҪɾ��βԪ�أ�  
}




int main() 
{
	scanf("%d%d%d%d", &Cmax, &n, &Sp, &m);

	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);

	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &weight[i]);

		//--��Ȩ��ȥ������һ��--
		weight[i] -= Cmax / 2;
	}

	for (int i = 0; i < m; i++) 
	{
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);

		G[v][u] = G[u][v];
	}


	Dijkstra(0);
	DFS(Sp);

	//---�����Ҫ��PBMCЯ��������bike��Ŀ---
	printf("%d ", minNeed);

	//---�����������·��---
	for (int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d", path[i]);
		if (i > 0) printf("->");
	}

	//---�����Ҫ������վSp���ص�����bike��Ŀ---
	printf(" %d", minRemain);
	return 0;
}
