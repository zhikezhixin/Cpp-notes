#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace CLOSE_HASH
{


	enum State {
		EMPTY,
		EXITS,
		DELETE
	};

	// Hash 节点
	template<class T>
	struct HashData {
		T _data;
		State _state = EMPTY;
	};

	// set 的键提取器：元素本身就是键
	template<class K>
	struct SetKeyOfT {
		const K& operator()(const K& key) const {
			return key;
		}
	};

	// map 的键提取器：pair 的 first 是键
	template<class K, class V>
	struct MapKeyOfT {
		const K& operator()(const pair<K, V>& kv) const {
			return kv.first;
		}
	};

	// 哈希表模板
	template<class K, class T, class KeyOfT>
	class HashTable {
	public:
		HashTable()
			: _num(0)
		{
		}

		bool Insert(const T& d) {
			KeyOfT koft;

			// 扩容
			if (_table.size() == 0 || _num * 10 / _table.size() >= 7) {
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				vector<HashData<T>> newtables(newsize);

				for (size_t i = 0; i < _table.size(); ++i) {
					if (_table[i]._state == EXITS) {
						size_t index = hash(koft(_table[i]._data)) % newsize;
						while (newtables[index]._state == EXITS) {
							index = (index + 1) % newsize;
						}
						newtables[index] = _table[i];
					}
				}

				_table.swap(newtables);
			}

			// 插入
			size_t index = hash(koft(d)) % _table.size();
			while (_table[index]._state == EXITS) {
				if (koft(_table[index]._data) == koft(d)) {
					return false; // 已存在
				}
				index = (index + 1) % _table.size();
			}

			_table[index]._data = d;
			_table[index]._state = EXITS;
			++_num;
			return true;
		}

		HashData<T>* Find(const K& key) {
			KeyOfT koft;
			size_t index = hash(key) % _table.size();

			while (_table[index]._state != EMPTY) {
				if (_table[index]._state == EXITS && koft(_table[index]._data) == key) {
					return &_table[index];
				}
				index = (index + 1) % _table.size();
			}

			return nullptr;
		}

		bool Erase(const K& key) {
			HashData<T>* ret = Find(key);
			if (ret) {
				ret->_state = DELETE;
				--_num;
				return true;
			}
			return false;
		}

	private:
		hash<K> hash; // 默认哈希函数对象
		vector<HashData<T>> _table;
		size_t _num;
	};

}

namespace OPEN_HASH
{

	// 节点定义
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data), _next(nullptr)
		{
		}
	};

	// set 的键提取器：元素本身就是键
	template<class K>
	struct SetKeyOfT {
		const K& operator()(const K& key) const {
			return key;
		}
	};

	// map 的键提取器：pair 的 first 是键
	template<class K, class V>
	struct MapKeyOfT {
		const K& operator()(const pair<K, V>& kv) const {
			return kv.first;
		}
	};

	// 默认 Hash 函数：对整型使用
	template<class K>
	struct DefaultHash {
		size_t operator()(const K& key) const {
			return key;
		}
	};

	// 针对 string 类型的哈希仿函数
	struct HashString {
		size_t operator()(const string& s) const {
			size_t hash = 0;
			for (char ch : s)
				hash = hash * 131 + ch;
			return hash;
		}
	};

	template<class K, class T, class KeyOfT, class Hash = DefaultHash<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

	public:
		bool Insert(const T& data)
		{
			KeyOfT koft;
			Hash hash;

			if (_tables.size() == _num)
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newtables(newsize);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = hash(koft(cur->_data)) % newsize;
						cur->_next = newtables[index];
						newtables[index] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}

			size_t index = hash(koft(data)) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
					return false;
				cur = cur->_next;
			}

			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_num;
			return true;
		}

		Node* Find(const K& key)
		{
			KeyOfT koft;
			Hash hash;

			if (_tables.empty()) return nullptr;
			size_t index = hash(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			KeyOfT koft;
			Hash hash;

			if (_tables.empty()) return false;
			size_t index = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (prev == nullptr)
						_tables[index] = cur->_next;
					else
						prev->_next = cur->_next;

					delete cur;
					--_num;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _num = 0;
	};

}