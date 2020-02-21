// A1040. Longest Symmetric String

//-------CODE---------

#include "C.h"

typedef long long ll;

//---MODΪ����hashֵʱ��ģ��---
const ll MOD = 1000000007;

//---PΪ����hashֵʱ�Ľ�����---
const ll P = 10000019;

//---MAXNΪ�ַ��������---
const ll MAXN = 1010;

//---powP[i]���P^i%MOD��H1��H2�ֱ���str��rstr��hashֵ---
ll powP[MAXN];
ll H1[MAXN], H2[MAXN];

//---init������ʼ��powP����---
void init()
{
	powP[0] = 1;
	for (int i = 1; i < MAXN; i++)
	{
		powP[i] = (powP[i - 1] * P) % MOD;
	}
}

//---calH���������ַ���str��hashֵ---
void calH(ll H[], string& str)
{
	//---H[0]��������---
	H[0] = str[0];

	for (int i = 1; i < str.length(); i++)
	{
		H[i] = (H[i - 1] * P + str[i]) % MOD;
	}
}

//--calSingleSubH����H[i...j]
int calSingleSubH(ll H[], int i, int j)
{
	//--H[0...j]��������--
	if (i == 0)
		return H[j];

	return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

//--------
// �ԳƵ�Ϊi���ַ�������Ϊlen����[l,r]����ֻ��İ뾶
// Ѱ�����һ������������hashL == hashR�� �Ļ��İ뾶
// �ȼ���Ѱ�ҵ�һ������������hashL != hashR���Ļ��İ뾶��Ȼ���1����
// isEven���������ʱΪ0������ż����ʱΪ1
//--------

int binarySearch(int l, int r, int len, int i, int isEven)
{
	while (l < r)
	{
		//--������l == rʱ��������Ϊ��Χ��[l,r]��
		int mid = (l + r) / 2;

		//--����Ӵ�hashֵH1[H1L...H1R]
		//--�Ұ��Ӵ�hashֵH2[H2L...H2R]
		int H1L = i - mid + isEven;
		int H1R = i;

		int H2L = len - 1 - (i + mid);
		int H2R = len - 1 - (i + isEven);

		int hashL = calSingleSubH(H1, H1L, H1R);
		int hashR = calSingleSubH(H2, H2L, H2R);

		//--hashֵ���ȣ�˵�����İ뾶<=mid--
		if (hashL != hashR)
			r = mid;

		//---hashֵ��ȣ�˵�����İ뾶>mid---
		else
			l = mid + 1;
	}

	//--���������İ뾶--
	return l - 1;
}

int main()
{
	//--��ʼ��powP--
	init();

	string str;
	getline(cin, str);

	//--����str��hash����--
	calH(H1, str);

	//--���ַ�����ת--
	reverse(str.begin(), str.end());

	//--����rstr��hash����--
	calH(H2, str);

	int ans = 0;

	//--�����--
	for (int i = 0; i < str.length(); i++)
	{
		//--�����Ͻ�Ϊ�ֽ��i�����ҳ��ȵĽ�Сֵ��1--
		int maxLen = min(i, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 0);
		ans = max(ans, k * 2 + 1);
	}

	//--ż����--
	for (int i = 0; i < str.length(); i++)
	{
		//--�����Ͻ�Ϊ�ֽ��i�����ҳ��ȵĽ�Сֵ��1--
		//--(ע����Ϊi+1)--
		int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 1);
		ans = max(ans, k * 2);
	}

	printf("%d\n", ans);
	return 0;
}