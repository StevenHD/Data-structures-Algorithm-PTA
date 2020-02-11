// DFS��BFS�����ı����к�ͼ�ı����ж���Ӧ��
// A1034 Head Of a Gang

//-----����-----
// ������֮���ͨ�����ȣ����Խ�����Ϊ�����
// ����Щͨ����Ϊ�����飬ÿ������ܱ�Ȩ��Ϊ�����ڵ�����ͨ���ĳ���֮��
// ÿ���˵ĵ�Ȩ��Ϊ���˲����ͨ������֮��
// ����һ����ֵK��ֻҪһ������ܱ�Ȩ����K����Ա��������2(>2)���򽫸�����ΪGang
// �������ڵ�Ȩ��������ΪͷĿ
// Ҫ�����Gang�ĸ���������ͷĿ�����ֵ����С�����˳�����ÿ��Gang��ͷĿ�����ͳ�Ա����

//-----˼·------
// STEP1������Ҫ������������������ŵĶ�Ӧ��ϵ��
//		  һ�ǿ���ʹ��mapֱ�ӽ����ַ��������͵�ӳ���ϵ
//		  ����ʹ���ַ���hash�ķ������ַ���ת��Ϊ����
// STEP2������������ÿ���˵ĵ�Ȩ�������ڶ���ʱ�ͽ��д���
//		  ����A��B��ͨ��ʱ��ΪT����ôA��B�ĵ�Ȩ�ֱ�����T
// STEP3������ͼ�ı�����ʹ��DFS����ÿ����ͨ�飬Ŀ���ǻ�ȡÿ����ͨ���ͷĿ
//		  ͷĿ������ͨ���ڵ�Ȩ���Ľ�㣬��Ҫ��� ��Ա�������ܱ�Ȩ
// STEP4��ͨ��STEP3���Ի����ͨ����ܱ�ȨtotalValue�����totalValue���ڸ�������ֵK
//		  ���ҳ�Ա��������2����˵������ͨ����һ�� Gang ������Gang����Ϣ�洢����
//		  ���Զ��� map<string, int>�������Ż�ͷĿ���������Ա������ӳ���ϵ
//		  map�е�Ԫ�����Զ�������С��������

//-----ע���-----
// C1������ͨ����¼�����������1000��������ζ�Ų�ͬ���˿�����2000�ˣ����������С������2000����
// C2
// C3


//-------------------CODE-----------------------

#include "C.h"

//---��������Ҫ����2000---
const int maxn = 2010;
//---����һ�������---
const int INF = 1000000000; // �������INF����û���ô�

//---����map����---
//---��Ŷ�Ӧ����---
map<int, string> intToString;
//---������Ӧ���---
map<string, int> stringToInt;
//---head��Ӧ����---
map<string, int> Gang;

//---adjacencyMatrix��nodeWeight---
int adjacencyMatrix[maxn][maxn] = { 0 };
int nodeWeight[maxn] = { 0 };

//---����numsOfEdges����ֵK��������totalNumsOfPeople---
//---����Ƿ񱻷���---
int numsOfEdges;
int K;
int totalNumsOfPeople = 0;
bool vis[maxn] = { false };


//----DFS�������ʵ�����ͨ�飬indexOfNowVisitΪ��ǰ���ʵı��----
//----headΪͷĿ��indexOfMemberΪ��Ա��ţ�totalValueΪ��ͨ����ܱ�Ȩ----

//---DFS������Ŀ�ľ��ǽ���ͼ�ı�������ȡÿ����ͨ���ͷĿ ��Ա���� �ܱ�Ȩ---
void DFS(int indexOfNowVisit, int& head, int& indexOfMember, int& totalValue) 
{
	//---��Ա������1---
	indexOfMember++; // Ϊʲô��Ա����Ҫ��1��
	//---���nowVisit�ѷ���---
	vis[indexOfNowVisit] = true;

	if (nodeWeight[indexOfNowVisit] > nodeWeight[head]) // indexOfNowVisit�ǵ�ǰ���ʽڵ�ı��
	{
		//---��ǰ���ʽ��ĵ�Ȩ����ͷĿ�ĵ�Ȩ�������ͷĿ---
		head = indexOfNowVisit;
	}

	//---�������˽���ö��---
	for (int i = 0; i < totalNumsOfPeople; i++)
	{
		//---�ڽӾ����ʾ�ľ���ͼ�ıߣ�����if�жϱ�ʾ���������nowVisit����������Ե���i�����---
		if (adjacencyMatrix[indexOfNowVisit][i] > 0)
		{
			//---�ڽӾ����д洢�ľ��� ��Ȩ ---
			//---���nowVisit��i����ͨ�ģ��� ��ͨ����ܱ�ȨtotalValue ���� �ñ�Ȩ ---
			totalValue += adjacencyMatrix[indexOfNowVisit][i];

			//---ɾ�������ߣ�˫��ģ�ɾ�������ñ�ȨΪ0������ɾ��---
			adjacencyMatrix[indexOfNowVisit][i] = adjacencyMatrix[i][indexOfNowVisit] = 0;
			// �����Dijkstra�㷨������ģ��������� 0 �� INF ��ʹ��

			if (vis[i] == false) 
			{
				//---���iδ�����ʣ���ݹ����i---
				DFS(i, head, indexOfMember, totalValue); // ����������forѭ���ĵ���ѭ���У���ô�ݹ��أ�
			}
		}
	}
}


