#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
	int maxProfit(vector<int>& prices, int k)
	{
		const int INF = -0x3f3f3f3f;
		int n = prices.size();
		k = min(n / 2, k);
		vector<vector<int>> f(n, vector<int>(k + 1, INF));
		vector<vector<int>> g(n, vector<int>(k + 1, INF));

		f[0][0] = -prices[0];
		g[0][0] = 0;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
				g[i][j] = g[i - 1][j];
				if (j - 1 >= 0)
				{
					g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
				}
			}
		}

		int maxP = 0;
		for (int i = 0; i <= k; i++)
		{
			maxP = max(maxP, g[n - 1][i]);
		}

		return maxP;
	}
};

void test1()
{
	int k = 2;
	vector<int> v{ 2,4,1 };
	cout<<Solution().maxProfit(v, 2);
}
*/
/*
class Solution {
public:
	int maxSubArray(const vector<int>& nums)
	{
		int n = nums.size();
		vector<int> dp(n + 1);

		for (int i = 1; i <= n; i++)
		{
			dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
		}

		int tmp = INT_MIN;
		for (auto x : dp)
		{
			tmp = max(x, tmp);
		}
		return tmp;
	}
};

void test2()
{
	cout<<Solution().maxSubArray(vector<int>{ -1 });
}
*/

class Solution {
public:
	int numberOfArithmeticSlices(const vector<int>& nums)
	{
		int n = nums.size();
		vector<int> dp(n);
		int count = 0;
		for (int i = 2; i < n; i++)
		{
			dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
			count += dp[i];
		}
		return count;
	}
};

void test3()
{
	//cout<<Solution().numberOfArithmeticSlices(vector<int>{1, 2, 3, 4});
	cout << Solution().numberOfArithmeticSlices(vector<int>{1});

}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}