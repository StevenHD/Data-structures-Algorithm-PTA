// A1080. Graduate Admission 研究生入学

#include "C.h"

struct student
{
	int GE;
	int GI;
	int Sum;

	int _rank_stu;
	int _ID_stu;

	//--定义每个考生的K个志愿学生的编号--
	//--voluSchool[0]的编号为5，voluSchool[2]的编号为1。。。---
	int _volu_school[10];
}stu[40010];

struct school
{
	//--定义该学校招生人数总额度--
	int _quota;

	//--当前实际招生人数--
	int _actual_Num;

	/*char _accecpted_ID;*/
	/*char _accecpted_ID[40010];*/
	//--招收的考生编号--
	//--accID[0]可能是1，accID[5]可能是5....---
	int _accecpted_ID[40010]; //??? 为什么是int型数组？？因为编号是1 2 5 3 这种

	//--记录最后一个招收的考生编号--
	int _last_one;
}sch[110];

bool cmpStu(student a, student b)
{
	if (a.Sum != b.Sum)
		return a.Sum > b.Sum;
	else
		return a.GE > b.GE;
}

bool cmpID(int c, int d) // c d 就是个学生的下标，表示第c个学生，第d个学生
{
	return stu[c]._ID_stu < stu[d]._ID_stu;
}//这个函数等下写，不太知道这个函数能干嘛

int main()
{
	int _stu_NUM;
	int _sch_NUM;
	int _volu_NUM;
	scanf("%d %d %d", &_stu_NUM, &_sch_NUM, &_volu_NUM);

	/*int _accecpted_NUM[10];*/
	for (int i = 0; i < _sch_NUM; i++)
	{
		/*scanf("%d", _accecpted_NUM[i]);*/
		scanf("%d", &sch[i]._quota);

		//可能我漏掉了2个需要初始化的指标。。。
		//等下用到的时候再加上

		//---当前实际招生人数为0---
		sch[i]._actual_Num = 0;

		sch[i]._last_one = -1; //---将最后一个招收学生的学生编号定为-1, 表示不存在---
							   //***我个人认为则是_last_one要作为下标来索引，-1则是无效的下标
	}

	for (int j = 0; j < _stu_NUM; j++)
	{
		/*scanf("%d %d %d %d %d", &stu[j].GE, &stu[j].GI, &stu[j]._volu_school[0],
			&stu[j]._volu_school[1], & stu[j]._volu_school[2]);*/

			//---输入样例中的一行输入信息，并不代表我需要在写code时候也需要一口气输入完，
			//---样例中的一行信息，也可能分为2部分，第2部分可能需要一个新的for循环来输入
			//---只要注意一下\n换行符就行

			//***忘记对学生的ID进行初始化了

		//---考生的编号为j---
		//---也就是 1 2 3 等等---
		stu[j]._ID_stu = j;

		scanf("%d %d", &stu[j].GE, &stu[j].GI);

		stu[j].Sum = stu[j].GE + stu[j].GI;

		for (int k = 0; k < _volu_NUM; k++)
		{
			//--对于考生j，依次输入k个志愿学校的编号，0~5之间---
			scanf("%d", &stu[j]._volu_school[k]);
		}
	}


	//信息输入结束后，则是排序
	sort(stu, stu + _stu_NUM, cmpStu);

	//因为可能出现排名相同的情况，所以我们对排好序的列表的排名进行处理
	for (int i = 0; i < _stu_NUM; i++)
	{
		if (i > 0 && stu[i].Sum == stu[i - 1].Sum && stu[i].GE == stu[i - 1].GE)
		{
			//--并列--
			stu[i]._rank_stu = stu[i - 1]._rank_stu;
		}
		else
			//--i是会递增的--
			stu[i]._rank_stu = i; //如果不要这个else会怎么样？
								  //---如果没有这个else,那么每次if中判断好的排名rank，都会被重新打乱。。。
	}
	//***stu的ID和rank都是拿i j 这些下标索引来表示并进行初始化


	for (int i = 0; i < _stu_NUM; i++)
	{
		for (int j = 0; j < _volu_NUM; j++)
		{
			//for循环开始前，通过for循环的指标，初始化很多需要判断（用在if中的）变量
			int _current_stu = stu[i]._volu_school[j];//---表示第i个学生的第j个志愿学校
													  //---学校也是用i j k这些下标来表示的

			/*int _now_ppl = _accecpted_NUM[j];*/
			//---都忘记还有个school结构体了。。。

			/*int _now_ppl = sch[j]._actual_Num;
			int _last = sch[j]._last_one;*/

			//---又错了，_current_stu是学生struct中的学校指标

			//---使用学生结构体中的学校指标，来作为school结构体中的下标索引
			//---这个操作太秀了
			int _now_ppl = sch[_current_stu]._actual_Num;
			int _last = sch[_current_stu]._last_one;

			//录取的条件是该学校的人数未满，或者，最后一个录取的考生与当前考生的排名 相同
			if (_now_ppl < sch[_current_stu]._quota ||
				(stu[i]._rank_stu == stu[_last]._rank_stu && _last != -1)) 
			{
				//***录取学生的操作是学校完成的
				//***所以录取学生时信息的更新是学校的结构体来完成

				//---第currentStu个学校录取了该学生---
				//---将考生编号存储进该学校的已招生编号中---
				sch[_current_stu]._accecpted_ID[_now_ppl] = i;
				
				//---当前该学校的最后一个录取考生变为i，也就是当前考生---
				//***lastOne在这里更新了***
				sch[_current_stu]._last_one = i;  //!!! i虽然是下标，但是在code中就代表着每一位考生
				
				//---实际招生人数加1---
				sch[_current_stu]._actual_Num++;

				break;//   为什么要 break?
					  //----break是跳出当前这个循环
					  //---因为最外层的for循环是学生，第二层循环是志愿学校
					  //---当学生被录取后，i学生的学校已经定了，不需要再在当前这个for循环中继续操作了
					  //---但是要进入到下个for循环中，完成学校招生信息的存储
					  //---所以使用break直接跳出当前for循环，进行下个for循环
					  //---然后开始下一个student的录取工作！
			}
		}
	}

	for (int k = 0; k < _sch_NUM; k++)
	{
		if (sch[k]._actual_Num > 0)
		{
			//---这次是给第k个学校，招收的所有学生的ID从小到大进行排序---
			sort(sch[k]._accecpted_ID,
				sch[k]._accecpted_ID + sch[k]._actual_Num, cmpID);//***sch[i]表示第i个学校

			for (int i = 0; i < sch[k]._actual_Num; i++)
			{
				printf("%d", stu[sch[k]._accecpted_ID[i]]._ID_stu);

				if (i < sch[k]._actual_Num - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
