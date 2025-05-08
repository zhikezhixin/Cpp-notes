#include <iostream>
#include <vector>
using namespace std;

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//必须在不复制数组的情况下原地对数组进行操作。
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int count = 0;
       
        vector<int>::iterator it = nums.begin();
        while (it != nums.end())
        {
            if (*it == 0)
            {
                it = nums.erase(it); //erase()删除元素后，会让数据所有前移以为，在删除pos位置后，pos位置下一个元素会移动到
                count++;             //pos位置，而erase()会返回pos这个位置指针
            }
            else
            {
                ++it;
            }
        }
        for (;count > 0;count--)
        {
            nums.push_back(0);
        }
    }
};

//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位，数组中每个元素只存储单个数字。
//每个元素只存储单个数字。你可以假设除了整数 0 之外，这个整数不会以零开头。
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator rit = digits.rbegin();
        while (rit != digits.rend())
        {
            if (*rit < 9)
            {
                ++(*rit);
                return digits;
            }
            *rit = 0;
        }
         digits.insert(digits.begin(), 1);// ← 只有全部都是9时才会走到这里
        return digits;

    }
};
int main()
{
	return 0;
}