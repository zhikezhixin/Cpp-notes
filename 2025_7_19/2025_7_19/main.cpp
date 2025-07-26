#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//接雨水:给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
// 计算按此排列的柱子，下雨之后能接多少雨水。

class Solution 
{
public:
	int trap(vector<int>& height)
	{
		stack<int> s;
		int Rain = 0;
		for (size_t i = 0; i < height.size();i++)
		{
			while(!s.empty() &&height[i] > s.top())
			{
				int low = s.top();
				s.pop();
				if (s.empty()) break;
				int left = s.top();
				int high = min(height[i], height[left]) - height[low];
				int wide = i - left - 1;
				if (high > 0)
					Rain += high * wide;
			}
			s.push(i);
		}
		return Rain;
	}
};


