// A1025. PAT Ranking

#include "C.h"

struct Student 
{
	char id[15];
	int score;

	//--考场号--
	//--考场内排名--
	int location_number;
	int local_rank;
}stu[30010];

bool cmp(Student a, Student b) 
{
	if (a.score != b.score) 
		//--分数则是从高到低排序--
		return a.score > b.score; // 对于数组stu，先按成绩大小排序
	else 
		//--如果a和b的分数相同，则按准考证号从小到大排序--
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
		//--i=2的时候，就要开始输入第2考场学生的信息了--
		scanf("%d", &testeesOfLocations);
		for (int j = 0; j < testeesOfLocations; j++)
		{
			//--第一步输入学生0的id和score--
			//---第二轮中学生0的id和score---
			scanf("%s %d", stu[totalNums].id, &stu[totalNums].score);

			//--然后学生0的考场就是当前的i--
			//---第二轮中，其内学生0的考场就是当前的2考场---
			stu[totalNums].location_number = i;

			//--第一轮中，totalNums就等于第一个考场的考生人数--
			//---第二轮中，totalNums则在第一个考场考生人数的基础上自增---
			//---最后totalNums的数量就是两个考场考生和---
			totalNums++;
		}

		//--所以第一轮sort括号里面的是(stu+0, stu+totalNums, cmp)--
		//---所以第二轮sort括号里面的是(stu+testeeOfLocations1+0, stu+testeeOfLocation1+2, cmp)
		sort(stu + totalNums - testeesOfLocations, stu + totalNums, cmp);

		//--排序完后，stu[0]就是该第一考场第一名--
		//---第二次排序完后，stu[testeesOfLocation1 + 1]也就是后面呢一位，考场内排名是第1名---
		stu[totalNums - testeesOfLocations].local_rank = 1;

		//--第一轮中，j的初值就为1，j < totalNums--
		//--因为第一名已经定好了，所以直接从stu[2]也就是第二名开始排--

		//---第二轮中，j的初值就是testeesOfLocations2最左边的值加1---
		for (int j = totalNums - testeesOfLocations + 1; j < totalNums; j++)
		{
			//--如果第二名和第一名的成绩相同，则并列--
			if (stu[j].score == stu[j - 1].score) 
			{
				stu[j].local_rank = stu[j - 1].local_rank; // 成绩相同一定并列，但是输出时的前后
														   // 则是根据之前的id大小，cmp已经排好了
			}

			//--如果不是并列，第1考场内的排名则为j+1--
			//---如果不是并列，第2考场内的排名则为 1 + 1 = 2 (将for中j的初值带进来)---
			else 
			{
				stu[j].local_rank = j + 1 - (totalNums - testeesOfLocations);
			}
		}
	}
	//----上述for循环的目的就是各自排好两个考场内的排名，将信息存储进去----
	//----特点在于，第二个考场排名是从stu[k]开始的，而不是跟第一考场一样从stu[0]开始的----
	//----因为整体排序后，改变的只是stu[]中的序号，stu[]中存储的值是没有变的----
	//----将local的信息存入了stu结构体变量中的local_rank中----

	printf("%d\n", totalNums);

	//----整体再排一次名----
	sort(stu, stu + totalNums, cmp);

	//----当前考生的排名----
	int r = 1;
	for (int i = 0; i < totalNums; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score) 
		{
			r = i + 1;
		}

		//----第一名跳过呢个if----
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}

//-----因为排序就是说，将一个元素从5放到了2，改变的是地址，但是里面存储的值没有变-----
//-----所以说，访问地址的时候，只不过是地址变了，里面的值不变，可以实现从大到小的排序-----