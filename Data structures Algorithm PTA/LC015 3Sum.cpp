//***行75到77的问题没解释清楚***
//***行27到32的问题解释清楚了---***

#include "C.h"

// vector是一个类模板，所以要在类名称vector的后面的角括号<>中指定元素型别，尺度写在object名字后的小括号里
vector<vector<int> > threeSum(vector<int>& nums) // nums这个vector对象的型别是int，但是大小没有指定
												 // 所以说nums是一个空vector，执行默认初始化
{
	// 关于这个ans，它也是一个vector，但是ans这个vector中，里面装的还是vector
	// 里面这个vector中装的才是int型元素，初值为0

	// 在本题中，装在ans这个vector中的，是nums这个vector
	vector<vector<int> > ans; // 该向量ans的元素是vector对象
	std::sort(nums.begin(), nums.end()); // 给nums排序
										 // nums保存了int类型的对象
										 // nums被定义为一个vector对象
										 // 可储存int元素，每个元素的初值为0
	
	const int n = nums.size();
	
	//---为什么范围是 0~n-3(i < n-2)，而不是 (i < n-1) ？---
	//***解答：因为我记得two pointers的一个规则就是l和r不能越界，就是走对方的老路***
	//***那么对于i也是一样的，正常范围是0~n-1，但是r=n-1了，所以i的范围就缩小到了0~n-2***
	//***但问题是，l=i+1，如果i可以到达n-2，l就可为n-1，这样重叠了，所以i的范围是0~n-3***
	for (int i = 0; i < n - 2; ++i)
	{
		//---下面两个if段我都没懂  ???---
		if (nums[i] > 0)
			break; // 因为要求 sum 是0，如果其中一个数nums[i]比0大，那肯定直接break!
		
		if (i > 0 && nums[i] == nums[i - 1])
			continue; // 因为nums[i]和[i-1]是一样的，nums[i]的操作和nums[i-1]肯定是一样
					  // 那么如果之前已经走过一次了，后面就不用走了，直接进入下此迭代iteration
		
		//---l 和 r 就是数组两端的小指针，有些像 two pointers
		int l = i + 1;
		int r = n - 1;

		// 这道题里面给了3个nums[]，nums[r]最好理解，从右边开始向左遍历
		// 但其实每个i都是一趟，l = i + 1，则是为了nums[i]和nums[l]不要重复
		// 如果nums[]3个数没有符合标准，只变化 l 和 r，i 是每一趟的呢个i。
		
		while (l < r)
		{
			if (nums[i] + nums[l] + nums[r] == 0)
			{
				// 将元素加入到 vector ans 后，l左边的指针往右走一格，右边的指针往左走一格
				ans.push_back({ nums[i], nums[l++], nums[r--] });
				
				// 如果满足等于0，l还是在r的左边，且nums[l]和nums[l]左边的前一个元素相同，那就再将l右移
				while (l < r && nums[l] == nums[l - 1])
					++l;

				// 如果满足等于0，l还是在r的左边，且nums[r]和自己右边的前一个元素相同，那就再将r左移
				while (l < r && nums[r] == nums[r + 1])
					--r;
			}
			
			// 因为之前已经将元素从小到大排序了，所以如果 sum 比0小，则将元素nums[l]右移
			else if (nums[i] + nums[l] + nums[r] < 0)
			{
				++l;
			}
			
			else 
			{
				--r;
			}
		}
	}
	
	return ans;

	//---对vector的push_back还是不理解，就是不断添加进2维数组，怎么直到具体添加到哪个位置？---
	//---因为在输出的时候，是知道位置的，m[i][j]中，像这个题里面，怎么直到第一次满足条件的---
	//---是在第一行，第二次满足条件的是在第二行？---
}

void printMatrix(vector<vector<int> >& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		printf("{");
		
		for (int j = 0; j < matrix[i].size; j++)
		{
			printf("%3d ", matrix[i][j]);
		}

		// 这个时候一行就输入完了，加一个换行符\n
		printf("}\n");
	}

	// 这个是所有都输入完后，再来一个整体的换行
	cout << endl;
}


int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > result = threeSum(nums);

	printMatrix(result); // 这个printMatrix函数等会好好研究下

	return 0;
}