//A1083. List Grades

#include "C.h"

const int maxn = 100010;

struct testee
{
	//--[]�е�20��ʾname���20����ĸ��ID���20����ĸ--
	char name[20];
	int grade;
	char ID[20];
}stu[maxn];

bool cmp(testee a, testee b)
{
	if (a.grade != b.grade)
		return a.grade > b.grade;
}

int main()
{
	int Num;
	scanf("%d", &Num);

	for (int i = 0; i < Num; i++)
	{
		scanf("%s %s %d", stu[i].name, stu[i].ID, &stu[i].grade);
	}

	int _left_boun, _right_boun;

	scanf("%d %d", &_left_boun, &_right_boun);

	sort(stu, stu + Num, cmp);

	//---Ҫһ��ʼ��flag�ĳ�ֵ��ʼ��Ϊfalse����������true������ôҲ�������None��---
	bool flag = false;

	for (int j = 0; j < Num; j++)
	{
		if (stu[j].grade >= _left_boun && stu[j].grade <= _right_boun)
			//�жϽ�����ֱ�����
		{
			printf("%s %s %d\n", stu[j].name, stu[j].ID, stu[j].grade);

			//--���flag���Է������ʱ����Ϊtrue������ΪֻҪ��һ���˱�������Ͳ���None--
			//--Ҳ����˵flag=falseֻ������None��Ӱ�죬����ʱ�����Ӱ��--
			flag = true;
		}

		/*if (flag == false)     //***��������ж�������None�ͻ���ÿ����������еĺ������һ��
			printf("None!\n");*/ //***��ΪNoneֻ�����һ�Σ�����printf NoneҪ����forѭ����ߡ�
	}

	if (flag == false)
		printf("None!\n");

	return 0;
}

