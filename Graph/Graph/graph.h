#pragma once

// 图graph  顶点vertex  边edge
//树是一种特殊（无环连通）的图，树关注的是顶点中存的值，图关注的是顶点及边的权值
#include <vector>  
#include <map>
#include <queue>
#include <string>
#include "D:\CodeManager\VisualStudio\C++PrimerPlus\Cpp-notes\并查集\并查集\UnionFindSet.h"

namespace AdjacentMatrix // 邻接矩阵
{
	using namespace std;
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false >
	class graph
	{

		typedef graph(V, W, MAX_W, Direction) self;
	public:
		graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_matrix.resize(n);
			for (size_t i = 0; i < _matrix.size(); i++)
			{
				_matrix[i].resize(n, INTMAX_MAX);
			}
		 }

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
		}

		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;

			if (Direction == false)
				_matrix[dsti][srci] = w;
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			_AddEdge(srci, dsti, w);
		 }

		void BFS( cosnt V& src)
		{
			size_t srci = GetVertexIndex(src);
			queue<int> q;
			vector<bool> visited(_vertexs.size(), false); //标记数组
			q.push(srci);
			visited[srci] = true;

			while (!q.empty)
			{
				int front = q.front();
				q.pop();
				cout << front << ":" << _vertexs[front] << endl;
				for (size_t i = 0; i < n; i++)
				{
					if (_matrixs[front][i] != MAX_W)
					{
						if (visited[i] == false)
						{
							q.push(i);
							visited[i] == true;
						}
					}	
				}
			}

			void _DBS(size_t srci, vector<bool>&visited)
			{
				cout << srci << ":" << _vertexs[srci] << endl;
				visited[srci] = true;

				for (size_t i = 0; i < _vertexs.size(); i++)
				{
					if (_matrix[srci][i] != INT_MAX && visited[srci] == false)
					{
						_DBS(i, visited);
					}
				}
			}

			void DBS(const V& src)
			{
				size_t srci = GetVertexIndex(src);
				vector<bool> visited(_vertexs.size(), false); //标记数组

				_DBS(srci, vector);
			}

			struct Edge
			{
				size_t _srci;
				size_t _dsti;
				W _w;

				Edge(size_t srci , size_i dsti , const W& w)
					:_srci(srci),_dsti(dsti),_w(w)
				{}

				bool operator < (const Edge& e) const
				{
					return _w > e._w
				}
			};

			W KrusKal(self& minTree)
			{
				size_t n = _vertexs.size();
				minTree._vertexs = _vertexs;
				minTree._indexMap = _indexMap;
				minTree._matrix.resize(n);
				for (size_t i = 0; i < n; i++)
				{
					minTree._matrix[i].resize(n, INT_MAX);
				}

				priority_queue<Edge, vector<Edge>, greator<Edge>> minque;
				
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (i < j && _matrix[i][j] != INT_MAX)
							minque.push(Edge(i,j,_matrix[i][j]));
					}
				}

				int size = 0;
				W totalW = W();
				UnionFindSet ufs(n);
				while (!minque.empty())
				{
					Edge min = minque.top();
					minque.pop();

					if (!ufs.InSet(min._srci, min._dsti))
					{
						minTree._AddEdge(min._srci, min._dsti, min._w);
						ufs(min._srci, min._dsti);
						size++;
						totalW += min._w;
					}
				}

				if (size = n - 1)
					return totalW;
				else
					return w();
			}

		}

	private:

		vector<V> _vertexs; // 顶点集合
		map<V, int> _indexMap; // 顶点下标
		vector<vector<W>> _matrix;
	};
}



namespace LinkTable // 邻接表
{
	template<class W>
	struct Edge
	{
		int _dsti; // 目标点下标
		W _w; // 权值
		Edge<W>* _next;

		Edge(int dsti, const W& w)
			:_dsti(dsti),_w(w),_next(nullptr)
		{ }
	};

	template<class V, class W, bool Direction = false >
	class graph
	{
		typedef Edge<W> Edge;
	public:
		graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_tables.resize(n, nullptr);

		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if(it != _indexMap.end())
			{
				return it->second;
			}
			else
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			Edge* eg = new Edge(dsti, w);
			eg->_next = _tables[srci];
			_tables[srci] = eg;

			if (Direction == false)
			{
				Edge* eg = new Edge(srci, w);
				eg->_next = _tables[dsti];
				_tables[dsti] = eg;
			}
		}

		void print()
		{
			for (size_t i = 0; i < _vertexs.size(); i++)
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			cout << endl;

			for (size_t i = 0; i < _tables.size(); i++)
			{
				cout << _vetexs[i] << "[" << i << "]->";
				Edge* cur = _tables[i];
				while (cur)
				{
					cout << _vertex[cur->_dsti] << "[" << cur->_dsti << "]" << cur->_w << "->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}


			
		}

	private:

		vector<V> _vertexs; // 顶点集合
		map<V, int> _indexMap; // 顶点下标
		vector<Edge*> _tables; //邻接表
	};
}
