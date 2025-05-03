#include <iostream>
using namespace std;

//继承
/*
class Person
{
public:
	Person(string name, int age) : m_name(name), m_age(age) {} //基类的构造、拷贝、析构都需要
	Person(const Person& p) : m_name(p.m_name), m_age(p.m_age) {} //调用自己的函数
	Person& operator=(const Person& p) //重载赋值运算符
	{
		if (this != &p)
		{
			m_name = p.m_name;
			m_age = p.m_age;
		}
		return *this;
	}
	~Person() {}
	void show()
	{
		cout << "name: " << m_name << " age: " << m_age << endl;
	}
private:
	string m_name;
	int m_age;
};
class Student : public Person
{
public:
	// 派生类中的构造函数必须调用基类的构造函数初始化基类的成员
	Student(string name, int age, int score) : Person(name, age), m_score(score) {}
	Student(const Student& s) : Person(s), m_score(s.m_score) {} 
	Student& operator=(const Student& s) //重载赋值运算符
	{
		if (this != &s)
		{
			Person::operator=(s); //调用基类的赋值运算符
			m_score = s.m_score;
		}
		return *this;
	}
	~Student() //派生类析构函数和基类析构函数构成重载，基类析构无需显式调用
	{          //派生类析构函数结束后，基类析构函数会自动调用
	}         

	void show() //隐藏，也称为重定义
	{
		Person::show();
		cout << "score: " << m_score << endl;
	}
private:
	int m_score;
};
*/

//公有继承
/*
class Base
{
public:
	Base():Public_Value(1),Protected_Value(2),Private_Value(3){}
	int Public_Value;
protected:
	int Protected_Value;
private:
	int Private_Value;
};

class Derived : public Base  
{  
public:  
   void PrintDerived()  
   {  
       cout << Public_Value << endl; //public中成员可访问
	   cout << Protected_Value << endl; //protected中成员可访问
	   cout << Private_Value << endl;// 报错:private中成员不可访问
   }  
};
*/


//保护继承
/*
class Base
{
public:
	Base() :Public_Value(1), Protected_Value(2), Private_Value(3) {}
	int Public_Value;
protected:
	int Protected_Value;
private:
	int Private_Value;
};

class Derived : protected Base
{
public:
	void PrintDerived()
	{
		cout << Public_Value << endl; //public中成员可访问,但Base类的public成员在Derived类中变为protected
		cout << Protected_Value << endl; //protected中成员可访问，Base类的protected成员在Derived类中变为protected
		cout << Private_Value << endl;// 报错:private中成员不可访问
	}
}; 
*/

//私有继承
/*
class Base
{
public:
	Base() :Public_Value(1), Protected_Value(2), Private_Value(3) {}
	int Public_Value;
protected:
	int Protected_Value;
private:
	int Private_Value;
};

class Derived : private Base
{
public:
	void PrintDerived()
	{
		cout << Public_Value << endl; //public中成员可访问,但Base类的public成员在Derived类中变为private
		cout << Protected_Value << endl; //protected中成员可访问，Base类的protected成员在Derived类中变为private
		cout << Private_Value << endl;// 报错:private中成员不可访问
	}
};

*/


//基类与派生类的构造与析构
/*
class Base 
{
public:
	Base() 
	{ 
		cout << "Base constructor\n";
	}
	~Base() 
	{ 
		cout << "Base destructor\n";
	}
};

class Derived : public Base 
{
public:
	Derived() 
	{ 
		cout << "Derived constructor\n";
	}
	
};

void test1()
{
	Derived d; 
} 
*/

//基类与派生类的构造与析构
/*
class Base 
{
private:
	int value;
public:
	Base(int x) :value(x) // 初始化列表
	{
		cout << "Base constructor: " << value << endl;
	}
	~Base()
	{
		cout << "Base destructor: " << endl;
	}
};

class Derived : public Base 
{
private:
	int data;
public:
	// 使用初始化列表调用基类构造函数
	Derived(int baseVal, int derivedVal) 
		: Base(baseVal), data(derivedVal) //在派生类中初始化基类成员函数，必须调用基类的构造函数
	{                                     //在派生类中拷贝构造基类成员也是同样调用基类的拷贝构造函数
		cout << "Derived constructor: " << data << endl;		

	}
	~Derived() // 在派生类中无需显式调用基类的析构函数，
	{          //派生类析构函数结束后，基类析构函数会自动调用
		cout << "Derived destructor: " << endl;
	}
};

void test2()
{
	Derived d(10, 20); // 创建派生类对象
}
*/


//派生类重定义基类中的成员函数
/*
class Base
{
public:
	Base(int x = 0) :base_value(x) {}
	void show()
	{
		cout << "base_value : " << base_value << endl;
	}
private:
	int base_value;
};

class Derived : public Base
{
public:
	Derived(int x = 0) :Base(x), Derived_value(x) {} 
	void show() //重定义基类中的成员函数
	{
		Base::show(); //调用基类的show函数
		cout << "Derived_value : " << Derived_value << endl;
	}
private:
	int Derived_value;
};

void test3()
{
	Derived d(10);
	d.show(); //调用派生类的show函数
}
*/


//多重继承


class A  
{  
public:  
    void show()  
    {  
        cout << "Class A" << endl;  
    }  
};  

class B : virtual public A  
{  
public:  
    void showB()  
    {  
        cout << "Class B" << endl;  
    }  
};  

class C : virtual public A  
{  
public:  
    void showC()  
    {  
        cout << "Class C" << endl;  
    }  
};  

class D : public B, public C  
{  
public:  
    void showD()  
    {  
        cout << "Class D" << endl;  
    }  
};  

void test4()  
{  
    D d;  
    d.showD();  
    d.show();   
}





int main()
{
	//Student s("zhangsan", 18, 100);
	//s.show();
	//test1();
	//test2();
	//test3();
	test4();
	return 0; 
}