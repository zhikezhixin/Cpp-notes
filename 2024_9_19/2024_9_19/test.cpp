#define _CRT_SECURE_NO_WARNINGS
#include "seplist.h"

int main()
{
	SL s;
	InitSepList(&s);

	for (int i = 'a'; i < 'z'; i++)
	{
		SepListPushBack(&s, i);
		//SepListPushFront(&s, i);

	}

	PrintSepList(&s);

	cout << "ɾ����Ԫ�غ�" << endl;
	SepListPopFront(&s);
	PrintSepList(&s);


	free(s.arr);
	return 0;
}  