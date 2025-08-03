#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		// 准备工作
		unordered_set<string> hash;
		for (auto& x : wordDict)
		{
			hash.insert(x);
		}

		// 创建dp表
		int n = s.size();
		vector<bool> dp(n + 1);

		// 初始化
		s = ' ' + s;
		dp[0] = true;

		// 填表
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
				{
					dp[i] = true;
					break;
				}
			}
		}
		//返回值
		return dp[n];
	}
};

void test1()
{
	string s("leetcode"); 
	vector<string> wordDict{ "leet", "code" };

	Solution().wordBreak(s, wordDict);
}


int main()
{
	test1();
	return 0;
}