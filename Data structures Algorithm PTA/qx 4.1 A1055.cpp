// A1055. The World's Richest

#include "C.h"

const int maxn = 100010;

//---某个年龄的人数---
int numsOfPeoatCerAge[maxn] = {0};

//int Age[maxn] = { 0 };//不太理解这个数组是干什么的

struct richMan
{
	int _indi_age;
	int worths;
	char name[20];
}_total_ppl[maxn], _valid_ppl[maxn];

bool cmp(richMan a, richMan b)
{
	if (a.worths != b.worths)
		return a.worths > b.worths;
	else if (a._indi_age != b._indi_age)
		return a._indi_age < b._indi_age;
	else
		return strcmp(a.name, b.name) < 0;
}

int main()
{
	int num;
	int _search_times;
	scanf("%d %d", &num, &_search_times);

	for (int i = 0; i < num; i++)
	{
		scanf("%s %d %d", _total_ppl[i].name, &_total_ppl[i]._indi_age, &_total_ppl[i].worths);
		//因为现在是刚开始输入，所以输入总人数_total_ppl的信息，而不是_valid_ppl的信息
	}

	//---这个时候已经整体排好序了---
	sort(_total_ppl, _total_ppl + num, cmp);

	//--因为M为100，所以只有前100的人的信息可以被输出--
	//--因此，我们要建立一个validppl数组来存放这些前100人的信息--

	int _nums_valid = 0;
	for (int j = 0; j < num; j++)
	{
		if (numsOfPeoatCerAge[_total_ppl[j]._indi_age] < 100)
		{
			numsOfPeoatCerAge[_total_ppl[j]._indi_age]++; // Age[i]表示年龄为i时，该年龄的人数

			//----如果该年龄的人数小于100，那么就将该人的信息存储到valid里面----
			_valid_ppl[_nums_valid++] = _total_ppl[j];    //---排序sort一定要放在这些前头，
													      //---nums_valid从0递增，j也是从0递增
													      // 要是想次序对应上，就一定要先排序
		}
	}


	int _investigate_ppl, ageL, ageR;
	for (int k = 1; k <= _search_times; k++)
	{
		scanf("%d %d %d", &_investigate_ppl, &ageL, &ageR);
		printf("Case #%d:\n", k);

		//--outputNum表示已经输出的人数--
		//--因为对 输出人数 也是有限制的--
		int _output_Num = 0;
		for (int i = 0; i < _nums_valid && _output_Num < _investigate_ppl; i++)
			//---_nums_valid表示存放在valid数组中的人数---
		{
			if (_valid_ppl[i]._indi_age >= ageL && _valid_ppl[i]._indi_age <= ageR)
			{
				printf("%s %d %d\n", _valid_ppl[i].name, _valid_ppl[i]._indi_age, _valid_ppl[i].worths);
				_output_Num++;
			}
		}

		if (_output_Num == 0)
		{
			printf("None!\n");
		}
	}
	return 0;
}

