// A1025. PAT Ranking

#include "C.h"

struct Student 
{
	char id[15];
	int score;

	//--������--
	//--����������--
	int location_number;
	int local_rank;
}stu[30010];

bool cmp(Student a, Student b) 
{
	if (a.score != b.score) 
		//--�������ǴӸߵ�������--
		return a.score > b.score; // ��������stu���Ȱ��ɼ���С����
	else 
		//--���a��b�ķ�����ͬ����׼��֤�Ŵ�С��������--
		return strcmp(a.id, b.id) < 0;
}

int main() 
{
	int numsOfLocations;
	int testeesOfLocations;
	int totalNums = 0;

	scanf("%d", &numsOfLocations);

	for (int i = 1; i <= numsOfLocations; i++)
	{
		//--i=2��ʱ�򣬾�Ҫ��ʼ�����2����ѧ������Ϣ��--
		scanf("%d", &testeesOfLocations);
		for (int j = 0; j < testeesOfLocations; j++)
		{
			//--��һ������ѧ��0��id��score--
			//---�ڶ�����ѧ��0��id��score---
			scanf("%s %d", stu[totalNums].id, &stu[totalNums].score);

			//--Ȼ��ѧ��0�Ŀ������ǵ�ǰ��i--
			//---�ڶ����У�����ѧ��0�Ŀ������ǵ�ǰ��2����---
			stu[totalNums].location_number = i;

			//--��һ���У�totalNums�͵��ڵ�һ�������Ŀ�������--
			//---�ڶ����У�totalNums���ڵ�һ���������������Ļ���������---
			//---���totalNums������������������������---
			totalNums++;
		}

		//--���Ե�һ��sort�����������(stu+0, stu+totalNums, cmp)--
		//---���Եڶ���sort�����������(stu+testeeOfLocations1+0, stu+testeeOfLocation1+2, cmp)
		sort(stu + totalNums - testeesOfLocations, stu + totalNums, cmp);

		//--�������stu[0]���Ǹõ�һ������һ��--
		//---�ڶ����������stu[testeesOfLocation1 + 1]Ҳ���Ǻ�����һλ�������������ǵ�1��---
		stu[totalNums - testeesOfLocations].local_rank = 1;

		//--��һ���У�j�ĳ�ֵ��Ϊ1��j < totalNums--
		//--��Ϊ��һ���Ѿ������ˣ�����ֱ�Ӵ�stu[2]Ҳ���ǵڶ�����ʼ��--

		//---�ڶ����У�j�ĳ�ֵ����testeesOfLocations2����ߵ�ֵ��1---
		for (int j = totalNums - testeesOfLocations + 1; j < totalNums; j++)
		{
			//--����ڶ����͵�һ���ĳɼ���ͬ������--
			if (stu[j].score == stu[j - 1].score) 
			{
				stu[j].local_rank = stu[j - 1].local_rank; // �ɼ���ͬһ�����У��������ʱ��ǰ��
														   // ���Ǹ���֮ǰ��id��С��cmp�Ѿ��ź���
			}

			//--������ǲ��У���1�����ڵ�������Ϊj+1--
			//---������ǲ��У���2�����ڵ�������Ϊ 1 + 1 = 2 (��for��j�ĳ�ֵ������)---
			else 
			{
				stu[j].local_rank = j + 1 - (totalNums - testeesOfLocations);
			}
		}
	}
	//----����forѭ����Ŀ�ľ��Ǹ����ź����������ڵ�����������Ϣ�洢��ȥ----
	//----�ص����ڣ��ڶ������������Ǵ�stu[k]��ʼ�ģ������Ǹ���һ����һ����stu[0]��ʼ��----
	//----��Ϊ��������󣬸ı��ֻ��stu[]�е���ţ�stu[]�д洢��ֵ��û�б��----
	//----��local����Ϣ������stu�ṹ������е�local_rank��----

	printf("%d\n", totalNums);

	//----��������һ����----
	sort(stu, stu + totalNums, cmp);

	//----��ǰ����������----
	int r = 1;
	for (int i = 0; i < totalNums; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score) 
		{
			r = i + 1;
		}

		//----��һ�������ظ�if----
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}

//-----��Ϊ�������˵����һ��Ԫ�ش�5�ŵ���2���ı���ǵ�ַ����������洢��ֵû�б�-----
//-----����˵�����ʵ�ַ��ʱ��ֻ�����ǵ�ַ���ˣ������ֵ���䣬����ʵ�ִӴ�С������-----