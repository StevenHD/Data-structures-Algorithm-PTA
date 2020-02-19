// A1048. Find Coins

//-------CODE--------

#include "C.h"

const int N = 1005;

//---����һ��ȫ�ֱ���hash��----
int HashTable[N];

int main() 
{
	//---n��Ԫ�أ�mΪĿ���---
	int n, m, a;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) 
	{
		//---������a��ʱ�򣬾Ϳ�ʼ��hashTable[a]���д�����---
		scanf("%d", &a);
		++HashTable[a];
	}

	//---ö��1~1005�е�ÿһ������i����i������������m-i���������У���˵���ҵ���һ��---
	for (int i = 0; i < N; i++) 
	{
		//---���û�еĻ���˵��hashTable[i]��0��0����ζ��false---
		if (HashTable[i] && HashTable[m - i]) 
		{
			if (i == m - i && HashTable[i] <= 1) 
			{
				//---���i��m-i����ȵģ�����i���ֵĴ�����ǰС��1��---
				//---��ֱ��continue�������´ε�����˵����ǰ���i���������⣬����i(��i+1)---
				continue;
			}

			//---���i��m-i���У�����һ��������Ҳû��ֻ��һ�Σ���ֱ��print---
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}

	//---ֻҪ��һ�����ϵģ������forѭ���ͻ��ӡ������Ȼ��return 0����---
	//---����˵��Ҫ��û������˵��û��һ�����ϣ���ô�� No solution---
	printf("No Solution\n");
	return 0;
}