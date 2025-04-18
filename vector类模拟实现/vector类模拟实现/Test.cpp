#include "vector.h"

int main()
{
	Zeker::vector<int> v;
	for (size_t i = 0; i < 5; i++)
	{
		v.push_back(i);
	}

	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
	return 0;
}