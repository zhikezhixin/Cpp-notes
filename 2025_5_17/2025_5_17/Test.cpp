#include <iostream>
#include <vector>
#include <string>
using namespace std;

//����һ������ coordinates ������ coordinates[i] = [x, y] ��[x, y] ��ʾ������Ϊ x��������Ϊ y �ĵ㡣
// �������жϣ���Щ���Ƿ��ڸ�����ϵ������ͬһ��ֱ���ϡ�
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];

        for (int i = 2;i < coordinates.size();i++)
        {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((y - y0)*(x1 - x0) != (y1 - y0) * (x - x0) )
            {
                return false;
            }
        }
        return true;
    }
};

//���������������ַ��� a �� b ���Զ������ַ�������ʽ�������ǵĺ�
class Solution {
public:
    int ctoi(char ch) {
        return ch - '0';
    }

    string addBinary(string a, string b) {
        string sum;
        int carry = 0;

        // ���볤��
        size_t diff = a.size() - b.size();
        if (diff > 0)
        {
            b = string(diff, '0') + b;
        }
        else if (diff < 0)
        {
            a = string(-diff, '0') + a;
        }

        auto rita = a.rbegin();
        auto ritb = b.rbegin();
        while (rita != a.rend() && ritb != b.rend())
        {
            int total = ctoi(*rita) + ctoi(*ritb) + carry;
            sum += (total % 2) + '0';
            carry = total / 2;
            ++rita;
            ++ritb;
        }
        if (carry)
        {
            sum = '1' + sum;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

//

int main()
{
    return 0;
}