#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
//下降路径最小和
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix)
	{
		//创建dp表->初始化->填表->返回值
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 2,INT_MAX));
		for (int i = 0, j = 0; j < col + 2; j++) dp[i][j] = 0;

		for (int i = 1; i <= row;i++)
			for (int j = 1; j <= col; j++)
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) 
				           + matrix[i - 1][j - 1];

		int tem = INT_MAX;
		for (int j = 1; j <= col; j++) tem = min(tem, dp[row][j]);

		return tem;
	}
};*/

// 打家劫舍Ⅱ
class Solution {
public:
	int rob1(vector<int>& nums, int begin, int end)
	{
		if (begin > end)
			return 0;

		int len = nums.size();
		vector<int> f(len);
		vector<int> g(len);

		f[begin] = nums[begin];
		
		for (int i = begin + 1; i <= end; i++)
		{
			f[i] = g[i - 1] + nums[i];
			g[i] = max(f[i - 1], g[i - 1]);
		}
		return max(f[end], g[end]);
	}

	int rob(vector<int>& nums)
	{
		int len = nums.size();
		return max(nums[0] + rob1(nums, 2, len - 2) , rob1(nums, 1, len - 1));       
	}
};

void test()
{
	Solution s;
	vector<int> t{ 1,2,3,1 };
	cout<<s.rob(t);
}

int main()
{
	test();
	return 0;
}