#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 动态规划分析步骤：
// 状态表示->状态转移方程->初始化->填表顺序->返回值


//泰波那契序列 Tn 定义如下：
//T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn + 3 = Tn + Tn + 1 + Tn + 2
//给你整数n,请返回第 n 个泰波那契数 Tn 的值。
class Solution {
public:
	int numDecodings(string s)
	{
		//创建dp表->初始化->填表->返回值
		int n = s.size();
		vector<int> dp(n);
		dp[0] = (s[0] != '0');
		if (n == 1) return dp[0];

		if (s[0] != '0' && s[1] != '0')  dp[1] += 1;
		int x = (s[0] - '0') * 10 + (s[1] - '0');
		if (x >= 10 && x <= 26) dp[1] += 1;

		for (size_t i = 2; i < n; i++)
		{
			if (s[i] != '0') dp[i] += dp[i - 1];
			int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
			if (x >= 10 && x <= 26) dp[i] += dp[i - 2];
		}

		return dp[n - 1];
	}
};


//三步问题。有个小孩正在上楼梯，楼梯有 n 阶台阶，小孩一次可以上 1 阶、2 阶或 3 阶。
// 实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模 1000000007。
class Solution {
public:
	int waysToStep(int n) 
	{

		if (n == 1 || n == 2) return n;
		if (n == 3) return 4;

		int Mod = 1e9 + 7;
		vector<int> dp(n + 1);
		dp[1] = 1, dp[2] = 2; dp[3] = 4;
		for (size_t i = 4; i <= n;i++)
			dp[i] = ((dp[i - 1] + dp[i - 2])%Mod + dp[i - 3]) % Mod;

		return dp[n];
	}
};

//数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
//每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
//请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) 
	{
		int n = cost.size();
		vector<int> dp(n + 1, 0);
		for (size_t i = 2; i <= n; i++)
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		return dp[n];
	}
};

// 解码方法：一条包含字母 A - Z 的消息通过1-26映射进行了编码
//给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。如果没有合法的方式解码整个字符串，返回 0。
//题目数据保证答案肯定是一个 32 位 的整数。

class Solution {
public:
	int numDecodings(string s)
	{
		//创建dp表
		int n = s.size();
		vector<int> dp(n);
		//初始化
		dp[0] = s[0] != '0';
		if (n == 1) return 1;
		if (s[0] != '0' && s[1] != '0') dp[1] += 1;
		int x = (s[0] - '0') * 10 + (s[1] - '0');
		if (x >= 10 && x <= 26) dp[1] += 1;
		//填表
		for (size_t i = 2; i < n;i++)
		{
			if (s[i] != '0') dp[i] += dp[i - 1];
			int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
			if (x >= 10 && x <= 26) dp[i] += dp[i-2];
		}
		//返回值
		return dp[n - 1];
	}
};
//优化后
class Solution {
public:
	int numDecodings(string s)
	{
		//创建dp表
		int n = s.size();
		vector<int> dp(n + 1);
		//初始化
		dp[0] = 1;
		dp[1] = s[1 - 1] != '0';
		//填表
		for (size_t i = 2; i <= n;i++)
		{
			if (s[i - 1] != '0') dp[i] += dp[i - 1];
			int x = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
			if (x >= 10 && x <= 26) dp[i] += dp[i - 2];
		}
		//返回值
		return dp[n];
	}
};


//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start”）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//问总共有多少条不同的路径？
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1));
        dp[0][1] = 1;
        for(size_t i = 1 ;i <= m;i++)
            for(size_t j = 1; j <= n ;j++)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        return dp[m][n];
    }
};