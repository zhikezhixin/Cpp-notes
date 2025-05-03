#define _CRT_SECURE_NO_WARNINGS
#include "singlelist.h"

void TestSList1()
{
	SLNODE* plist = NULL; //Õ∑÷∏’Î
	SListPushBack(plist,1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	SListPushFront(plist,0);
	/*SListPopFront(plist);
	SListPopFront(plist);
	SListPopBack(plist);
	SListPopBack(plist);*/
	/*SLNODE* posion = SListFind(plist, 0);
	if (posion)
	{
		SListInsert(plist, posion, 30);
	}

	SListPrint(plist);*/
	SLNODE* posion = SListFind(plist, 3);
	if (posion)
	{
		SListErase(plist, posion);
	}

	SListPrint(plist);

}

int main()
{
	TestSList1();


	return 0;
}