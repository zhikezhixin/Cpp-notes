#include <iostream>
#include <vector>
#include <stack>
#include<string>
using namespace std;

/*inline int add(int a, int b)
{
	return a + b;
}*/

void Test_1()  // 判断出入栈序列是否合法
{
	class Solution
	{
	public:
		bool IsPopOrder(vector<int> pushV, vector<int> popV)
		{
			stack<int> st;
			int push_i = 0, pop_i = 0;
			while (push_i < pushV.size())
			{
				st.push(pushV[push_i++]); // 先入栈
				while (!st.empty() && st.top() == popV[pop_i]) // 入到栈顶元素与出栈序列相同，不停出栈
				{
					st.pop(); // 出栈
					pop_i++; // 出栈序列下标加1
				}
				{
					st.pop();
					pop_i++;
				}
			}
			return st.empty();
		}
	};
}

void test_2() // 逆波兰数：操作数顺序不变，操作符在操作数后面，并且按照优先级排列
{
	class Solution
	{
	public:
		int evalRPN(vector<string>& tokens)
		{
			stack<int> st;
			for (auto& str : tokens)  // 推导出str是string类型
			{
				if (str == "+" || str == "-" || str == "*" || str == "/")
				{
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					switch (str[0])  // 用string库中的重载[]
					{
					case'+':
						st.push(left + right);
						break;
					case'-':
						st.push(left - right);
						break;
					case'*':
						st.push(left * right);
						break;
					case'/':
						st.push(left / right);
						break;
					}
				}
				else
				{
					st.push(stoi(str));
				}
			}
		}
	};
}

int main()
{
	//int sum = add(3, 4);
	return 0;
}