//---DFS�������Ի����ͨ����ܱ�ȨtotalValue---
//---DFSTrave�����п���ͨ��totalValue��K�ıȶԣ����г�Ա��������Ϣ�����ж���ͨ���ǲ���һ���Ż�---

//---DFSTrave�������Ǳ�������ͼ����ȡÿ����ͨ�����Ϣ---
//---һ����ͨ��Ͷ�Ӧһ���ŻҪ�����Ż����Ϣ�洢����---

void DFSTrave() 
{
	//---�������˽���ö��---
	for (int i = 0; i < totalNumsOfPeople; i++) 
	{
		//---���i�����û�б�����---
		if (vis[i] == false) 
		{
			//---ͷĿ����Ա�����ܱ�Ȩ---
			int head = i, numMember = 0, totalValue = 0; // ΪʲôҪ��head����i��

			//---����i���ڵ���ͨ��---
			DFS(i, head, numMember, totalValue);

			//---��Ա������2�����ܱ�Ȩ����k---
			if (numMember > 2 && totalValue > K) 
			{
				//---��head��Ӧ��С������---
				Gang[intToString[head]] = numMember;
			}
		}
	}
}


//----change������������str��Ӧ�ı��----
int change(string str) 
{
	//---���str�Ѿ����ֹ�---
	//---�򷵻�str�ı��---
	if (stringToInt.find(str) != stringToInt.end())  // ��仰�ܱ�ʾʲô��str�Ƿ���ֹ���
	{
		return stringToInt[str];
	}

	//---���strû�г��ֹ�---
	else
	{
		//---str�ı��ΪtotalNumsOfPeople---
		stringToInt[str] = totalNumsOfPeople; // totalNumsOfPeople��ʾ��������

		//---totalNumsOfPeople��Ӧstr---
		intToString[totalNumsOfPeople] = str;

		//---��������1---
		return totalNumsOfPeople++;
	}
}

int main() 
{
	int nw;
	string str1, str2;
	cin >> numsOfEdges >> K;

	// ö��ÿһ����
	for (int i = 0; i < numsOfEdges; i++)
	{
		//---����ÿ���ߵ������˵�͵�Ȩnw---
		cin >> str1 >> str2 >> nw;

		//---��str1ת��Ϊ���id1---
		//---��str2ת��Ϊ���id2---
		int id1 = change(str1);
		int id2 = change(str2);

		//---id1�ĵ�Ȩ����nw---
		//---id2�ĵ�Ȩ����nw---
		nodeWeight[id1] += nw;
		nodeWeight[id2] += nw;

		//---��id1->id2�ı�Ȩ����nw---
		//---��id2->id1�ı�Ȩ����nw---
		adjacencyMatrix[id1][id2] += nw;
		adjacencyMatrix[id2][id1] += nw;
	}

	//---DFSTrave��������ͼ�������Ż�(��ͨ��)������ȡGang����Ϣ---
	DFSTrave();

	//---Gang�ĸ���---
	cout << Gang.size() << endl;   // ����Ż������

	map<string, int>::iterator it; // ������һ��������������Ϊʲô�õ������أ�
								   // Ҳ����ΪGang������map���͵İ�

	//---��������Gang---
	for (it = Gang.begin(); it != Gang.end(); it++)
	{
		//---�����Ϣ---
		cout << it->first << " " << it->second << endl;
	} 
	// it->first�ǵ�ǰӳ��ļ���Ҳ����string ͷĿ������
	// it->secode�ǵ�ǰӳ���ֵ��Ҳ���� int ��Ա������

	return 0;
}
