#include <iostream>
#include <vector>
#include <stack>
#include<string>
using namespace std;

/*inline int add(int a, int b)
{
	return a + b;
}*/

void Test_1()  // �жϳ���ջ�����Ƿ�Ϸ�
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
				st.push(pushV[push_i++]); // ����ջ
				while (!st.empty() && st.top() == popV[pop_i]) // �뵽ջ��Ԫ�����ջ������ͬ����ͣ��ջ
				{
					st.pop(); // ��ջ
					pop_i++; // ��ջ�����±��1
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

void test_2() // �沨������������˳�򲻱䣬�������ڲ��������棬���Ұ������ȼ�����
{
	class Solution
	{
	public:
		int evalRPN(vector<string>& tokens)
		{
			stack<int> st;
			for (auto& str : tokens)  // �Ƶ���str��string����
			{
				if (str == "+" || str == "-" || str == "*" || str == "/")
				{
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					switch (str[0])  // ��string���е�����[]
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