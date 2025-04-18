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

void test_2()  // erase�ĵ�����ʧЧ����
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
			//lt_2.erase(it)  ��ô����ɣ�itָ��Ŀռ䱻�ͷź�it��Ȼָ���ǿ�ռ䣬��������������it����ɳ���
			it = lt_2.erase(it);  // erase()�᷵�ر��ͷſռ����һ��λ�ã����丳��it,��֤�´���ȷ������ַ�ռ�
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