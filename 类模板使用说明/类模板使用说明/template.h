#pragma once
#include <iostream>
using namespace std;

// �����﷨
//��ģ��
template<class T = int>  // Ĭ��ģ�����Ϊint
class example    // ģ������������������������������
{
public:
    example() : t1(T()), p1(nullptr) // T()��һ��ͨ�ó�ʼ����ʽ
    {
        cout << "ģ��ʵ��������: " << typeid(T).name() << endl;
    }
private:
    T t1;
    T* p1;
};

//����ģ��
template<class A, class B>
auto Add(A a, B b) // ����ģ��ֻ�ܸ��ݸ����ľ���ֵ���Զ��Ƶ�����,�޷�������������ģ������Ƶ�����
{
    return a + b;
}

//ģ�����
template <typename T, class U> //��ģ������У�typename �� class û������
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

//Array<int, 5> myArray; // ����ʱֱ�Ӹ���ֵ


//Ĭ��ģ�����
template<class T1, class T2 = int, class T3 = double>
class Example
{};

Example<float> obj1; // �ȼ��� Example<float, int, double>
Example<float, char> obj2; // �ȼ��� Example<float, char, double>


template <typename T>
class MyClass
{
public:
    const T Value()const;
    void print();
private:
    T _value;
};

// ���ⶨ���Ա����
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


// ��ģ���ػ�
template <class T, class U>
class Print_type
{
public:
    void print() 
    {
        cout << "T������: " << typeid(T).name() << endl;
        cout << "U������: " << typeid(U).name() << endl;
    }
};

// ��������
template <class T>  // ���ж��ģ����������ڲ�������ģ���������ģ������ʱ����
class Print_type<T,int>
{
public:
    void print()
    {
        cout << "T������: " << typeid(T).name() << endl;
        cout << "U������: " << "int" << endl;
    }
};


template <class U>  // ���ж��ģ����������ڲ�������ģ���������ģ������ʱ����
class Print_type<double,U>
{
public:
    void print()
    {
        cout << "T������: " << typeid(T).name() << endl;
        cout << "U������: " << "double" << endl;
    }
};

template <class T, class U>
class Print_type<T*,U*>
{
public:
    void print()
    {
        cout << "T������: " << typeid(T).name() << endl;
        cout << "U������: " << typeid(U).name() << endl;
    }
};


template <> // ��ȫ����ʱ��ģ�������ÿ�
class Print_type<int, double> // �����������<>��������ģ�����������
{
public:
    void print()
    {
        cout << "T������: " << "int" << endl;
        cout << "U������: " << "double" << endl;
    }
};