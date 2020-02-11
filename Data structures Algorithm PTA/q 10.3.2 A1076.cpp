// A1076 Forwards on Weibo

//-----˼·-----
// ���ȿ�����ν�ͼ����Ϊ��Ŀ�������û���ע��������������û�����ע�����
// ��������û�X��ע���û�Y������Ҫ������Yָ��X�������
// Yָ��X��˵��Y��������ϢX�����յ������ҿ��Ա�Xת��

// �ڽ�ͼ��Ϻ�ʹ��DFS��BFS�����Եõ���Ҫ�Ľ��
// ���ʹ��DFS��������ֻҪ���Ʊ�����Ȳ�������Ŀ�����Ĳ���L����
// DFS���������� ���� ���ʵ��Ľ�����
// ���ʹ��BFS��������Ҫ�ѽ���źͲ�Ž����ɽṹ��
// Ȼ����Ʊ�������������L

//------------CODE------------------

#include "C.h"

const int MAXV = 1010;

//-----�ṹ��Node�Ķ���----
struct Node 
{
	//---�ṹ���еĽ��ı��---
	//---�ṹ���еĽ��Ĳ��---
	int id;
	int layer;
};


//---�ڽӱ�---
vector<Node> adjList[MAXV];

//---�����Ƿ��ѱ����������---
bool inQueue[MAXV] = { false };


//---stPointΪ��ʼ��㣬LΪ��������---
int BFS(int stPoint, int L)
{
	//---numForwardת������ֵΪ0---
	//---BFS����---
	int numForward = 0;
	queue<Node> queOfBFS;

	//---������ʼ���---
	//---��ʼ�����---
	//---��ʼ�����Ϊ0---
	Node start;
	start.id = stPoint;
	start.layer = 0;

	//---����ʼ���start ѹ�� ����queOfBFS---
	queOfBFS.push(start);

	//---��ʼ���ı����Ϊ �ѱ����������---
	inQueue[start.id] = true;


	while (!queOfBFS.empty()) 
	{
		//---ȡ�����׽��---
		Node topNode = queOfBFS.front();

		//---ȡ�����ö��׽�����---
		queOfBFS.pop();

		//---���׽��ı��id��ֵ������u---
		int u = topNode.id;


		for (int i = 0; i < adjList[u].size(); i++) 
		{
			//---�Ӷ��׽��u�����ܵ���Ľ��uNext---
			Node uNext = adjList[u][i]; //�ڽӱ�adjList�洢����ʲôֵ����

			//---uNext�Ĳ�ŵ��ڵ�ǰ�����+1---
			uNext.layer = topNode.layer + 1;

			//---���uNext�ı��δ����������У�����uNext�Ĳ�β���������L---
			if (inQueue[uNext.id] == false && uNext.layer <= L)
			{
				//---��uNext�������---
				queOfBFS.push(uNext);    // ���BFS�������Ǹ�����أ�ʲô���ð���

				//---���ʱ����Խ�uNext�ı����Ϊ���ѱ����������---
				inQueue[uNext.id] = true;

				//---ת����+1---
				numForward++;
			}
		}
	}

	//---����ת����---
	return numForward;
}

int main() 
{
	Node user;

	//---numsOfNode������---
	//---maxOfLayer��������---
	int numsOfNode, maxOfLayer, numFollow, idFollow;
	scanf("%d%d", &numsOfNode, &maxOfLayer);

	for (int i = 1; i <= numsOfNode; i++)
	{
		//---�û����Ϊi---
		user.id = i;

		//---i���û���ע������---
		scanf("%d", &numFollow);

		for (int j = 0; j < numFollow; j++) 
		{
			//---i���û���ע���û����---
			scanf("%d", &idFollow);

			adjList[idFollow].push_back(user);
		}
	}

	//---��ѯ����---
	int numQuery, s;
	scanf("%d", &numQuery);

	for (int i = 0; i < numQuery; i++) 
	{
		//---inQueue�����ʼ��---
		memset(inQueue, false, sizeof(inQueue));

		//---��ʼ���ı��---
		scanf("%d", &s);
		int numForward = BFS(s, maxOfLayer);
		printf("%d\n", numForward);
	}
	return 0;
}
