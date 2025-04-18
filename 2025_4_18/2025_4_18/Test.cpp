#include <iostream>
#include <list>
using namespace std;
 
void print_list(list<int>& lt_1)
{
	list<int>::reverse_iterator ritl = lt_1.rbegin();
	while (ritl != lt_1.rend())
	{
		cout << *ritl << " ";
		ritl++;
	}
	cout << endl;
}

void test_1()
{
	list<int> lt_1;
	for (size_t i = 2; i < 5; i++)
	{
		lt_1.push_back(i);
	}
	print_list(lt_1);
	lt_1.push_front(1);
	lt_1.push_front(0);
	print_list(lt_1);

	list<int>::iterator pos = find(lt_1.begin(), lt_1.end(), 3);
	if (pos != lt_1.end())
	{
		lt_1.insert(pos, 30);
	}
	print_list(lt_1);
}

void test_2()  // erase的迭代器失效问题
{
	list<int> lt_2;
	
	lt_2.push_back(2);
	lt_2.push_back(1);
	lt_2.push_back(5);
	lt_2.push_back(4);
	print_list(lt_2);

	list<int>::iterator it = lt_2.begin();
	while (it != lt_2.end())
	{
		if (*it % 2 == 0)
		{
			//lt_2.erase(it)  这么会造成，it指向的空间被释放后，it仍然指向那块空间，后续若是再引用it会造成出错
			it = lt_2.erase(it);  // erase()会返回被释放空间的下一个位置，将其赋给it,保证下次正确操作地址空间
		}
		else
		{
			++it;
		}
	}
	print_list(lt_2);

}

int main()
{
	//test_1();
	test_2();
	return 0;
}