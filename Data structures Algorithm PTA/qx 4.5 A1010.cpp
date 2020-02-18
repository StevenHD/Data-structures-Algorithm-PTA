// A1010. Radix ����
// ���ֲ���

#include "C.h"

typedef long long LL;

LL Map[256];
LL inf = (1LL << 63) - 1;

void init() 
{
	for (char c = '0'; c <= '9'; c++) 
	{
		Map[c] = c - '0';
	}

	for (char c = 'a'; c <= 'z'; c++) 
	{
		Map[c] = c - 'a' + 10;
	}
}

//---��aת��Ϊʮ���ƣ�tΪ�Ͻ�---
LL convertNum10(char a[], LL radix, LL t) 
{
	LL ans = 0;

	int len = strlen(a);
	for (int i = 0; i < len; i++) 
	{
		//---����ת��---
		ans = ans * radix + Map[a[i]];

		//---����򳬹�N1��ʮ����---
		if (ans < 0 || ans > t) 
			return -1;
	}

	return ans;
}

//---N2��ʮ������t�Ƚ�---
int cmp(char N2[], LL radix, LL t) 
{
	int len = strlen(N2);

	//---��N2ת��Ϊʮ����---
	LL num = convertNum10(N2, radix, t);

	//---num<0��˵������ˣ����Կ϶���N2>t---
	if (num < 0) 
		return 1;

	//---t�ϴ󣬷���-1---
	if (t > num) 
		return -1;

	//---num��t��ȣ�����0---
	else if (t == num) 
		return 0;

	//---num�ϴ󣬷���1---
	else 
		return 1;
}


//---�������N2�Ľ���---
LL binarySearch(char N2[], LL left, LL right, LL t) // N2[]��char��������
{
	LL mid;
	while (left <= right) 
	{
		mid = (left + right) / 2;

		//---�ж�N2ת��Ϊʮ���ƺ���t�Ƚ�---
		int flag = cmp(N2, mid, t);

		//---�ҵ��⣬����mid---
		if (flag == 0) 
			return mid;

		//---flag����-1��ʾ����t�ϴ����������������������---
		else if (flag == -1) 
			left = mid + 1;

		//---flag����1����num�ϴ��������������������---
		else 
			right = mid - 1;
	}

	//---�ⲻ����---
	return -1;
}

//---��������λ---
int findLargestDigit(char N2[]) 
{
	int ans = -1;
	int len = strlen(N2);

	for (int i = 0; i < len; i++) 
	{
		if (Map[N2[i]] > ans) 
		{
			ans = Map[N2[i]];
		}
	}

	//---������λΪans��˵���������ĵ�����ans+1---
	return ans + 1;
}

char N1[20], N2[20], temp[20];
int tag, radix;

int main() 
{
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);  // ע��N1 N2ǰ��û��&����Ϊ���ַ�����

	//---����N1��N2---
	if (tag == 2) 
	{
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}

	//---��N1��radix����ת��Ϊʮ����---
	LL t = convertNum10(N1, radix, inf);

	//---�ҵ�N2����λ����λ��1�����ɶ����½�---
	LL low = findLargestDigit(N2);

	//---�����Ͻ�---
	LL high = max(low, t) + 1;

	//---����---
	LL ans = binarySearch(N2, low, high, t);

	if (ans == -1) 
		printf("Impossible\n");
	else 
		printf("%lld\n", ans);

	return 0;
}
