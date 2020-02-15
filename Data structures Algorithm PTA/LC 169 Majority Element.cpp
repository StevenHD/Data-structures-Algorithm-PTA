// Moore Voting O(n) / O(1)
// Ħ��ͶƱ

#include "C.h"

int majorityElement (vector<int>& nums) 
{
	int majority = nums.front(); // front()ȡ�ľ��ǵ�ǰvector�У����ڵ�һ�����ظ�Ԫ�أ�������2
	int count = 0;
	
	// ���forѭ����c++11���±�׼��num����nums�е�ÿһ��Ԫ�أ�Ҳ����2 2 1 1 1 2 2
	for (const int num : nums) // num������������ const int��num��ֵ���Ǳ��� nums ���vector object
	{
		// �տ�ʼnumΪ2, maҲ��2����ʱ��count+1��Ϊ1
		// �ڶ���num����2��ma����2����ʱ��count+1��Ϊ2
		// ������numΪ1��ma����2�����Ի���else if�����ʱcountΪ2����1��Ϊ1������0
		// *** ����ֱ�ӽ����´ε���������Ψһ�ĸı���count�Ѿ���Ϊ��1 ***
		// ������numΪ1��ma����2�������ߵ�else if�����ʱcount�ټ�1����0�ˣ���˽���else if��������
		// count����Ϊ��1��ma����1
		// ������numΪ1��maҲ��1������count��1��Ϊ1
		// ������num���2�ˣ�maΪ1�����Խ���else if�У�count��1��Ϊ0
		// ��ʱ��count��Ϊ1��ma��Ϊ2
		// ������numΪ2��maҲ��2������count��1��Ϊ2����ʱforѭ����ɣ�����ma������2
		// �����Ħ��ͶƱ�㷨
		if (num == majority) 
			++count;
		
		else if (--count == 0) 
		{
			count = 1;
			majority = num;
		}
	}
	
	return majority;
}

int main()
{
	int a[] = { 2,2,1,1,1,2,2 };
	vector<int> n(a, a + sizeof(a)/sizeof(int));

	int result = majorityElement(n);
	printf("%d", result);
}
