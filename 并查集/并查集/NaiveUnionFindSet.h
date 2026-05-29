#pragma once
#include <vector>


class NaiveUnionFindSet
{
public:

	NaiveUnionFindSet(size_t n)
		:_ufs(n, -1)
	{
	}

	int FindRoot(int x) //查找根
	{
		int parent = x;
		while (_ufs[parent] >= 0)
		{
			parent = _ufs[parent];
		}
		return parent;
	}

	void Union(int x, int y) //合并节点
	{
		int root_x = FindRoot(x);
		int root_y = FindRoot(y);
		if (root_x == root_y)
			return;

		_ufs[root_x] += _ufs[root_y];
		_ufs[root_y] = root_x;
	}

	bool InSet(int x, int y) //俩个节点是否在同一个集合
	{
		return FindRoot(x) == FindRoot(y);
	}

	size_t SetSize()
	{
		int count = 0;
		for (auto x : _ufs)
		{
			if (x < 0) count++;
		}

		return count;
	}

private:
	vector<int> _ufs;
};
