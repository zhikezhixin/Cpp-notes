#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class vector
{
public:
	vector():_a(nullptr),_size(0),_capacity(0)
	{}

	vector(size_t n) :_a(new T[n]), _size(0), _capacity(0)
	{}

	~vector()
	{
		delete[] _a;
		_a = nullptr;
		_size = _capacity = 0;
	}

	void push_back(const T& x);
	void push_pop();

	int size()
	{
		return _size;
	}

	T& operator[] (size_t i)
	{
		assert(i < _size);
		return _a[i];
	}


private:
	T* _a;
	size_t _size;
	size_t _capacity;
};

template<class T>
void vector<T>::push_back(const T& x)
{
	if (_size == _capacity)
	{
		size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
		T * tmp = new T[newcapacity];
		if (_a)
		{
			memcpy(tmp, _a, sizeof(T) * _size);
			delete[] _a;
		}
		_a = tmp;
		_capacity = newcapacity;
	}
	_a[_size] = x;
	++_size;
}

template<class T>
void vector<T>::push_pop()
{
	assert(_size > 0);
	--_size;
}

int main()
{
	vector<int> v;
	for (size_t i = 1; i < 5; ++i)
	{
		v.push_back(i);
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}