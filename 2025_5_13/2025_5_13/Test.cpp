#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//柠檬水找零
//在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& x : bills)
        {
            if (x == 5)
            {
                ++five;
            }
            else if (x == 10)
            {
                if (five == 0)
                    return false;
                ++ten;
                --five;
            }
            else
            {
                if (five && ten)
                {
                    --five;
                    --ten;
                }
                else if(five >=3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回0。
class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
       
        sort(nums.begin(),nums.end());
        for (int i = nums.size() - 1; i >= 2 ;i--)
        {
            if (nums[i - 1] + nums[i] > nums[i + 1])
            {
                return nums[i - 1] + nums[i] > nums[i + 1];
            }
            
        }
        return 0;
    }
};

//给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y 的点。
// 请你来判断，这些点是否在该坐标系中属于同一条直线上。
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int size = coordinates.size();
        int sub_y = coordinates[size - 1][1] - coordinates[size - 2][1];
        int sub_x = coordinates[size - 1][0] - coordinates[size - 2][0];

        for (int i = size - 2; i >= 1;i--)
        {
            if (coordinates[size - 1][1] - coordinates[size - 2][1] != sub_y ||
                coordinates[size - 1][0] - coordinates[size - 2][0] != sub_x   )
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
	return 0;
}