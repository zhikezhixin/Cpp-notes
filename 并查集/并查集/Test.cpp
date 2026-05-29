#include "NaiveUnionFindSet.h"
#include "UnionFindSet.h"
#include <iostream>
using namespace std;

void test_UnionFindSet()
{
	UnionFindSet ufs(5);

	cout << "初始集合数量: " << ufs.SetSize() << endl;

	auto PrintInSet = [&ufs](int x, int y)
		{
			cout << ufs.InSet(x, y) << endl;
		};

	PrintInSet(2, 3);
	PrintInSet(1, 4);

	ufs.Union(2, 3);
	cout << "合并2、3后集合数量: " << ufs.SetSize() << endl;
}

int main()
{
	test_UnionFindSet();
	return 0;
}