#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//给定两个以字符串形式表示的非负整数num1和num2，返回num1和num2的乘积，
//它们的乘积也表示为字符串形式。
class Solution {
public:
	int ctoi(const char ch)
	{
		return ch - '0';
	}
    string multiply(string num1, string num2) 
	{
		if (num1 == "0" || num2 == "0")
			return "0";

		vector<int> result(num1.size() + num2.size(), 0);

		for (int i = num1.size() - 1; i >= 0;i--)
		{
			for (int j = num2.size() - 1;j >= 0;j--)
			{
				int mul = ctoi(num1[i]) * ctoi(num2[j]);
				int high = i + j;
				int low = i + j + 1;
				//处理进位
				int sum = mul + result[low]; 
				result[high] += sum / 10;
				result[low] = sum % 10;
			}
		}
		string s = "";
		for (int i = 0; i < result.size();i++)
		{
			if (!(s.empty() && result[i] == 0))
			{
				s += to_string(result[i]);
			}
		}
		return s;
    }
};

//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
class Solution {
public:
	double myPow(double x, int n) {
		long long exp = n;
		double result = 1.0;
		if (exp < 0)
		{
			exp = -exp;
			x = 1 / x;
		}
		while (exp > 0)
		{
			if (exp % 2 == 1)
			{
				result *= x;
				--exp;
			}
			x *= x;
			exp /= 2;
		}
		return result;
	}
};

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode dummy(0);            // 虚拟头节点，简化处理逻辑
		ListNode* tail = &dummy;

		while (list1 && list2) 
		{
			if (list1->val < list2->val) 
			{
				tail->next = list1;
				list1 = list1->next;
			}
			else 
			{
				tail->next = list2;
				list2 = list2->next;
			}
			tail = tail->next;
		}

		// 把剩余节点拼上去
		if (list1) 
			tail->next = list1;
		else 
			tail->next = list2;

		return dummy.next;
	}
};

int main()
{
	system("pause");
	return 0;
}