#pragma once 

// 四种压缩路径下的加权并查集
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <string>
#include <random>
using namespace std;

enum class CompressionMode //四种路径压缩方式
{
	NONE,
	FULL,
	HALVE,
	SPLIT
};
typedef CompressionMode CPM;

template<class NODE , CPM M>
struct FindPolicy;  // 声明查找策略类

//逐一特化
template<class NODE>
struct FindPolicy<NODE, CPM::NONE>
{
	static NODE apply(vector<NODE>& parent, NODE cur) // 不作路径压缩
	{
		while (parent[cur] != cur)
			cur = parent[cur];
		return cur;
	}
};

template<class NODE>
struct FindPolicy<NODE, CPM::FULL> // 完全路径压缩
{
	static NODE apply(vector<NODE>& parent, NODE cur)
	{
		NODE x = cur;
		while (parent[x] != x) x = parent[x];   // 找根

		while (parent[cur] != cur)  // 回溯压缩
		{
			NODE p = parent[cur];
			parent[cur] = x;
			cur = p;
		}

		return x;
	}
};

template<class NODE>
struct FindPolicy<NODE, CPM::HALVE> // 折半路径压缩
{
	static NODE apply(vector<NODE>& parent, NODE cur)
	{
		while (parent[cur] != cur)
		{
			parent[cur] = parent[parent[cur]]; // 直接将父指针指向祖父
			cur = parent[cur]; // 将cur祖父作为当前指针
		}

		return cur;
	}
};

template<class NODE>
struct FindPolicy<NODE, CPM::SPLIT> // 分裂路径压缩
{
	static NODE apply(vector<NODE>& parent, NODE cur)
	{
		while (parent[cur] != cur)
		{
			NODE p = parent[cur];
			NODE gp = parent[p];

			parent[cur] = gp; // 直接将父指针指向祖父
			cur = p; // 将cur父亲作为当前指针
		}

		return cur;
	}
};

template<class NodeType , CPM mode = CPM::FULL>
class WUFS
{
public:
	WUFS() : _SetQuantity(0) {};

	WUFS(const vector<NodeType>& data)
	{
		const size_t n = data.size();
		 _parent.resize(n);
		_SetSize.resize(n, 1);
		_SetQuantity = n;
		_IndexMap.reserve((size_t)(n * 1.3));
		for (size_t i = 0; i < n; i++)
		{
			auto[it,ok] = _IndexMap.emplace(data[i] , i);
			if (!ok)
				assert(false && "存在元素重复插入");
			_parent[i] = i;
		}
	};

	const size_t* TryGetIndex(const NodeType& node) const
	{
		auto it = _IndexMap.find(node);

		return (it == _IndexMap.end()) ? nullptr : &(it->second);
	}

	size_t GetIndex(const NodeType& node )
	{
		auto it = _IndexMap.find(node);

		if (it != _IndexMap.end())
			return it->second;

		size_t index = _parent.size();
		_IndexMap[node] = index;
		_parent.push_back(index);
		_SetSize.push_back(1);
		_SetQuantity++;

		return index;
	}


	size_t FindRoot(size_t x)
	{
		assert(x < _parent.size());
		return FindPolicy<size_t, mode>::apply(_parent, x);
	}

	

	bool Union(const NodeType& n1, const NodeType& n2)
	{
		if (n1 == n2) return false;

		size_t index_n1 = GetIndex(n1);
		size_t index_n2 = GetIndex(n2);
		size_t root_n1 = FindRoot(index_n1);
		size_t root_n2 = FindRoot(index_n2);

		if (root_n1 == root_n2) return false;

		//按集合大小合并 - > 小集合合并大集合
		if (_SetSize[root_n1] < _SetSize[root_n2])
		{
			_SetSize[root_n2] += _SetSize[root_n1];
			_parent[root_n1] = root_n2;
		}
		else
		{
			_SetSize[root_n1] += _SetSize[root_n2];
			_parent[root_n2] = root_n1;
		}
		_SetQuantity--;

		return true;
	}


	bool SameSet(const NodeType & n1, const NodeType & n2)
	{
		auto it1 = _IndexMap.find(n1);
		auto it2 = _IndexMap.find(n2);

		// 任一节点不存在，则无法比较
		if (it1 == _IndexMap.end() || it2 == _IndexMap.end())
			return false;

		size_t root1 = FindRoot(it1->second);
		size_t root2 = FindRoot(it2->second);

		if (root1 == root2)
			return true;

		return false;
	}



	size_t GetSetQuantity() const
	{
		return _SetQuantity;
	}

	bool IsExist(const NodeType& node) const
	{
		return _IndexMap.count(node);
	}

private:
	unordered_map<NodeType, size_t> _IndexMap; // 建立节点-数字关系映射
	vector<size_t> _parent; // 记录每个节点的父节点
	vector<size_t> _SetSize; // 记录每个集合大小
	size_t _SetQuantity; // 记录集合数量
};

template <class NodeType , CPM Mode>
void PrintSet(WUFS<NodeType, Mode>& wufs, const vector<NodeType>& sample)
{
	unordered_map<size_t, vector<NodeType>> parts;
	parts.reserve(sample.size());

	for (auto& tmp: sample)
	{
		if (auto pidx = wufs.TryGetIndex(tmp)) 
		{
			size_t root = wufs.FindRoot(*pidx);
			parts[root].push_back(tmp);
		}
	}

	cout << "---------当前集合划分---------" << endl;
	for (auto& tmp : parts)
	{
		cout <<"根节点下标为-> " << tmp.first << " : ";
		for (auto& tem : tmp.second)
		{
			cout << tem << " , ";
		}
		cout << endl;
	}
}