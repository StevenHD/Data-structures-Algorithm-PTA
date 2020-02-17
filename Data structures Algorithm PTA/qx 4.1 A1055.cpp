// A1055. The World's Richest

#include "C.h"

const int maxn = 100010;

//---ĳ�����������---
int numsOfPeoatCerAge[maxn] = {0};

//int Age[maxn] = { 0 };//��̫�����������Ǹ�ʲô��

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
		//��Ϊ�����Ǹտ�ʼ���룬��������������_total_ppl����Ϣ��������_valid_ppl����Ϣ
	}

	//---���ʱ���Ѿ������ź�����---
	sort(_total_ppl, _total_ppl + num, cmp);

	//--��ΪMΪ100������ֻ��ǰ100���˵���Ϣ���Ա����--
	//--��ˣ�����Ҫ����һ��validppl�����������Щǰ100�˵���Ϣ--

	int _nums_valid = 0;
	for (int j = 0; j < num; j++)
	{
		if (numsOfPeoatCerAge[_total_ppl[j]._indi_age] < 100)
		{
			numsOfPeoatCerAge[_total_ppl[j]._indi_age]++; // Age[i]��ʾ����Ϊiʱ�������������

			//----��������������С��100����ô�ͽ����˵���Ϣ�洢��valid����----
			_valid_ppl[_nums_valid++] = _total_ppl[j];    //---����sortһ��Ҫ������Щǰͷ��
													      //---nums_valid��0������jҲ�Ǵ�0����
													      // Ҫ��������Ӧ�ϣ���һ��Ҫ������
		}
	}


	int _investigate_ppl, ageL, ageR;
	for (int k = 1; k <= _search_times; k++)
	{
		scanf("%d %d %d", &_investigate_ppl, &ageL, &ageR);
		printf("Case #%d:\n", k);

		//--outputNum��ʾ�Ѿ����������--
		//--��Ϊ�� ������� Ҳ�������Ƶ�--
		int _output_Num = 0;
		for (int i = 0; i < _nums_valid && _output_Num < _investigate_ppl; i++)
			//---_nums_valid��ʾ�����valid�����е�����---
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

