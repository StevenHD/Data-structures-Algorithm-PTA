//A1083. List Grades

#include "C.h"

const int maxn = 100010;

struct testee
{
	//--[]中的20表示name最多20个字母，ID最多20个字母--
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

	//---要一开始将flag的初值初始化为false，如果定义成true，就怎么也不能输出None了---
	bool flag = false;

	for (int j = 0; j < Num; j++)
	{
		if (stu[j].grade >= _left_boun && stu[j].grade <= _right_boun)
			//判断结束后直接输出
		{
			printf("%s %s %d\n", stu[j].name, stu[j].ID, stu[j].grade);

			//--这个flag可以放在输出时再置为true，是因为只要有一个人被输出，就不是None--
			//--也就是说flag=false只会对输出None有影响，正常时输出无影响--
			flag = true;
		}

		/*if (flag == false)     //***如果不加判定条件，None就会在每个合理输出中的后面出现一次
			printf("None!\n");*/ //***因为None只能输出一次，所以printf None要放在for循环外边。
	}

	if (flag == false)
		printf("None!\n");

	return 0;
}

