//A1077. Kuchiguse

//------CODE------

#include "C.h"

//---����100���ַ�����ÿ���ַ�������256���ַ�---
char _input_String[100][256];   // ���ڵ������������ȫ�ֵĺ�һЩ

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
	//--N���ַ����ĸ���--
	scanf("%d", &N);

	//--���ջ��з�--
	getchar();

	// ��Ϊ��ÿ���ַ����� ÿ���ַ� ��Ҫ�����о�������˵���ǽ�����ÿ���ַ����Ĳ����ŵ�forѭ������
	// �Ӷ�һ����һ�εĶ��������о�
	for (int i = 0; i < N; i++)
	{
		gets_s(_input_String[i]);

		int len = strlen(_input_String[i]);

		// ���ϵ������minLen�ĸ���
		//--ȡ��С����--
		if (len < minLen)
			minLen = len;

		//Ϊ�˺�˼�������ַ�����ת���Զ���һ��reverse����.
		/*_reverse_Str(_input_String[i], minLen);*/ //��˵����������ݲ���Ҫpass by reference�
													//��˵����������ݲ���Ҫpass by reference�
													//P72ҳ
		//---��ת�ַ���s[i]��ת��Ϊ�󹫹�ǰ׺---
		_reverse_Str(_input_String[i], len); 
	}

	/*bool _is_Same = false;*/
	/*bool _is_Same = true;*/
	int _common_Len = 0;

	
	char _common_Str[256]; // ����Ҫһ����������Ź����ַ�����
	
	//---�ж������ַ����ĵ�i���ַ��Ƿ�ȫ�����---
	for (int i = 0; i < minLen; i++) // ������Ȼ�ǶԵ����ַ������в�������
	{
		//---ȡ��һ���ַ����ĵ�i���ַ�---
		char _preferred_char = _input_String[0][i];
		bool _is_Same = true;

		/*for (int j = 0; j < N; j++)*/

		// ������߼����������ó���һ���ַ����ĵ�[0]���ַ���Ȼ���2����3���ַ�����[0]���ַ���֮�Ƚ�
		// �Ƚ�������ó���1���ַ���[1]���ַ�����ʣ���ַ�����[1]���ַ��Ƚ�

		//---�ж������ַ����ĵ�i���ַ��Ƿ����c---
		for (int j = 1; j < N; j++)
		{
			/*if (_input_String[j][i] == _preferred_char)*/
			/*if (_input_String[j][i] == _preferred_char)*/

			//---ֻҪ��һ�����ȣ���ֹͣö�٣�˵������ǰ׺����Ϊֹ---
			if (_preferred_char != _input_String[j][i])
			/*if (_preferred_char == _input_String[j][i])*/
			{
				_is_Same = false;
				break;
				/*_is_Same = true;*/
				/*_common_Len++;*/
				//Ӧ�õȳ�ȥ��һ����������ַ�����[0]���ַ��Ƚ����ˣ��ٽ���commonLen++

				/*_common_Str[i] = _preferred_char;*/
				//��������Բ�Ҫ
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

		//---�������ַ����ĵ�iλ��ȣ��������_common_len��1---
		if (_is_Same)
			_common_Len++;//Ӧ��Ҫ�������ַ�����[0]��λ���ж��꣬���ܽ���++����
		else
			break; // break��������ô������Щѭ����

	}

	if (_common_Len)
	{
		for (int i = _common_Len - 1; i >= 0; i--)
		{
			/*printf("%d", _common_Str[i]);*/
			//��TM��֪��������ֵ�������������ˣ���
			/*printf("%c", _common_Str[i]);*/
			/*printf("%s", _common_Str[i]);*/
			/*printf("%s", _input_String[i]);*/

			//wo Tm ��ɵ�ˣ���Ȼ�����˶�ά���飬�����һ���ַ�����Ҫ�޶�һ��λ��
			//д��_input_String[i]�����ɶҲ���ǣ�
			//���ҵ����ַ��϶��� %c ����
			printf("%c", _input_String[0][i]);
		}
	}

	else
		//---�����ڹ���ǰ׺---
		printf("nai");

	return 0;

}