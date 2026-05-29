#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution1 {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        int max_len = 1;
        int begin = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
                if (dp[i][j] && j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max_len);
    }
};

void test1()
{
    string s{ "a" };
    Solution1().longestPalindrome(s);
}


class Solution2 {
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> IsPal(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (s[i] == s[j])
                    IsPal[i][j] = i + 1 < j ? IsPal[i + 1][j - 1] : true;

        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
            if (IsPal[0][i])
                dp[i] = 0;
            else
                for (int j = 1; j <= i; j++)
                    if (IsPal[j][i])
                        dp[i] = min(dp[j - 1] + 1, dp[i]);


        return dp[n - 1];
    }
};


int main()
{
	test1();
	return 0;
}
