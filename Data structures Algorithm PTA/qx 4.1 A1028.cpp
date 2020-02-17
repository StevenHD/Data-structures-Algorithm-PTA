// A1028. List Sorting
#include "C.h"

const int maxn = 100010;
struct Student 
{
	int id;
	char name[10];
	int score;
}stu[maxn];

//--按第一列排序的比较函数--
bool cmp1(Student a, Student b) 
{
	return a.id < b.id;
}

//--按第二列排序的比较函数--
bool cmp2(Student a, Student b) 
{
	int s = strcmp(a.name, b.name);

	//--按 姓名字典序 从小到大排序--
	if (s != 0) 
		return s < 0;
	else 
		return a.id < b.id;
}

//--按第三列排序的比较函数--
bool cmp3(Student a, Student b) 
{
	if (a.score != b.score) 
		return a.score < b.score;
	else 
		return a.id < b.id;
}

int main() 
{
	int n, c;
	scanf("%d%d", &n, &c); // n个学生，按照c列排序

	for (int i = 0; i < n; i++) 
	{
		scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
	}

	if (c == 1) 
		sort(stu, stu + n, cmp1);
	else if (c == 2) 
		sort(stu, stu + n, cmp2);
	else 
		sort(stu, stu + n, cmp3);

	for (int i = 0; i < n; i++) 
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
	return 0;
}

//---写了3个比较函数，3个cmp之间的转换，是通过if...else来实现的---