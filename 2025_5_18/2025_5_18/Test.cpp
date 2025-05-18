#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ
//ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
class Solution {
public:
    int ctoi(char ch)
    {
        return ch - '0';
    }
    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        size_t result = 0;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int fig_1 = num1[i] - '0';
            for (int j = num2.size() - 1;j >= 0; j--)
            {
                int fig_2 = num1[j] - '0';
                result += ctoi(num2[j]) * fig * ctoi(num1[i]);
                fig /= 10;
            }
        }
        string s_restul((result + "0"));
    }
};

