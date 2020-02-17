// A1080. Graduate Admission �о�����ѧ

#include "C.h"

struct student
{
	int GE;
	int GI;
	int Sum;

	int _rank_stu;
	int _ID_stu;

	//--����ÿ��������K��־Ըѧ���ı��--
	//--voluSchool[0]�ı��Ϊ5��voluSchool[2]�ı��Ϊ1������---
	int _volu_school[10];
}stu[40010];

struct school
{
	//--�����ѧУ���������ܶ��--
	int _quota;

	//--��ǰʵ����������--
	int _actual_Num;

	/*char _accecpted_ID;*/
	/*char _accecpted_ID[40010];*/
	//--���յĿ������--
	//--accID[0]������1��accID[5]������5....---
	int _accecpted_ID[40010]; //??? Ϊʲô��int�����飿����Ϊ�����1 2 5 3 ����

	//--��¼���һ�����յĿ������--
	int _last_one;
}sch[110];

bool cmpStu(student a, student b)
{
	if (a.Sum != b.Sum)
		return a.Sum > b.Sum;
	else
		return a.GE > b.GE;
}

bool cmpID(int c, int d) // c d ���Ǹ�ѧ�����±꣬��ʾ��c��ѧ������d��ѧ��
{
	return stu[c]._ID_stu < stu[d]._ID_stu;
}//�����������д����̫֪����������ܸ���

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

		//������©����2����Ҫ��ʼ����ָ�ꡣ����
		//�����õ���ʱ���ټ���

		//---��ǰʵ����������Ϊ0---
		sch[i]._actual_Num = 0;

		sch[i]._last_one = -1; //---�����һ������ѧ����ѧ����Ŷ�Ϊ-1, ��ʾ������---
							   //***�Ҹ�����Ϊ����_last_oneҪ��Ϊ�±���������-1������Ч���±�
	}

	for (int j = 0; j < _stu_NUM; j++)
	{
		/*scanf("%d %d %d %d %d", &stu[j].GE, &stu[j].GI, &stu[j]._volu_school[0],
			&stu[j]._volu_school[1], & stu[j]._volu_school[2]);*/

			//---���������е�һ��������Ϣ��������������Ҫ��дcodeʱ��Ҳ��Ҫһ���������꣬
			//---�����е�һ����Ϣ��Ҳ���ܷ�Ϊ2���֣���2���ֿ�����Ҫһ���µ�forѭ��������
			//---ֻҪע��һ��\n���з�����

			//***���Ƕ�ѧ����ID���г�ʼ����

		//---�����ı��Ϊj---
		//---Ҳ���� 1 2 3 �ȵ�---
		stu[j]._ID_stu = j;

		scanf("%d %d", &stu[j].GE, &stu[j].GI);

		stu[j].Sum = stu[j].GE + stu[j].GI;

		for (int k = 0; k < _volu_NUM; k++)
		{
			//--���ڿ���j����������k��־ԸѧУ�ı�ţ�0~5֮��---
			scanf("%d", &stu[j]._volu_school[k]);
		}
	}


	//��Ϣ�����������������
	sort(stu, stu + _stu_NUM, cmpStu);

	//��Ϊ���ܳ���������ͬ��������������Ƕ��ź�����б���������д���
	for (int i = 0; i < _stu_NUM; i++)
	{
		if (i > 0 && stu[i].Sum == stu[i - 1].Sum && stu[i].GE == stu[i - 1].GE)
		{
			//--����--
			stu[i]._rank_stu = stu[i - 1]._rank_stu;
		}
		else
			//--i�ǻ������--
			stu[i]._rank_stu = i; //�����Ҫ���else����ô����
								  //---���û�����else,��ôÿ��if���жϺõ�����rank�����ᱻ���´��ҡ�����
	}
	//***stu��ID��rank������i j ��Щ�±���������ʾ�����г�ʼ��


	for (int i = 0; i < _stu_NUM; i++)
	{
		for (int j = 0; j < _volu_NUM; j++)
		{
			//forѭ����ʼǰ��ͨ��forѭ����ָ�꣬��ʼ���ܶ���Ҫ�жϣ�����if�еģ�����
			int _current_stu = stu[i]._volu_school[j];//---��ʾ��i��ѧ���ĵ�j��־ԸѧУ
													  //---ѧУҲ����i j k��Щ�±�����ʾ��

			/*int _now_ppl = _accecpted_NUM[j];*/
			//---�����ǻ��и�school�ṹ���ˡ�����

			/*int _now_ppl = sch[j]._actual_Num;
			int _last = sch[j]._last_one;*/

			//---�ִ��ˣ�_current_stu��ѧ��struct�е�ѧУָ��

			//---ʹ��ѧ���ṹ���е�ѧУָ�꣬����Ϊschool�ṹ���е��±�����
			//---�������̫����
			int _now_ppl = sch[_current_stu]._actual_Num;
			int _last = sch[_current_stu]._last_one;

			//¼ȡ�������Ǹ�ѧУ������δ�������ߣ����һ��¼ȡ�Ŀ����뵱ǰ���������� ��ͬ
			if (_now_ppl < sch[_current_stu]._quota ||
				(stu[i]._rank_stu == stu[_last]._rank_stu && _last != -1)) 
			{
				//***¼ȡѧ���Ĳ�����ѧУ��ɵ�
				//***����¼ȡѧ��ʱ��Ϣ�ĸ�����ѧУ�Ľṹ�������

				//---��currentStu��ѧУ¼ȡ�˸�ѧ��---
				//---��������Ŵ洢����ѧУ�������������---
				sch[_current_stu]._accecpted_ID[_now_ppl] = i;
				
				//---��ǰ��ѧУ�����һ��¼ȡ������Ϊi��Ҳ���ǵ�ǰ����---
				//***lastOne�����������***
				sch[_current_stu]._last_one = i;  //!!! i��Ȼ���±꣬������code�оʹ�����ÿһλ����
				
				//---ʵ������������1---
				sch[_current_stu]._actual_Num++;

				break;//   ΪʲôҪ break?
					  //----break��������ǰ���ѭ��
					  //---��Ϊ������forѭ����ѧ�����ڶ���ѭ����־ԸѧУ
					  //---��ѧ����¼ȡ��iѧ����ѧУ�Ѿ����ˣ�����Ҫ���ڵ�ǰ���forѭ���м���������
					  //---����Ҫ���뵽�¸�forѭ���У����ѧУ������Ϣ�Ĵ洢
					  //---����ʹ��breakֱ��������ǰforѭ���������¸�forѭ��
					  //---Ȼ��ʼ��һ��student��¼ȡ������
			}
		}
	}

	for (int k = 0; k < _sch_NUM; k++)
	{
		if (sch[k]._actual_Num > 0)
		{
			//---����Ǹ���k��ѧУ�����յ�����ѧ����ID��С�����������---
			sort(sch[k]._accecpted_ID,
				sch[k]._accecpted_ID + sch[k]._actual_Num, cmpID);//***sch[i]��ʾ��i��ѧУ

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
