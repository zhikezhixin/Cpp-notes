#include <iostream>
#include <vector>
using namespace std;

//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//�����ڲ���������������ԭ�ض�������в�����
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
                it = nums.erase(it); //erase()ɾ��Ԫ�غ󣬻�����������ǰ����Ϊ����ɾ��posλ�ú�posλ����һ��Ԫ�ػ��ƶ���
                count++;             //posλ�ã���erase()�᷵��pos���λ��ָ��
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

//����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ�����λ���ִ�����������λ��������ÿ��Ԫ��ֻ�洢�������֡�
//ÿ��Ԫ��ֻ�洢�������֡�����Լ���������� 0 ֮�⣬��������������㿪ͷ��
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
         digits.insert(digits.begin(), 1);// �� ֻ��ȫ������9ʱ�Ż��ߵ�����
        return digits;

    }
};
int main()
{
	return 0;
}