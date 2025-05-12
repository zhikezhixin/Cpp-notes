 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��������:����һ��m ��n �еľ��� matrix ���밴��˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> anser;
        while (true)
        {
            for (int i = left;i <= right; i++)
            {
                anser.push_back(matrix[up][i]);
            }
            if (++up > down) break;

            for (int i = up;i <= down;i++)
            {
                anser.push_back(matrix[i][right]);
            }
            if (--right < left) break;

            for (int i = right;i >= left; i--)
            {
                anser.push_back(matrix[down][i]);
            }
            if (--down < up) break;

            for (int i = down; i >= up;i--)
            {
                anser.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return anser;
    }
};


//����һ��m x n�ľ������һ��Ԫ��Ϊ 0 ,���������к��е�����Ԫ�ض���Ϊ 0����ʹ��ԭ���㷨��
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int row = matrix.size(), col = matrix[0].size();
        bool first_row = false, first_col = false;

        for (int i = 0;i < col;i++)
        {
            if (matrix[0][i] == 0)
                first_row = true;
        }

        for (int i = 0;i < row;i++)
        {
            if (matrix[i][0] == 0)
                first_col = true;
        }

        for (int i = 1;i <= row - 1; i++)
        {
            for (int j = 1; j <= col - 1; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1;i <= row - 1; i++)
        {
            for (int j = 1; j <= col - 1; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row)
        {
            for (int i = 0;i < col;i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (first_col)
        {
            for (int i = 0;i < row;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

//���������Ǹ����� low �� high �����㷵�� low �� high ֮�䣨�������ߣ���������Ŀ��
/*class Solution {
public:
    int countOdds(int low, int high)
    {
        int counter = 0;
        int i = low;
            do
            {
                if (i % 2 == 0) counter++;
                i++;

            } while (i <= high);
        return counter;
    }
};
*/
class Solution {
public:
    int Odd(int x)
    {
        return (x + 1) >> 1;
    }

    int countOdds(int low, int high)
    {
        return Odd(high) - Odd(low - 1);
    }
};
//ȥ����͹��ʺ���߹��ʺ�Ĺ���ƽ��ֵ
//����һ����������salary ��������ÿ��������Ψһ�ģ����� salary[i]�ǵ�i��Ա���Ĺ��ʡ�
//���㷵��ȥ����͹��ʺ���߹����Ժ�ʣ��Ա�����ʵ�ƽ��ֵ��
class Solution {
public:
    double average(vector<int>& salary) 
    {
        sort(salary.begin(), salary.end());
        if (salary.size() == 3)
        {
            return (double)salary[1];
        }
        double sum = 0;
        for (int i = 1; i < salary.size() - 1;i++)
        {

            sum += salary[i];
        }
        sum /= 2;
        return sum;
    }
    
};

int main()
{
	return 0;
}