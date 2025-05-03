#define _CRT_SECURE_NO_WARNINGS
#include "Circle.h"

void test()
{
	CL* plist = InitList();
	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushFront(plist, 0);
	InsertNode(plist, 3,30);
	PopBack(plist);
	PopFront(plist);
	PrintList(plist);


}

int main()
{

	test();

	return 0;
}