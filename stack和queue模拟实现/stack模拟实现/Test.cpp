#include "stack.h"
#include <vector>
#include <list>

void test_stack()
{
	Zeker::stack<int, list<int>> st1;
	Zeker::stack<int, vector<int>> st2;

	for (size_t i = 1; i < 5;i++)
	{
		st1.push(i);
	}
	cout << "st1_empty = " << st1.size() << endl;
	cout << "st1:";
	 while(!st1.empty())
	{
		cout<<st1.top()<<" ";
		st1.pop();
	}

	 cout << endl << endl;

	 for (size_t i = 5; i < 10;i++)
	 {
		 st2.push(i);
	 }
	 cout << "st2_empty = " << st2.size() << endl;
	 cout << "st2:";
	 while (!st2.empty())
	 {
		 cout << st2.top() << " ";
		 st2.pop();
	 }
}


int main()
{
	test_stack();
	return 0;
}