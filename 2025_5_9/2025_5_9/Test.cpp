#include <iostream>
#include <vector>
#include <string>
using namespace std;

//��������һ�������������ư�������ļ�¼Ա���ⳡ���������ɻغ���ɣ���ȥ���غϵĵ÷ֿ��ܻ�Ӱ���Ժ󼸻غϵĵ÷֡�
//������ʼʱ����¼�ǿհ׵ġ����õ�һ����¼�������ַ����б� ops������ ops[i] ������Ҫ��¼�ĵ� i �������ops ��ѭ��������
//���� x - ��ʾ���غ��»�÷��� x
//"+" - ��ʾ���غ��»�õĵ÷���ǰ���ε÷ֵ��ܺ͡���Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���������Ч�ķ�����
//"D" - ��ʾ���غ��»�õĵ÷���ǰһ�ε÷ֵ���������Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
//"C" - ��ʾǰһ�ε÷���Ч������Ӽ�¼���Ƴ�����Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
//���㷵�ؼ�¼�����е÷ֵ��ܺ͡�
class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        vector<int> Score;
        int sum = 0;
        for (const string& tmp : operations)
        {
            if (tmp == "+")
            {
                Score.push_back(Score[Score.size() - 2] + Score[Score.size() - 1]);
            }
            else if (tmp == "D")
            {
                Score.push_back(Score.back() * 2);
            }
            else if (tmp == "C")
            {
                Score.pop_back();
            }
            else
            {
                Score.push_back(stoi(tmp));
            }
        }

         for (const int& tmp : Score)
         {
             sum += tmp;
         }
         return sum;
    }
};

//�ڶ�άƽ���ϣ���һ�������˴�ԭ�� (0, 0) ��ʼ�����������ƶ�˳���ж����������������ƶ����Ƿ��� (0, 0) ��������
//�ƶ�˳�����ַ��� moves ��ʾ���ַ� move[i] ��ʾ��� i ���ƶ��������˵���Ч������ R���ң���L���󣩣�U���ϣ��� D���£���
//�����������������ж����󷵻�ԭ�㣬�򷵻� true�����򣬷��� false��
class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int count_R = 0;
        int count_L = 0;
        int count_U = 0;
        int count_D = 0;
        for (const char& s : moves)
        {
            if (s == 'R')
            {
                count_R++;
            }
            if (s == 'L')
            {
                count_L++;
            }
            if (s == 'U')
            {
                count_U++;
            }
            if (s == 'D')
            {
                count_D++;
            }
        }
        if (count_R == count_L && count_U == count_D)
        {
            return true;
        }
        return false;
    }
};

//�ҳ��������ʤ��
class Solution
{
public:
    string tictactoe(vector<vector<int>>& moves)
    {
        int count = 0;
        int Ddia = 0, Ndia = 0;
        int arr[4][4] = { 0 };
        for (const vector<int>& pos : moves)
        {
            count++;
            int row = pos[0], col = pos[1]; //ȡ�����ӵ��кź��к�
            int num = count % 2 == 0 ? -1 : 1; //A��ֵ1��B��ֵ-1

            arr[row][col] = num; //����
            if (row == col) //�������Խ���֮��
            {
                Ddia += num;
            }
            if (row + col == 2) //���¸��Խ���֮��
            {
                Ndia += num;
            }
            arr[row][3] += num; //���¸���֮��
            arr[3][col] += num; //���¸���֮��
            if ((abs(arr[row][3])) == 3 || (abs(arr[3][col]) == 3) || (abs(Ddia) == 3) || (abs(Ndia) == 3))
            {
                return num == 1 ? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";

    }
};

//���ڻ��еĻ�����:1.�ص�ԭ���л���2.һ����������ٳ������л���3.�������û��
class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        //                               0��   1��    2��      3��
        vector<vector<int>> direction = { {0,1},{1,0}, {0,-1} ,{-1,0} };//��ĳһ������ʱ�������θı�
        int x = 0, y = 0;
        int direIndex = 0; //�����˵�ǰ����
        for (const char& ch : instructions)
        {
            if (ch == 'G')
            {
                x += direction[direIndex][0];
                y += direction[direIndex][1];
            }
            else if (ch == 'L')
            {
                direIndex = (direIndex + 3) % 4;
            }
            else if (ch == 'R')
            {
                direIndex = (direIndex + 1) % 4;
            }
        }
        return (direIndex != 0) || (x == 0 && y == 0);
    }
};



int main()
{
	return 0;
}