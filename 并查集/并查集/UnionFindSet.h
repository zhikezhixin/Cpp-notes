#pragma once
#include <vector>

class UnionFindSet
{
public:
	UnionFindSet(int n)
		:_parent(n), _high(n, 0), _size(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int FindRoot(int x) //查找根的同时，将节点直接连接到根
	{
		int current = x;

		if (_parent[current] != current)
			_parent[current] = FindRoot(_parent[current]);

		return _parent[current];
	}

	void Union(int x, int y)
	{
		int root_x = FindRoot(x);
		int root_y = FindRoot(y);

		if (_high[root_x] > _high[root_y])
		{
			_high[root_x] += _high[root_y];
			_parent[root_y] = root_x;
		}
		else if (_high[root_x] < _high[root_y])
		{
			_high[root_y] += _high[root_x];
			_parent[root_x] = root_y;
		}
		else
		{
			_high[root_x] += _high[root_y];
			_parent[root_y] = root_x;
			_high[root_x]++;
		}
		_size--;
	}

	bool InSet(int x, int y) //俩个节点是否在同一个集合
	{
		return FindRoot(x) == FindRoot(y);
	}

	size_t SetSize()
	{
		return _size;
	}

private:

	std::vector<int> _parent; //当前节点的父节点
	std::vector<int> _high; //当前树高
	int _size; //集合个数
};