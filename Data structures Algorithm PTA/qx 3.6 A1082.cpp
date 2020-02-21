//A1082. Read Number in Chinese

//---------CODE---------

#include "C.h"

char num[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

//char digit[10][5] = {"Ge", "Shi", "Bai", "Qian", "Wan", "Yi"};

//**没有个位**
char digit[10][5] = { "Shi", "Bai", "Qian", "Wan", "Yi" };

int main()
{
	//--输入数字
	//--输入数字是按整型还是字符串，完全看的是需要做什么操作
	//--因为这里需要对每一位进行处理，所以说用字符串好一些

	char _input_num[15];
	gets_s(_input_num);  // 按字符串方式输入数字

	//--字符串长度
	int len = strlen(_input_num);

	//--left和right分别指向字符串首尾元素--
	int left = 0;
	int right = len - 1;//right = len - 1 可能是因为right作为下标，在数组中刚好要-1.

	//--如果是负数，则输出“Fu”，并把left右移1位--
	if (_input_num[0] == '-')
	{
		printf("Fu");
		left++;
	}

	//--将right每次左移4位，直到left与right在同一节--
	while (left + 4 <= right)
	{
		right -= 4;
	}

	//--for循环每次处理这一长串数字的一节，也就是(4位)
	//--(也可能小于4位)
	while (left < len)
	{
		//--flag = false 表示没有累积的0
		bool flag = false; 

		//--_is_Print = false表示该节中没有输出过其中的位
		bool _is_Print = false; 

		//--从左至右处理数字中某节的每一位--
		while (left <= right)
		{
			//--如果当前位是0---
			//--left是下标--
			//--left>0表示当前位不是首位，只有这样，才能让flag为true--
			if (left > 0 && _input_num[left] == '0') 
			{
				flag = true; // 令标记flag为true
			}

			//--如果当前位不为0
			else
			{
				if (flag == true)
				{
					//--但是如果已经存在累积的0--
					printf(" ling"); // 注意：ling 前有个小空格
					flag = false;    // 将标记flag重新置为false非常重要
				}

				//--只要不是首位（包括负号，也就是如果是负数，那么 负号 就算 首位）
				//--后面的每一位前面都要输出空格--
				if (left > 0)  // left > 0 就表示不是首位
					printf(" ");

				//--输出当前位数字--
				printf("%s", num[_input_num[left] - '0']); //**为甚么输出的是字符串还要减'0'?
														   //**我一直以为只有输出的是单个字符才要 -'0'。

				//--该节至少有一位被输出--
				_is_Print = true; // 因为该节至少有一位数字被输出了，所以将_is_Print变成true.

				//--上面digit数组中之所以没有定义个位--
				//--是因为某节中除了个位外，都需要输出十百千--
				if (left != right)
				{
					printf(" %s", digit[right - left - 1]); // 讲真，这行code记住就好
				}
			}

			//--left右移一位
			left++; 	
		}

		// 离开了处理 数字 单节 的步骤
		// 但还是在每次循环处理数字的一节中
		if (_is_Print == true && right != len - 1)
			// 第一个条件看懂了，说的是之前至少已经输出过一位了
			// 第二个条件的意思就是 只要right所指的不是个位，就输出 万 或 亿
		{
			printf(" %s", digit[(len - 1 - right) / 4 + 2]);  //**这行code也是，记住就好**
		}

		// 这一节结束。开始想办法输出 下一节
		// 其实做的所有工作就是输出。按着要求把这些东西输出
		// 处理这类问题的想法就是 吸收输入的东西、将输入的东西进行改装，变得好输出、按着格式输出
		right += 4; // 输出万或亿后，right+4进入下一节
	}

	// 这里才是结束了每次循环处理 数字某一节 的地方

	return 0;
}