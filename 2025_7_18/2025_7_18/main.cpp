#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 
using namespace std;

//给定一个未排序的整数数组nums ，找出数字连续的最长序列
//（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

class Solution {
public:
int longestConsecutive(vector<int>& nums) 
{
	unordered_set<int> s(nums.begin(),nums.end());
	int MaxLen = 0;
	
	for (auto num : s)
	{
		if (!s.count(num - 1))
		{
			int CurNum = num;
			int CurLen = 1;
			while (s.count(CurNum + 1))
			{
				CurNum++;
				CurLen++;
			}
			MaxLen = max(MaxLen, CurLen); // Ensure std::max is used
		}
	}
	return MaxLen; // Add return statement to return the result
}
};


//给定一个长度为n的整数数组height有n条垂线,第i条线的两个端点是(i,0)和(i,height[i])。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//说明：你不能倾斜容器。
class Solution {
public:
	int maxArea(vector<int>& height)
	{
		int MaxVolum = 0;
		int right = height.size() - 1;
		int left = 0;

		while (left < right)
		{
			int CurrentVolum = (right - left) * min(height[left], height[right]);

			if (height[left] < height[right])
				left++;
			else
				right--;

			MaxVolum = max(MaxVolum, CurrentVolum);
		}
		return MaxVolum;
	}
};



//给你一个整数数组nums,判断是否存在三元组[nums[i],nums[j],nums[k]]满足i!=j、i!=k且j!=k，
// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> vv;
		for (int i = 0;i < nums.size() - 1; i++)
		{
			if(i > 0 && nums[i] == nums[i - 1]) continue;

			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum > 0)
				{
					right--;
				}
				else if (sum < 0)
				{
					left++;
				}
				else 
				{
					vv.push_back({ nums[i],nums[left],nums[right] });
					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right - 1]) right--;
					left++;
					right--;
				}
				
			}
		}
		return vv;
	}
};



int main()
{
return 0;
}