// A1075. PAT Judge

#include "C.h"

const int maxn = 100010;

struct testee
{
	//---准考证号---
	int id;

	//---每道题的得分---
	/*int _indi_score;*/
	int _indi_score[6];  // 这个[]中的6表示什么？

	//---是否有能通过编译的提交---
	bool _pass_compile;

	//---总分---
	int _total_score;

	//---完美解题数---
	int _perfect_methods;
}stu[maxn];

int _testee_nums;
int _problem_nums;
int _record_nums;

//---每道题的满分---
int _each_problem_full[6]; // 为什么每道题的满分定义成数组，而且是6? 
						   // 也许是因为一共有4道题，数组的大小要比4大一些

bool cmp(testee	a, testee b)
{
	//---输出总分比较高的---
	//---输出完美解题数更多的---
	//---准考证号从小到大排序---
	if (a._total_score != b._total_score)
		return a._total_score > b._total_score;
	else if (a._perfect_methods != b._perfect_methods)
		return a._perfect_methods > b._perfect_methods;
	else
		return a.id < b.id;
}

//---初始化---
void init()
{
	for (int i = 1; i <= _testee_nums; i++)
	{
		//---准考证号就是序号1 2 3 4 5等等---
		stu[i].id = i;

		//---总成绩和完美解题数都初始化为0---
		stu[i]._total_score = 0;
		stu[i]._perfect_methods = 0;

		//---初始化为没有能通过编译的提交---
		stu[i]._pass_compile = false;

		//---每一个学生的成绩，也就是题目得分，因为indi_score[]是个一维数组---
		//---indi_score[0]表示第一道题的得分，indi_score[1]表示第二道题的得分等等---
		//---这些都初始化为-1，这个简写需要注意一下，就是indi_score得分的初始化---
		memset(stu[i]._indi_score, -1, sizeof(stu[i]._indi_score));
	}
}

int main()
{
	//---test用例的输入是7 4 20---
	//---表示7个学生，4道题，一共有20条提交记录---
	scanf("%d%d%d", &_testee_nums, &_problem_nums, &_record_nums);

	init();

	//---这个输入4道题目，每个题目的满分---
	//---分别是20 25 25 30---
	for (int i = 1; i <= _problem_nums; i++)
	{
		scanf("%d", &_each_problem_full[i]);
	}

	//---下面三个分别是题目ID，考生ID，所获分值---
	int _pro_id, _testee_id, _obtained_score;

	//---接下来是针对每一条record记录，来进行分值的处理---
	for (int j = 0; j < _record_nums; j++)
	{
		scanf("%d%d%d", &_testee_id, &_pro_id, &_obtained_score);

		//---如果所获分值是-1，则表示 提交记录 是-1，也就是编译无法通过---
		//---所以如果 提交记录 上是-1，那么_pass_compile就是false---
		//---但重点是依然要在分数显示上，显示为0分，因为就算不通过，但还是提交了，只是没做对---
		if (_obtained_score != -1)
			stu[_testee_id]._pass_compile = true;

		//---obtained_score表示的是当前for循环中，该条提交记录上的得分是-1---
		//---indi_score表示的则是该考生在这个时候的题目总得分，初始化init()中置为-1了---
		if (_obtained_score == -1 && stu[_testee_id]._indi_score[_pro_id] == -1)
			
			//----某题第一次编译错误，分值记为0分，便于输出----
			stu[_testee_id]._indi_score[_pro_id] = 0; //***
													  //判断条件2没看懂欸...
													  //*** 在这里将成绩置为0了

		//---当前提交记录中某题目的得分obtained_score是满分---
		//---当前这条 提交记录 中，该考生做的这道题的得分比这道题的满分少---
		//---如果满足上面这样，说明该考生做这道题是第一次获得满分，那么完美解题数+1---
		//***我的疑惑在于，怎么没把该考生该题目的得分更新啊？？*** 
		if (_obtained_score == _each_problem_full[_pro_id] 
			&& stu[_testee_id]._indi_score[_pro_id] < _each_problem_full[_pro_id])

			stu[_testee_id]._perfect_methods++;//***
											   //我就是不明白，obtained_score和stu结构体中的score有什么区别？
											   //既然某道题拿满分了，那为什么这个学生的这道题的得分并不是满分？
											   //***

		//***
		/*if (_obtained_score > _each_problem_full[_pro_id])*/
		//---某题获得更高分值，则覆盖---
		//---这个也解答了上面的疑惑，这里将该考生该题目的 满分 给了indi_score，下次就不会让完美数+1了---
		if (_obtained_score > stu[_testee_id]._indi_score[_pro_id])
			stu[_testee_id]._indi_score[_pro_id] = _obtained_score;
		//***
	}

	//----这里是计算总分----
	//---每个考生是外层循环---
	//---每个考生的每道题目得分的叠加则是内层循环---
	for (int k = 1; k <= _testee_nums; k++)
	{
		for (int m = 1; m <= _problem_nums; m++)
		{
			//---如果indi_score一直是-1，则表明提交记录就没有它---
			//***这个if判断竟然忘记了加...
			if (stu[k]._indi_score[m] != -1)
				//***

			{
				stu[k]._total_score += stu[k]._indi_score[m];
			}
		}
	}

	sort(stu + 1, stu + 1 + _testee_nums, cmp);

	int _current_rank = 1;

	/*for (int i = 1; i <= _testee_nums; i++)*/
	for (int i = 1; i <= _testee_nums && stu[i]._pass_compile == true; i++)

	{
		//---如果i是2，如果stu[2]的成绩不等于stu[1]的成绩，那么它一定是第2名---
		//---如果stu[1]和stu[2]的成绩一样，则current_rank不变，两个人都是第1名---
		if (i > 1)
		{
			if (stu[i]._total_score != stu[i - 1]._total_score)
				_current_rank = i;
		}

		printf("%d %05d %d", _current_rank, stu[i].id, stu[i]._total_score);

		//---下面是输入每个学生的每道题目的得分---
		//***
		/*for (int j = 1; j <= _problem_nums; i++)*/
		for (int j = 1; j <= _problem_nums; j++)
			//***

		{
			if (stu[i]._indi_score[j] == -1)
				printf(" -");
			else
				printf(" %d", stu[i]._indi_score[j]);

			//if (stu[i]._pass_compile == false)//对这个_pass_compile的编译没太明白???
			//								  //如果做到针对每个学生每道题的状态呢？
			//	printf("0"); //***那成绩0是怎么输出的？？

		}
		printf("\n");

	}
	return 0;
}



//---------------------疑问-----------------------------
// 这道题没有太明白，看着很乱，
// 第一就是score_obtained和stu.score有什么区别？--已解决

//还有就是输出0和-的区别 --已解决

//还有就是里面的对应，感觉真的有些乱。。。 --已解决