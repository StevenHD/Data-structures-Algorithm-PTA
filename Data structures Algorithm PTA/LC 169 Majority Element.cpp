// Moore Voting O(n) / O(1)
// 摩尔投票

#include "C.h"

int majorityElement (vector<int>& nums) 
{
	int majority = nums.front(); // front()取的就是当前vector中，排在第一个的呢个元素，这里是2
	int count = 0;
	
	// 这个for循环是c++11的新标准，num遍历nums中的每一个元素，也就是2 2 1 1 1 2 2
	for (const int num : nums) // num变量的类型是 const int，num的值则是遍历 nums 这个vector object
	{
		// 刚开始num为2, ma也是2，这时候count+1后为1
		// 第二轮num还是2，ma还是2，这时候count+1后为2
		// 第三轮num为1，ma还是2，所以换到else if那里，此时count为2，减1后为1不等于0
		// *** 所以直接进入下次迭代，但是唯一的改变是count已经变为了1 ***
		// 第四轮num为1，ma还是2，所以走到else if那里，这时count再减1就是0了，因此进入else if函数体内
		// count被置为了1，ma等于1
		// 第五轮num为1，ma也是1，所以count加1，为1
		// 第六轮num变成2了，ma为1，所以进入else if中，count减1后为0
		// 此时将count置为1，ma置为2
		// 第七轮num为2，ma也是2，所以count加1后为2，这时for循环完成，返回ma，就是2
		// 这个是摩尔投票算法
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
