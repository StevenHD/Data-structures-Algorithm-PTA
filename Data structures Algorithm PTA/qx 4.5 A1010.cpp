// A1010. Radix 基数
// 二分查找

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

//---将a转换为十进制，t为上界---
LL convertNum10(char a[], LL radix, LL t) 
{
	LL ans = 0;

	int len = strlen(a);
	for (int i = 0; i < len; i++) 
	{
		//---进制转换---
		ans = ans * radix + Map[a[i]];

		//---溢出或超过N1的十进制---
		if (ans < 0 || ans > t) 
			return -1;
	}

	return ans;
}

//---N2的十进制与t比较---
int cmp(char N2[], LL radix, LL t) 
{
	int len = strlen(N2);

	//---将N2转换为十进制---
	LL num = convertNum10(N2, radix, t);

	//---num<0，说明溢出了，所以肯定是N2>t---
	if (num < 0) 
		return 1;

	//---t较大，返回-1---
	if (t > num) 
		return -1;

	//---num和t相等，返回0---
	else if (t == num) 
		return 0;

	//---num较大，返回1---
	else 
		return 1;
}


//---二分求解N2的进制---
LL binarySearch(char N2[], LL left, LL right, LL t) // N2[]是char型数组吗？
{
	LL mid;
	while (left <= right) 
	{
		mid = (left + right) / 2;

		//---判断N2转换为十进制后与t比较---
		int flag = cmp(N2, mid, t);

		//---找到解，返回mid---
		if (flag == 0) 
			return mid;

		//---flag等于-1表示表明t较大，所以往右子区间继续查找---
		else if (flag == -1) 
			left = mid + 1;

		//---flag等于1表明num较大，则往左子区间继续查找---
		else 
			right = mid - 1;
	}

	//---解不存在---
	return -1;
}

//---求最大的数位---
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

	//---最大的数位为ans，说明进制数的底线是ans+1---
	return ans + 1;
}

char N1[20], N2[20], temp[20];
int tag, radix;

int main() 
{
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);  // 注意N1 N2前面没有&，因为是字符数组

	//---交换N1和N2---
	if (tag == 2) 
	{
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}

	//---将N1从radix进制转换为十进制---
	LL t = convertNum10(N1, radix, inf);

	//---找到N2中数位最大的位加1，当成二分下界---
	LL low = findLargestDigit(N2);

	//---二分上界---
	LL high = max(low, t) + 1;

	//---二分---
	LL ans = binarySearch(N2, low, high, t);

	if (ans == -1) 
		printf("Impossible\n");
	else 
		printf("%lld\n", ans);

	return 0;
}
