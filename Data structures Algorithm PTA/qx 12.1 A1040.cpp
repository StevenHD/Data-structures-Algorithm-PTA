// A1040. Longest Symmetric String

//-------CODE---------

#include "C.h"

typedef long long ll;

//---MOD为计算hash值时的模数---
const ll MOD = 1000000007;

//---P为计算hash值时的进制数---
const ll P = 10000019;

//---MAXN为字符串最长长度---
const ll MAXN = 1010;

//---powP[i]存放P^i%MOD，H1和H2分别存放str和rstr的hash值---
ll powP[MAXN];
ll H1[MAXN], H2[MAXN];

//---init函数初始化powP函数---
void init()
{
	powP[0] = 1;
	for (int i = 1; i < MAXN; i++)
	{
		powP[i] = (powP[i - 1] * P) % MOD;
	}
}

//---calH函数计算字符串str的hash值---
void calH(ll H[], string& str)
{
	//---H[0]单独处理---
	H[0] = str[0];

	for (int i = 1; i < str.length(); i++)
	{
		H[i] = (H[i - 1] * P + str[i]) % MOD;
	}
}

//--calSingleSubH计算H[i...j]
int calSingleSubH(ll H[], int i, int j)
{
	//--H[0...j]单独处理--
	if (i == 0)
		return H[j];

	return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

//--------
// 对称点为i，字符串长度为len，在[l,r]里二分回文半径
// 寻找最后一个满足条件“hashL == hashR” 的回文半径
// 等价于寻找第一个满足条件“hashL != hashR”的回文半径，然后减1即可
// isEven当求奇回文时为0，当求偶回文时为1
//--------

int binarySearch(int l, int r, int len, int i, int isEven)
{
	while (l < r)
	{
		//--当出现l == r时结束（因为范围是[l,r]）
		int mid = (l + r) / 2;

		//--左半子串hash值H1[H1L...H1R]
		//--右半子串hash值H2[H2L...H2R]
		int H1L = i - mid + isEven;
		int H1R = i;

		int H2L = len - 1 - (i + mid);
		int H2R = len - 1 - (i + isEven);

		int hashL = calSingleSubH(H1, H1L, H1R);
		int hashR = calSingleSubH(H2, H2L, H2R);

		//--hash值不等，说明回文半径<=mid--
		if (hashL != hashR)
			r = mid;

		//---hash值相等，说明回文半径>mid---
		else
			l = mid + 1;
	}

	//--返回最大回文半径--
	return l - 1;
}

int main()
{
	//--初始化powP--
	init();

	string str;
	getline(cin, str);

	//--计算str的hash数组--
	calH(H1, str);

	//--将字符串反转--
	reverse(str.begin(), str.end());

	//--计算rstr的hash数组--
	calH(H2, str);

	int ans = 0;

	//--奇回文--
	for (int i = 0; i < str.length(); i++)
	{
		//--二分上界为分界点i的左右长度的较小值加1--
		int maxLen = min(i, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 0);
		ans = max(ans, k * 2 + 1);
	}

	//--偶回文--
	for (int i = 0; i < str.length(); i++)
	{
		//--二分上界为分界点i的左右长度的较小值加1--
		//--(注意左长为i+1)--
		int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 1);
		ans = max(ans, k * 2);
	}

	printf("%d\n", ans);
	return 0;
}