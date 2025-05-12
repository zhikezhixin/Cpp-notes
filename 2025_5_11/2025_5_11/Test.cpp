#include <iostream>
#include <vector>
using namespace std;

//给你一 mxn的整数网 accounts ,其中 accounts[i][j]是第i​​​​​​​​​​​​位客户在第j家银行托管的资产数量。返回最富有客户所拥有的资产总量 。
//客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int rich_man = 0;
        int most_money = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;
            for (int x : accounts[i])
            {
                sum += x;
            }
            if (sum > most_money)
            {
                most_money = sum;
                rich_man = i;
            }
        }
        return most_money;
    }
};

//给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
//请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int mat_size = mat[0].size();
        int sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat_size;j++)
            {
                if (i == j)
                    sum += mat[i][j];
                if (i + j == mat_size - 1)
                    sum += mat[i][j];
            }
        }
        if (mat_size % 2 == 1)
        {
            sum -= mat[(mat_size - 1) / 2][(mat_size - 1) / 2];
        }
        return sum;
    }
};

//螺旋矩阵：给你一个m行n列的矩阵matrix ,请按照 顺时针螺旋顺序 ,返回矩阵中的所有元素。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {

    }
};
