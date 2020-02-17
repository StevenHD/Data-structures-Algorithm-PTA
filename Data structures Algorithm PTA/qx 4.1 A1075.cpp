// A1075. PAT Judge

#include "C.h"

const int maxn = 100010;

struct testee
{
	//---׼��֤��---
	int id;

	//---ÿ����ĵ÷�---
	/*int _indi_score;*/
	int _indi_score[6];  // ���[]�е�6��ʾʲô��

	//---�Ƿ�����ͨ��������ύ---
	bool _pass_compile;

	//---�ܷ�---
	int _total_score;

	//---����������---
	int _perfect_methods;
}stu[maxn];

int _testee_nums;
int _problem_nums;
int _record_nums;

//---ÿ���������---
int _each_problem_full[6]; // Ϊʲôÿ��������ֶ�������飬������6? 
						   // Ҳ������Ϊһ����4���⣬����Ĵ�СҪ��4��һЩ

bool cmp(testee	a, testee b)
{
	//---����ֱܷȽϸߵ�---
	//---������������������---
	//---׼��֤�Ŵ�С��������---
	if (a._total_score != b._total_score)
		return a._total_score > b._total_score;
	else if (a._perfect_methods != b._perfect_methods)
		return a._perfect_methods > b._perfect_methods;
	else
		return a.id < b.id;
}

//---��ʼ��---
void init()
{
	for (int i = 1; i <= _testee_nums; i++)
	{
		//---׼��֤�ž������1 2 3 4 5�ȵ�---
		stu[i].id = i;

		//---�ܳɼ�����������������ʼ��Ϊ0---
		stu[i]._total_score = 0;
		stu[i]._perfect_methods = 0;

		//---��ʼ��Ϊû����ͨ��������ύ---
		stu[i]._pass_compile = false;

		//---ÿһ��ѧ���ĳɼ���Ҳ������Ŀ�÷֣���Ϊindi_score[]�Ǹ�һά����---
		//---indi_score[0]��ʾ��һ����ĵ÷֣�indi_score[1]��ʾ�ڶ�����ĵ÷ֵȵ�---
		//---��Щ����ʼ��Ϊ-1�������д��Ҫע��һ�£�����indi_score�÷ֵĳ�ʼ��---
		memset(stu[i]._indi_score, -1, sizeof(stu[i]._indi_score));
	}
}

int main()
{
	//---test������������7 4 20---
	//---��ʾ7��ѧ����4���⣬һ����20���ύ��¼---
	scanf("%d%d%d", &_testee_nums, &_problem_nums, &_record_nums);

	init();

	//---�������4����Ŀ��ÿ����Ŀ������---
	//---�ֱ���20 25 25 30---
	for (int i = 1; i <= _problem_nums; i++)
	{
		scanf("%d", &_each_problem_full[i]);
	}

	//---���������ֱ�����ĿID������ID�������ֵ---
	int _pro_id, _testee_id, _obtained_score;

	//---�����������ÿһ��record��¼�������з�ֵ�Ĵ���---
	for (int j = 0; j < _record_nums; j++)
	{
		scanf("%d%d%d", &_testee_id, &_pro_id, &_obtained_score);

		//---��������ֵ��-1�����ʾ �ύ��¼ ��-1��Ҳ���Ǳ����޷�ͨ��---
		//---������� �ύ��¼ ����-1����ô_pass_compile����false---
		//---���ص�����ȻҪ�ڷ�����ʾ�ϣ���ʾΪ0�֣���Ϊ���㲻ͨ�����������ύ�ˣ�ֻ��û����---
		if (_obtained_score != -1)
			stu[_testee_id]._pass_compile = true;

		//---obtained_score��ʾ���ǵ�ǰforѭ���У������ύ��¼�ϵĵ÷���-1---
		//---indi_score��ʾ�����Ǹÿ��������ʱ�����Ŀ�ܵ÷֣���ʼ��init()����Ϊ-1��---
		if (_obtained_score == -1 && stu[_testee_id]._indi_score[_pro_id] == -1)
			
			//----ĳ���һ�α�����󣬷�ֵ��Ϊ0�֣��������----
			stu[_testee_id]._indi_score[_pro_id] = 0; //***
													  //�ж�����2û�����G...
													  //*** �����ｫ�ɼ���Ϊ0��

		//---��ǰ�ύ��¼��ĳ��Ŀ�ĵ÷�obtained_score������---
		//---��ǰ���� �ύ��¼ �У��ÿ������������ĵ÷ֱ�������������---
		//---�����������������˵���ÿ�����������ǵ�һ�λ�����֣���ô����������+1---
		//***�ҵ��ɻ����ڣ���ôû�Ѹÿ�������Ŀ�ĵ÷ָ��°�����*** 
		if (_obtained_score == _each_problem_full[_pro_id] 
			&& stu[_testee_id]._indi_score[_pro_id] < _each_problem_full[_pro_id])

			stu[_testee_id]._perfect_methods++;//***
											   //�Ҿ��ǲ����ף�obtained_score��stu�ṹ���е�score��ʲô����
											   //��Ȼĳ�����������ˣ���Ϊʲô���ѧ���������ĵ÷ֲ��������֣�
											   //***

		//***
		/*if (_obtained_score > _each_problem_full[_pro_id])*/
		//---ĳ���ø��߷�ֵ���򸲸�---
		//---���Ҳ�����������ɻ����ｫ�ÿ�������Ŀ�� ���� ����indi_score���´ξͲ�����������+1��---
		if (_obtained_score > stu[_testee_id]._indi_score[_pro_id])
			stu[_testee_id]._indi_score[_pro_id] = _obtained_score;
		//***
	}

	//----�����Ǽ����ܷ�----
	//---ÿ�����������ѭ��---
	//---ÿ��������ÿ����Ŀ�÷ֵĵ��������ڲ�ѭ��---
	for (int k = 1; k <= _testee_nums; k++)
	{
		for (int m = 1; m <= _problem_nums; m++)
		{
			//---���indi_scoreһֱ��-1��������ύ��¼��û����---
			//***���if�жϾ�Ȼ�����˼�...
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
		//---���i��2�����stu[2]�ĳɼ�������stu[1]�ĳɼ�����ô��һ���ǵ�2��---
		//---���stu[1]��stu[2]�ĳɼ�һ������current_rank���䣬�����˶��ǵ�1��---
		if (i > 1)
		{
			if (stu[i]._total_score != stu[i - 1]._total_score)
				_current_rank = i;
		}

		printf("%d %05d %d", _current_rank, stu[i].id, stu[i]._total_score);

		//---����������ÿ��ѧ����ÿ����Ŀ�ĵ÷�---
		//***
		/*for (int j = 1; j <= _problem_nums; i++)*/
		for (int j = 1; j <= _problem_nums; j++)
			//***

		{
			if (stu[i]._indi_score[j] == -1)
				printf(" -");
			else
				printf(" %d", stu[i]._indi_score[j]);

			//if (stu[i]._pass_compile == false)//�����_pass_compile�ı���û̫����???
			//								  //����������ÿ��ѧ��ÿ�����״̬�أ�
			//	printf("0"); //***�ǳɼ�0����ô����ģ���

		}
		printf("\n");

	}
	return 0;
}



//---------------------����-----------------------------
// �����û��̫���ף����ź��ң�
// ��һ����score_obtained��stu.score��ʲô����--�ѽ��

//���о������0��-������ --�ѽ��

//���о�������Ķ�Ӧ���о������Щ�ҡ����� --�ѽ��