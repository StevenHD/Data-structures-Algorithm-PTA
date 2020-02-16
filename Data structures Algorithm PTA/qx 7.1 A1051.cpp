// A1051 Pop Sequence

//---˼·---
// ����1����ʼ��ջ������������Ҫ���Եĳ�ջ���С�
// ʹ��bool�ͱ���flag��ʾ��ջ�����Ƿ�Ϸ������flag=true�����ʾ��ջ���кϷ���
// ���flag=false�����ʾ��ջ���в��Ϸ���
// flag�ĳ�ֵ��Ϊtrue��ʹ��int�ͱ���current��ʾ��ջ�����е�ǰ�ȴ���ջ��Ԫ�ص�λ�ñ�ǣ���ֵΪ1

// ����2����Ϊ��ջ˳��Ϊ1~N�����Դ�1��Nö��i������ÿ��i���Ƚ�i��ջ��
// �����ʱջ��Ԫ����Ŀ����m����mΪ������������������������Υ��������flagΪfalse���˳�ѭ����
// ���򣬷����жϵ�ǰcurrent��ָ ��ջ�����е�Ԫ��(Ҳ���Ǵ���ջԪ��)�Ƿ����ջ��Ԫ�ء�
// ����жϡ��ǡ������ø�Ԫ�س�ջ������current������ָ����һ������ջԪ�ء�

// ����3�������������������ջ����flag=true����˵���ó�ջ˳��Ϸ��������YES��������NO����

#include "C.h"

const int maxn = 1010;

//---������Ŀ�����ĳ�ջ����---
int arr[maxn];

//---����һ��ջst���������int��Ԫ��---
stack<int> st;

int main() 
{
	//--mΪ������nΪԪ�ظ�����TΪ�������еĸ���--
	int m, n, T;
	scanf("%d%d%d", &m, &n, &T);

	//--��Ϊ��T�����Գ�ջ����--
	//--����ѭ��ִ��T��--
	while (T--) 
	{
		//--������ÿ����ջ��������ǰ��һ��Ҫ���ջ--
		//--��������ϸ���ջ���еĽ��û�б���գ���ô��Ӱ���¸���ջ���еĹ���--
		while (!st.empty()) 
		{
			st.pop();
		}

		//--��������--
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &arr[i]);
		}

		//---current����ָ���ջ�����еĴ���ջԪ��---
		int current = 1;  //***Ϊʲôcurrent�ĳ�ֵΪ1��***
						  //**��Ϊ����scanf�����ֵ��ʱ��i�ĳ�ֵΪ1**
		bool flag = true;


		for (int i = 1; i <= n; i++) 
		{
			//--��iѹ��ջ--
			st.push(i);

			if (st.size() > m) 
			{
				//--�����ʱջ��Ԫ�ظ�����������m�������зǷ�--
				flag = false;
				break; //**���breakӦ��ֻ�����������forѭ����whileѭ���ǲ���������**
					   //**��Ϊ��������������ˣ�ֻ��������������в��Ϸ�������������Ķ����Ϸ�**
			}

			//--ջ��Ԫ�����ջ���е�ǰλ�õ�Ԫ����ͬʱ--
			while (!st.empty() && st.top() == arr[current]) // st.top()��ʾջ��Ԫ��
			{
				//--������ջ��ͬʱ��(current++)--
				st.pop(); // ������߷��ϣ��Ͱ�ջst�е�ǰ��ջ��Ԫ��i������
						  // ��Ȼ�Ͳ��ϵ���ջst��ѹ��i
				current++;
			}
		}

		if (st.empty() == true && flag == true) 
		{
			//--ջ����flag=true��ʱ�򣬱����Ϸ�--
			printf("YES\n");
		}

		else 
		{
			printf("NO\n");
		}
	}

	return 0;
}