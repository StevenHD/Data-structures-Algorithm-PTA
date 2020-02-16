// A1051 Pop Sequence

//---思路---
// 步骤1：初始化栈，用来读入需要测试的出栈序列。
// 使用bool型变量flag表示出栈序列是否合法，如果flag=true，则表示出栈序列合法；
// 如果flag=false，则表示出栈序列不合法。
// flag的初值定为true，使用int型变量current表示出栈序列中当前等待出栈的元素的位置标记，初值为1

// 步骤2：因为入栈顺序为1~N，所以从1至N枚举i。对于每个i，先将i入栈。
// 如果此时栈内元素数目大于m个，m为题干中所允许的最大容量，则违反规则，置flag为false，退出循环。
// 否则，反复判断当前current所指 出栈序列中的元素(也就是待出栈元素)是否等于栈顶元素。
// 如果判断“是”，则让该元素出栈，并让current自增以指向下一个待出栈元素。

// 步骤3：如果上述操作结束后，栈空且flag=true，则说明该出栈顺序合法，输出“YES”；否则“NO”。

#include "C.h"

const int maxn = 1010;

//---保存题目给定的出栈序列---
int arr[maxn];

//---定义一个栈st，用来存放int型元素---
stack<int> st;

int main() 
{
	//--m为容量，n为元素个数，T为测试序列的个数--
	int m, n, T;
	scanf("%d%d%d", &m, &n, &T);

	//--因为有T个测试出栈序列--
	//--所以循环执行T次--
	while (T--) 
	{
		//--首先在每个出栈序列输入前，一定要清空栈--
		//--否则如果上个出栈序列的结果没有被清空，那么会影响下个出栈序列的过程--
		while (!st.empty()) 
		{
			st.pop();
		}

		//--读入数据--
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &arr[i]);
		}

		//---current用来指向出栈序列中的待出栈元素---
		int current = 1;  //***为什么current的初值为1？***
						  //**因为上面scanf数组的值的时候，i的初值为1**
		bool flag = true;


		for (int i = 1; i <= n; i++) 
		{
			//--把i压入栈--
			st.push(i);

			if (st.size() > m) 
			{
				//--如果此时栈中元素个数大于容量m，则序列非法--
				flag = false;
				break; //**这个break应该只是跳出外面的for循环，while循环是不会跳出的**
					   //**因为这个序列容量超了，只是这个单独的序列不合法，不代表后面的都不合法**
			}

			//--栈顶元素与出栈序列当前位置的元素相同时--
			while (!st.empty() && st.top() == arr[current]) // st.top()表示栈顶元素
			{
				//--反复弹栈，同时令(current++)--
				st.pop(); // 如果二者符合，就把栈st中当前的栈顶元素i弹出来
						  // 不然就不断地向栈st中压入i
				current++;
			}
		}

		if (st.empty() == true && flag == true) 
		{
			//--栈空且flag=true的时候，表明合法--
			printf("YES\n");
		}

		else 
		{
			printf("NO\n");
		}
	}

	return 0;
}
