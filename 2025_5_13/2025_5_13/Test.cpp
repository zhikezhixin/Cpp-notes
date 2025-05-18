#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//����ˮ����
//������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ���˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����
//ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��
//������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ���˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����
//ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��
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

//������һЩ�����������ȣ���ɵ����� nums ������ ����������������ɵġ������Ϊ��������ε�����ܳ� ����������γ��κ������Ϊ��������Σ�����0��
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

//����һ������ coordinates ������ coordinates[i] = [x, y] �� [x, y] ��ʾ������Ϊ x��������Ϊ y �ĵ㡣
// �������жϣ���Щ���Ƿ��ڸ�����ϵ������ͬһ��ֱ���ϡ�
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