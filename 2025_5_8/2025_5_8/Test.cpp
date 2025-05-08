#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

//已知函数 signFunc(x) 将会根据 x 的正负返回特定值：
//如果 x 是正数，返回 1 。
//如果 x 是负数，返回 - 1 。
//如果 x 是等于 0 ，返回 0 。
//给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。
//返回 signFunc(product) 。
class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int count = 0;
        for (int tmp : nums)
        {
            if (tmp == 0)
                return 0;
            if (tmp < 0)
                count++;
        }


        if (count % 2 == 0)
            return 1;
        else
            return -1;

    }
};


//给你一个数字数组 arr,如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int tmp = arr[1] - arr[0];
        for (int i = 0; i < arr.size() - 1;i++)
        {
           
            if (tmp != arr[i + 1] - arr[i])
            {
                return false;
            }
        }
        return true;
    }
};

//如果数组是单调递增或单调递减的，那么它是单调的
//当给定的数组 nums 是单调数组时返回 true，否则返回 false。
class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        bool inc = true, dec = true;
        for (int i = 0;i < nums.size() - 1;i++)
        {
            if (nums[i] <= nums[i + 1]) {}
            else
                inc = false;
            if (nums[i] >= nums[i + 1]) {}
            else
                dec = false;
        }

        return inc || dec;
    }
};

//罗马数字转整数
class Solution {
public:
    int romanToInt(string s) 
    {
        int sum = 0;
        vector<int> v;
        map<char, int> rom = 
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        for (char ch:s)
        {
            v.push_back(rom[ch]);
        }
        int i = 0;
        for (; i < v.size() - 1;i++)
        {
            if (v[i] < v[i + 1])
                v[i] = -v[i];
            sum += v[i];
        }
        sum += v[i];
        return sum;
    }
};



int main()
{
	return 0;
}