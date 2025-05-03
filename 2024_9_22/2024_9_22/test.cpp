#define _CRT_SECURE_NO_WARNINGS
#include "doublelist.h"

void ListTest()
{
	DLNODE* plist = InitList();
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPushBack(plist, 5);
	DListPushFront(plist, 2);
	DListPushFront(plist, 1);
	DListPushFront(plist, 0);

	ListPopFront(plist);
	ListPopBack(plist);

	InsertNode(plist, 4, 30);

	DlistPrint(plist);  
}
int main()
{
	ListTest();
	return 0;
}