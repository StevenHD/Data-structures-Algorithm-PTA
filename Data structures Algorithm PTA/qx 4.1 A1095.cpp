//A1095. Cars on Campus

#include "C.h"

const int maxn = 10010;

struct Car
{
	//--���ƺ�--
	char _plate_number[20];

	//--��¼�е�ʱ��(��sΪ��λ)--
	int time;

	//---status������in����out---
	char status[10];//why���״̬���ֻ��in out, Ϊ��ô�Ǵ�СΪ4���ַ��������أ�
}_all_records[maxn], _valid_records[maxn];//�����ּ�¼�͵����飬һ��Ҫ��Ϊ���м�¼��������Ч�ļ�¼


//---��Ч��¼������---
int _val_num = 0;

//---��Ҫ����һ��map---
map<string, int> _park_Time;//�����ƺ�ӳ�䵽��ͣ��ʱ��

//---дһ������¼�е�ʱ��ת���ɵ�λΪs�ĺ���timeToInt��Ϊ�˺ü���---

int timeToInt(int hour, int minute, int second)
{
	return hour * 3600 + minute * 60 + second;
}


//---дһ�����ƺŵ�cmp������---
bool _cmp_For_Plate_Number(Car a, Car b)
{
	//---�Ȱ����ƺ��ֵ����С�������������ƺ���ͬ����ʱ���С��������---
	if (strcmp(a._plate_number, b._plate_number)) // if�ж�Ϊtrue����������a��b��_plate_number�����
		return strcmp(a._plate_number, b._plate_number) < 0;
	else
		return a.time < b.time;
}


//---��ʱ���С��������---
bool _cmp_For_Time(Car a, Car b)
{
	return a.time < b.time;
}


//---main
int main()
{
	//--�����¼������ѯ��--
	int _records_num;
	int _queries_num;
	scanf("%d %d", &_records_num, &_queries_num);//�����¼���Ͳ�ѯ��

	int hour;
	int minute;
	int second;
	for (int i = 0; i < _records_num; i++)
	{
		/*scanf("%s %d %d %d %s", _all_records[i]._plate_number, &hour, &minute, &second, _all_records[i].status);*/
		scanf("%s %d:%d:%d %s", _all_records[i]._plate_number, &hour, &minute, &second, _all_records[i].status);
		
		//---ת��Ϊ��sΪ��λ---
		_all_records[i].time = timeToInt(hour, minute, second); //���hour minute second��Щ����������
															    //����for�����������
															    //�Ҹо�����
	}

	//---�����ƺź�ʱ������---
	sort(_all_records, _all_records + _records_num, _cmp_For_Plate_Number);

	//---�����ͣ��ʱ��---
	int _max_Park_Time = -1;  //Ϊɶ�������ǻᱻ�����-1,why,�����ҹ���

	//----�������м�¼----
	for (int j = 0; j < _records_num - 1; j++)//****Ϊɶ_records_num Ҫ -1����****
	{
		//--j��j+1��ͬһ������j��in��¼��j+1��out��¼--
		if (!strcmp(_all_records[j]._plate_number, _all_records[j + 1]._plate_number) &&
			!strcmp(_all_records[j].status, "in") &&
			!strcmp(_all_records[j + 1].status, "out"))
		{
			//---˵��j��j+1����Եģ�����valid����---
			_valid_records[_val_num++] = _all_records[j];
			_valid_records[_val_num++] = _all_records[j + 1];

			//--����˴ε�ͣ��ʱ��--
			int _in_Time = _all_records[j + 1].time - _all_records[j].time;

			//---count����0˵��map�л�û��������ƺţ����ó��ƺŵ�parkTime��Ϊ0---
			if (_park_Time.count(_all_records[j]._plate_number) == 0)
			{
				_park_Time[_all_records[j]._plate_number] = 0; //�ж�һ��count(id)��Ȼ����idΪ0
															   //��ʾmap�л�û��������ƺţ���0
															   //�൱�ڴ���map�д洢�ĳ��ƺ�
			}

			//--���Ӹó��ƺŵ���ͣ��ʱ�䣬֮������0����Ϊ�ó��ƺ��� ��һ�� ����--
			_park_Time[_all_records[j]._plate_number] += _in_Time; // []���������ʼ�����±�
																   // Ҳ����Ѱ������ʱ�������
			
			//---����ÿ��carͣ����ʱ���maxֵ---
			_max_Park_Time = max(_max_Park_Time, _park_Time[_all_records[j]._plate_number]);
		}
	}

	// ��valid records��������
	// ����Ч��¼��ʱ���С�����������
	sort(_valid_records, _valid_records + _val_num, _cmp_For_Time);

	
	//����һ��now��int�ͱ�����ָ�򲻳�����ǰ��ѯʱ��ļ�¼
	//��һ��_num_Car��ʾ��ǰУ԰�ڳ�����

	int _now_records = 0;
	int _car_now_campus = 0;

	//���ڵ��˲�ѯ�׶Σ�������Ҫ�õ�һ��ʼ����Ĳ�ѯ��¼��
	for (int i = 0; i < _queries_num; i++)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		int _time_Queries = timeToInt(hour, minute, second);

		//��_now_records��Ϊ�±��������Ž�_valid_records�У����д���ֱ�� �±�ﵽ ��ǰ��ѯʱ��
		while (_now_records < _val_num && _valid_records[_now_records].time <= _time_Queries)
		{
			if (!strcmp(_valid_records[_now_records].status, "in"))
				_car_now_campus++;  //ִ�����if��ʾ������in״̬��Ҳ���ǳ�������
			else
				_car_now_campus--;  //��else�Ļ�˵����out״̬����ʾ�����뿪

			_now_records++; // ������¼�����ָ꣬����һ����¼
						    // �о����whileѭ����forһ��ë����û�а�
						    // �ѵ�����Ϊ����??
		}
		printf("%d\n", _car_now_campus);// Ϊʲô������ط�������� ��ʱ��У԰�ڵĳ������أ�
										// ��Ϊ����������_time_Queries����ʾһ��ʱ����ֵ
										// �����ʱ����ֵ�У������������ߣ�whileִ�����
										// �պ������ʱ������ĳ���������������
										// ��ĩβ�����ʱ�̵ĳ�����
	}

	map<string, int>::iterator it; //����һ����������Ŀ���Ǳ������еĳ��ƺ�
	for (it = _park_Time.begin(); it != _park_Time.end(); it++)
	{
		if (it->second == _max_Park_Time)
		{
			//---����������ͣ��ʱ��ĳ��ƺ�---
			printf("%s ", it->first.c_str());// �������first��second��ʲô��c_str()����ʲô?
		}
	}

	//---��������������ͣ��ʱ��---
	printf("%02d:%02d:%02d\n", _max_Park_Time / 3600, _max_Park_Time % 3600 / 60, _max_Park_Time % 60);

	return 0;
}