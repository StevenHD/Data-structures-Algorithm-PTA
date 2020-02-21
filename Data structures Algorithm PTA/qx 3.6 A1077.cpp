//A1077. Kuchiguse

//------CODE------

#include "C.h"

//---至多100个字符串，每个字符串至多256个字符---
char _input_String[100][256];   // 现在的声明都定义成全局的好一些

int minLen = 256;
int N;

void _reverse_Str(char s[], int len)
{
	for (int h = 0; h < len / 2; h++)
	{
		int temp = s[h];
		s[h] = s[len - 1 - h];
		s[len - 1 - h] = temp;
	}
}

int main()
{
	//--N是字符串的个数--
	scanf("%d", &N);

	//--接收换行符--
	getchar();

	// 因为对每个字符串的 每个字符 都要深入研究，所以说我们将输入每个字符串的操作放到for循环里面
	// 从而一次又一次的对它进行研究
	for (int i = 0; i < N; i++)
	{
		gets_s(_input_String[i]);

		int len = strlen(_input_String[i]);

		// 不断地来完成minLen的更新
		//--取最小长度--
		if (len < minLen)
			minLen = len;

		//为了好思考，将字符串反转，自定义一个reverse函数.
		/*_reverse_Str(_input_String[i], minLen);*/ //话说这个参数传递不需要pass by reference嘛？
													//话说这个参数传递不需要pass by reference嘛？
													//P72页
		//---反转字符串s[i]，转化为求公共前缀---
		_reverse_Str(_input_String[i], len); 
	}

	/*bool _is_Same = false;*/
	/*bool _is_Same = true;*/
	int _common_Len = 0;

	
	char _common_Str[256]; // 还需要一个数组来存放公共字符串段
	
	//---判断所有字符串的第i个字符是否全部相等---
	for (int i = 0; i < minLen; i++) // 现在依然是对单个字符串进行操作处理
	{
		//---取第一个字符串的第i个字符---
		char _preferred_char = _input_String[0][i];
		bool _is_Same = true;

		/*for (int j = 0; j < N; j++)*/

		// 这个的逻辑是这样，拿出第一个字符串的第[0]号字符，然后第2个第3个字符串的[0]号字符与之比较
		// 比较完后，再拿出第1个字符的[1]号字符，和剩下字符串的[1]号字符比较

		//---判断其余字符串的第i个字符是否等于c---
		for (int j = 1; j < N; j++)
		{
			/*if (_input_String[j][i] == _preferred_char)*/
			/*if (_input_String[j][i] == _preferred_char)*/

			//---只要有一个不等，就停止枚举，说明公共前缀到此为止---
			if (_preferred_char != _input_String[j][i])
			/*if (_preferred_char == _input_String[j][i])*/
			{
				_is_Same = false;
				break;
				/*_is_Same = true;*/
				/*_common_Len++;*/
				//应该等除去第一个外的所有字符串的[0]号字符比较完了，再进行commonLen++

				/*_common_Str[i] = _preferred_char;*/
				//这句代码可以不要
				/*_common_Len++;*/
				//break;
			}
		/*	else
			{
				_is_Same = false;
				break;
			}*/

			/*else
			{
				_is_Same = false;
				break;
			}*/

		}

		//---若所有字符串的第i位相等，则计数器_common_len加1---
		if (_is_Same)
			_common_Len++;//应该要等所有字符串的[0]号位置判断完，才能进行++操作
		else
			break; // break到底是怎么跳出哪些循环？

	}

	if (_common_Len)
	{
		for (int i = _common_Len - 1; i >= 0; i--)
		{
			/*printf("%d", _common_Str[i]);*/
			//我TM就知道输出数字的问题出在这里了！！
			/*printf("%c", _common_Str[i]);*/
			/*printf("%s", _common_Str[i]);*/
			/*printf("%s", _input_String[i]);*/

			//wo Tm 人傻了，竟然忘记了二维数组，输出第一个字符串需要限定一下位置
			//写个_input_String[i]输出的啥也不是！
			//而且单个字符肯定是 %c 啊！
			printf("%c", _input_String[0][i]);
		}
	}

	else
		//---不存在公共前缀---
		printf("nai");

	return 0;

}