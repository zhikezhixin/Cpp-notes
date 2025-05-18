#include <iostream>
#include <vector>
#include <string>
using namespace std;

//给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ，[x, y] 表示横坐标为 x、纵坐标为 y 的点。
// 请你来判断，这些点是否在该坐标系中属于同一条直线上。
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

//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和
class Solution {
public:
    int ctoi(char ch) {
        return ch - '0';
    }

    string addBinary(string a, string b) {
        string sum;
        int carry = 0;

        // 补齐长度
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