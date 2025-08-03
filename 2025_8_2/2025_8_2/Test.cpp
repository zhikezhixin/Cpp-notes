#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> len(n, 1);
		vector<int> count(n, 1);

		int maxlen = 1, tmp = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (nums[j] < nums[i])
				{
					if (len[j] + 1 == len[i])
					{
						count[i] += count[j];
					}
					else if (len[j] + 1 > len[i])
					{
						len[i] = len[j] + 1;
						count[i] = count[j];
					}
				}
			}

			if (len[i] == maxlen)
			{
				tmp += count[i];
			}
			else if (len[i] > maxlen)
			{
				maxlen = len[i];
				tmp = count[i];
			}
		}

		return tmp;
	}
};
*/

