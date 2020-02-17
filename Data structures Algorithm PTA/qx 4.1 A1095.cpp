//A1095. Cars on Campus

#include "C.h"

const int maxn = 10010;

struct Car
{
	//--车牌号--
	char _plate_number[20];

	//--记录中的时刻(以s为单位)--
	int time;

	//---status可能是in或者out---
	char status[10];//why这个状态如果只是in out, 为甚么是大小为4的字符型数组呢？
}_all_records[maxn], _valid_records[maxn];//像这种记录型的数组，一般要分为所有记录，还有有效的记录


//---有效记录的条数---
int _val_num = 0;

//---需要定义一个map---
map<string, int> _park_Time;//将车牌号映射到总停留时间

//---写一个将记录中的时间转换成单位为s的函数timeToInt，为了好计算---

int timeToInt(int hour, int minute, int second)
{
	return hour * 3600 + minute * 60 + second;
}


//---写一个车牌号的cmp排序函数---
bool _cmp_For_Plate_Number(Car a, Car b)
{
	//---先按车牌号字典序从小到大排序，若车牌号相同，则按时间从小到大排序---
	if (strcmp(a._plate_number, b._plate_number)) // if判断为true的条件则是a和b的_plate_number不相等
		return strcmp(a._plate_number, b._plate_number) < 0;
	else
		return a.time < b.time;
}


//---按时间从小到大排序---
bool _cmp_For_Time(Car a, Car b)
{
	return a.time < b.time;
}


//---main
int main()
{
	//--定义记录数、查询数--
	int _records_num;
	int _queries_num;
	scanf("%d %d", &_records_num, &_queries_num);//输入记录数和查询数

	int hour;
	int minute;
	int second;
	for (int i = 0; i < _records_num; i++)
	{
		/*scanf("%s %d %d %d %s", _all_records[i]._plate_number, &hour, &minute, &second, _all_records[i].status);*/
		scanf("%s %d:%d:%d %s", _all_records[i]._plate_number, &hour, &minute, &second, _all_records[i].status);
		
		//---转换为以s为单位---
		_all_records[i].time = timeToInt(hour, minute, second); //这个hour minute second这些东西的声明
															    //放在for里面会怎样？
															    //我感觉可以
	}

	//---按车牌号和时间排序---
	sort(_all_records, _all_records + _records_num, _cmp_For_Plate_Number);

	//---定义最长停留时间---
	int _max_Park_Time = -1;  //为啥这种总是会被定义成-1,why,得找找规律

	//----遍历所有记录----
	for (int j = 0; j < _records_num - 1; j++)//****为啥_records_num 要 -1？？****
	{
		//--j和j+1是同一辆车，j是in记录，j+1是out记录--
		if (!strcmp(_all_records[j]._plate_number, _all_records[j + 1]._plate_number) &&
			!strcmp(_all_records[j].status, "in") &&
			!strcmp(_all_records[j + 1].status, "out"))
		{
			//---说明j和j+1是配对的，存入valid数组---
			_valid_records[_val_num++] = _all_records[j];
			_valid_records[_val_num++] = _all_records[j + 1];

			//--定义此次的停留时间--
			int _in_Time = _all_records[j + 1].time - _all_records[j].time;

			//---count等于0说明map中还没有这个车牌号，将该车牌号的parkTime置为0---
			if (_park_Time.count(_all_records[j]._plate_number) == 0)
			{
				_park_Time[_all_records[j]._plate_number] = 0; //判断一下count(id)，然后置id为0
															   //表示map中还没有这个车牌号，置0
															   //相当于处理map中存储的车牌号
			}

			//--增加该车牌号的总停留时间，之所以置0是因为该车牌号是 第一次 出现--
			_park_Time[_all_records[j]._plate_number] += _in_Time; // []里面的内容始终是下标
																   // 也就是寻找数据时候的依据
			
			//---更新每个car停留总时间的max值---
			_max_Park_Time = max(_max_Park_Time, _park_Time[_all_records[j]._plate_number]);
		}
	}

	// 对valid records进行排序
	// 将有效记录按时间从小到大进行排序
	sort(_valid_records, _valid_records + _val_num, _cmp_For_Time);

	
	//定义一个now的int型变量，指向不超过当前查询时间的记录
	//和一个_num_Car表示当前校园内车辆数

	int _now_records = 0;
	int _car_now_campus = 0;

	//现在到了查询阶段，所以需要用到一开始定义的查询记录数
	for (int i = 0; i < _queries_num; i++)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		int _time_Queries = timeToInt(hour, minute, second);

		//让_now_records作为下标索引，放进_valid_records中，进行处理，直到 下标达到 当前查询时间
		while (_now_records < _val_num && _valid_records[_now_records].time <= _time_Queries)
		{
			if (!strcmp(_valid_records[_now_records].status, "in"))
				_car_now_campus++;  //执行这个if表示车辆是in状态，也就是车辆进入
			else
				_car_now_campus--;  //到else的话说明是out状态，表示车辆离开

			_now_records++; // 这条记录处理完，指向下一条记录
						    // 感觉这个while循环用for一点毛病都没有啊
						    // 难道是因为性能??
		}
		printf("%d\n", _car_now_campus);// 为什么在这个地方可以输出 该时刻校园内的车辆数呢？
										// 因为我们这里有_time_Queries，表示一个时间阈值
										// 在这个时间阈值中，车辆来来走走，while执行完后，
										// 刚好是这个时间区间的车辆总数，所以在
										// 最末尾输出该时刻的车辆数
	}

	map<string, int>::iterator it; //定义一个迭代器，目的是遍历所有的车牌号
	for (it = _park_Time.begin(); it != _park_Time.end(); it++)
	{
		if (it->second == _max_Park_Time)
		{
			//---输出所有最长总停留时间的车牌号---
			printf("%s ", it->first.c_str());// 这里面的first和second是什么？c_str()又是什么?
		}
	}

	//---输出车辆的最长的总停留时间---
	printf("%02d:%02d:%02d\n", _max_Park_Time / 3600, _max_Park_Time % 3600 / 60, _max_Park_Time % 60);

	return 0;
}