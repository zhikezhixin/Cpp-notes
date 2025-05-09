#include <iostream>
#include <vector>
#include <string>
using namespace std;

//你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
//比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
//整数 x - 表示本回合新获得分数 x
//"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
//"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
//"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
//请你返回记录中所有得分的总和。
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

//在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
//移动顺序由字符串 moves 表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
//如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
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

//找出井字棋获胜者
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
            int row = pos[0], col = pos[1]; //取出落子的行号和列号
            int num = count % 2 == 0 ? -1 : 1; //A赋值1，B赋值-1

            arr[row][col] = num; //落子
            if (row == col) //更新正对角线之和
            {
                Ddia += num;
            }
            if (row + col == 2) //更新负对角线之和
            {
                Ndia += num;
            }
            arr[row][3] += num; //更新该行之和
            arr[3][col] += num; //更新该列之和
            if ((abs(arr[row][3])) == 3 || (abs(arr[3][col]) == 3) || (abs(Ddia) == 3) || (abs(Ndia) == 3))
            {
                return num == 1 ? "A" : "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";

    }
};

//困于环中的机器人:1.回到原点有环。2.一次走完后方向不再朝北，有环。3.其余情况没环
class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        //                               0北   1东    2南      3西
        vector<vector<int>> direction = { {0,1},{1,0}, {0,-1} ,{-1,0} };//朝某一方向走时，左边如何改变
        int x = 0, y = 0;
        int direIndex = 0; //机器人当前朝向北
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