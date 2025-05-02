#pragma once
#include <iostream>
using namespace std;

// 基本语法
//类模板
template<class T = int>  // 默认模板参数为int
class example    // 模板参数声明必须紧挨类声明或函数声明
{
public:
    example() : t1(T()), p1(nullptr) // T()是一种通用初始化方式
    {
        cout << "模板实例化类型: " << typeid(T).name() << endl;
    }
private:
    T t1;
    T* p1;
};

//函数模板
template<class A, class B>
auto Add(A a, B b) // 函数模板只能根据给定的具体值来自动推导类型,无法根据其他函数模板参数推导类型
{
    return a + b;
}

//模板参数
template <typename T, class U> //在模板参数中，typename 和 class 没有区别
class Pair                    
{
private:
    T first;
    U second;
public:
    Pair(T a, U b) : first(a), second(b) 
    {
    }
};


template <typename T, size_t Size>
class Array 
{
private:
    T data[Size];
public:

    size_t size() const 
    {
        return Size;
    }
};

//Array<int, 5> myArray; // 调用时直接给定值


//默认模板参数
template<class T1, class T2 = int, class T3 = double>
class Example
{};

Example<float> obj1; // 等价于 Example<float, int, double>
Example<float, char> obj2; // 等价于 Example<float, char, double>


template <typename T>
class MyClass
{
public:
    const T Value()const;
    void print();
private:
    T _value;
};

// 类外定义成员函数
template <typename T>
const T MyClass<T>::Value()const
{
    return _Value;
}

template <typename T>
void MyClass<T>::print()
{
    std::cout << "Value: " << value << std::endl;
}


// 类模板特化
template <class T, class U>
class Print_type
{
public:
    void print() 
    {
        cout << "T的类型: " << typeid(T).name() << endl;
        cout << "U的类型: " << typeid(U).name() << endl;
    }
};

// 部分例化
template <class T>  // 若有多个模板参数，对于不例化的模板参数仍在模板声明时给出
class Print_type<T,int>
{
public:
    void print()
    {
        cout << "T的类型: " << typeid(T).name() << endl;
        cout << "U的类型: " << "int" << endl;
    }
};


template <class U>  // 若有多个模板参数，对于不例化的模板参数仍在模板声明时给出
class Print_type<double,U>
{
public:
    void print()
    {
        cout << "T的类型: " << typeid(T).name() << endl;
        cout << "U的类型: " << "double" << endl;
    }
};

template <class T, class U>
class Print_type<T*,U*>
{
public:
    void print()
    {
        cout << "T的类型: " << typeid(T).name() << endl;
        cout << "U的类型: " << typeid(U).name() << endl;
    }
};


template <> // 完全例化时，模板声明置空
class Print_type<int, double> // 在类名后加上<>给出所有模板参数的类型
{
public:
    void print()
    {
        cout << "T的类型: " << "int" << endl;
        cout << "U的类型: " << "double" << endl;
    }
};