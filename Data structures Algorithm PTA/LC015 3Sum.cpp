//***��75��77������û�������***
//***��27��32��������������---***

#include "C.h"

// vector��һ����ģ�壬����Ҫ��������vector�ĺ���Ľ�����<>��ָ��Ԫ���ͱ𣬳߶�д��object���ֺ��С������
vector<vector<int> > threeSum(vector<int>& nums) // nums���vector������ͱ���int�����Ǵ�Сû��ָ��
												 // ����˵nums��һ����vector��ִ��Ĭ�ϳ�ʼ��
{
	// �������ans����Ҳ��һ��vector������ans���vector�У�����װ�Ļ���vector
	// �������vector��װ�Ĳ���int��Ԫ�أ���ֵΪ0

	// �ڱ����У�װ��ans���vector�еģ���nums���vector
	vector<vector<int> > ans; // ������ans��Ԫ����vector����
	std::sort(nums.begin(), nums.end()); // ��nums����
										 // nums������int���͵Ķ���
										 // nums������Ϊһ��vector����
										 // �ɴ���intԪ�أ�ÿ��Ԫ�صĳ�ֵΪ0
	
	const int n = nums.size();
	
	//---Ϊʲô��Χ�� 0~n-3(i < n-2)�������� (i < n-1) ��---
	//***�����Ϊ�Ҽǵ�two pointers��һ���������l��r����Խ�磬�����߶Է�����·***
	//***��ô����iҲ��һ���ģ�������Χ��0~n-1������r=n-1�ˣ�����i�ķ�Χ����С����0~n-2***
	//***�������ǣ�l=i+1�����i���Ե���n-2��l�Ϳ�Ϊn-1�������ص��ˣ�����i�ķ�Χ��0~n-3***
	for (int i = 0; i < n - 2; ++i)
	{
		//---��������if���Ҷ�û��  ???---
		if (nums[i] > 0)
			break; // ��ΪҪ�� sum ��0���������һ����nums[i]��0���ǿ϶�ֱ��break!
		
		if (i > 0 && nums[i] == nums[i - 1])
			continue; // ��Ϊnums[i]��[i-1]��һ���ģ�nums[i]�Ĳ�����nums[i-1]�϶���һ��
					  // ��ô���֮ǰ�Ѿ��߹�һ���ˣ�����Ͳ������ˣ�ֱ�ӽ����´˵���iteration
		
		//---l �� r �����������˵�Сָ�룬��Щ�� two pointers
		int l = i + 1;
		int r = n - 1;

		// ������������3��nums[]��nums[r]�����⣬���ұ߿�ʼ�������
		// ����ʵÿ��i����һ�ˣ�l = i + 1������Ϊ��nums[i]��nums[l]��Ҫ�ظ�
		// ���nums[]3����û�з��ϱ�׼��ֻ�仯 l �� r��i ��ÿһ�˵��ظ�i��
		
		while (l < r)
		{
			if (nums[i] + nums[l] + nums[r] == 0)
			{
				// ��Ԫ�ؼ��뵽 vector ans ��l��ߵ�ָ��������һ���ұߵ�ָ��������һ��
				ans.push_back({ nums[i], nums[l++], nums[r--] });
				
				// ����������0��l������r����ߣ���nums[l]��nums[l]��ߵ�ǰһ��Ԫ����ͬ���Ǿ��ٽ�l����
				while (l < r && nums[l] == nums[l - 1])
					++l;

				// ����������0��l������r����ߣ���nums[r]���Լ��ұߵ�ǰһ��Ԫ����ͬ���Ǿ��ٽ�r����
				while (l < r && nums[r] == nums[r + 1])
					--r;
			}
			
			// ��Ϊ֮ǰ�Ѿ���Ԫ�ش�С���������ˣ�������� sum ��0С����Ԫ��nums[l]����
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

	//---��vector��push_back���ǲ���⣬���ǲ�����ӽ�2ά���飬��ôֱ��������ӵ��ĸ�λ�ã�---
	//---��Ϊ�������ʱ����֪��λ�õģ�m[i][j]�У�����������棬��ôֱ����һ������������---
	//---���ڵ�һ�У��ڶ����������������ڵڶ��У�---
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

		// ���ʱ��һ�о��������ˣ���һ�����з�\n
		printf("}\n");
	}

	// ��������ж������������һ������Ļ���
	cout << endl;
}


int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	vector<int> nums(a, a + sizeof(a) / sizeof(int));
	vector<vector<int> > result = threeSum(nums);

	printMatrix(result); // ���printMatrix�����Ȼ�ú��о���

	return 0;
}