#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(5);
	s.insert(7);

	set<int>::iterator it = s.begin(); 
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	set<int>::iterator tmp = s.fin (3);
	if (tmp != s.end())
	{
		s.erase(tmp);
	}
}

void test_map1()
{
	map<string, string> m;
	m.insert(pair<string, string>("数字", "number"));
	m.insert(pair<string, string>("罗马", "roam"));
	m.insert(pair<string, string>("喜欢", "like"));
	m.insert(pair<string, string>("打扰", "disturbe"));
	map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}

}

//统计水果出现次数
void test_solution()
{
	string fruit[] = {"西瓜","樱桃","哈密瓜","香蕉","西瓜", "哈密瓜", "哈密瓜", "哈密瓜","樱桃","樱桃", };
	map<string, int> count;
	for (auto& fr : fruit)
	{
		//法一
		/*map<string, int>::iterator it = count.find(fr);
		if (it != count.end())
		{
			it->second++;
		}
		else
		{
			count.insert(make_pair(fr,1));
		}*/
		//法二
		/*pair<map<string, int>::iterator, bool> ret = count.insert(make_pair(fr,1));
		if (ret.second == false)
		{
			ret.first->second++;
		}*/
		//insert插入成功返回插入节点迭代器和trut,已存在则插入失败，返回已存在节点迭代器和false

		//法三
		count[fr]++;
		//operator[],如果key在map中，返回value的引用；如果key不在map中，插入key返回value的引用 
	}
	for (auto& num : count)
	{
		cout << num.first << ":" << num.second << endl;
	}
	
}

//给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) 
	{
		map<string, int> m;
		for (string& s : words)
		{
			m[s]++;
		}

		multimap<int, string,greater<int>> mm;
		for (pair<string, int> tmp : m)
		{
			mm.insert(make_pair(tmp.second,tmp.first));
		}

		vector<string> v;
		
		multimap<int, string>::iterator it = mm.begin();
		while (it != mm.end())
		{
			if (k == 0)
				break;

			v.push_back(it->second);
			it++;
			k--;
		}
		return v;
	}
};
int main()
{
	test_set1(); 
	test_map1();
	test_solution();
	return 0;
}