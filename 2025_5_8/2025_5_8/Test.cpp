#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

//��֪���� signFunc(x) ������� x �����������ض�ֵ��
//��� x ������������ 1 ��
//��� x �Ǹ��������� - 1 ��
//��� x �ǵ��� 0 ������ 0 ��
//����һ���������� nums ���� product Ϊ���� nums ������Ԫ��ֵ�ĳ˻���
//���� signFunc(product) ��
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


//����һ���������� arr,��������������������γɵȲ����У��뷵�� true �����򣬷��� false
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

//��������ǵ��������򵥵��ݼ��ģ���ô���ǵ�����
//������������ nums �ǵ�������ʱ���� true�����򷵻� false��
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

//��������ת����
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