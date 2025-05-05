#include <iostream> 
using namespace std;

//多态
//virtual关键字：1.可以修饰原成员函数，完成虚函数的重写。2.在菱形继承中完成虚继承，解决数据冗余和二义性问题
//虽然俩个地方使用同一个关键字，但是没有任何关联

/*
//多态的俩个条件：1.虚函数的重写。2.父类对象的指针或者引用去调用虚函数
//满足多态:跟调用对象的类型无关，跟指向对象有关，指向那个对象就调用哪个对象的虚函数
//不满足多态:跟调用对象的类型有关，类型是什么调用的就是谁的虚函数
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "class Person" << endl;
	}
};
class Student : public Person
{
public :
	virtual void BuyTicket() //虚函数的重写：1.函数名相同。2.参数列表相同。3.返回值类型相同。
	{
		cout << "class Student" << endl;
	}
};
void show(Person& p)  // 隐式向上类型转换：将派生类的对象转换为基类的引用或指针。
{                     // 原因是派生类继承了基类的所有公共和受保护成员，因此派生类对象可以被安全地视为基类对象的一种
	p.BuyTicket();
}

void test1()
{
	Person p;
	Student s;
	show(p);
	show(s);
}
*/

/*
//协变(基类和派生类函数返回值不同的一种特殊情况):
//1.基类的虚函数返回值基类对象的指针或引用类型。2.派生类的虚函数返回值是派生类对象的指针或引用类型。
class Person
{	
public:
	virtual Person* BuyTicket()
	{
		cout << "class Person" << endl;
		return this;
	}
};
class Student : public Person
{
public:
	//Student* BuyTicket() 在重写基类虚函数时，派生类的虚函数可以不加virtual关键字
	virtual Student* BuyTicket() 
	{
		cout << "class Student" << endl;
		return this;
	}
};
void show(Person& p)  
{                     
	p.BuyTicket();
}
void test2()
{
	Person p;
	Student s;
	show(p);
	show(s);
}
*/

/*
// 析构函数要用虚函数重写
class Persong
{
public:
	virtual ~Persong() 
	{
		cout << "class Person" << endl;
	}
};
class Student : public Persong
{
public:
	virtual ~Student()  //析构函数的函数名会被处理成destructor
	{
		cout << "class Student" << endl;
	}
};
*/

/*
class A
{
public:
	virtual void func( int val = 1)
	{
		cout << "A::func( " << val << ") " << endl;
	}
	virtual void TEST() //（）中隐含着A* this 基类对象指针
	{                  //A* this = p 基类对象指针指向派生类对象
		func(); 
	}              
};
class B : public A
{
public:
	virtual void func(int val = 2) //继承基类函数的返回值类型和参数列表和默认参数
	{                              //重写函数体内容
		cout << "B::func( " << val << ") " << endl;
	}
};
void test3()
{
	A* p = new B;
	p->TEST(); //隐式类型转换:p->func(p)
	delete p;
}
*/

//final关键字:被final修饰的类或者虚函数不能被继承或重写
//override关键字: 检查子类虚函数是否重写了父类的虚函数


//重载:函数在同一作用域中，函数名相同，参数列表不同(参数个数不同或参数类型不同)
//重写（覆盖）:函数分别在基类和派生类作用域中，函数名相同，参数列表相同，返回值类型相同(返回值类型可以不同)，
// 对函数的实现进行重写，重写后会覆盖虚函数表中的函数地址
//重定义(隐藏):函数分别在基类和派生类作用域中，函数名相同

/*
//抽象类:包含纯虚函数的类，不能实例化对象，只能作为基类使用
//纯虚函数:在基类中声明但不实现的虚函数，必须在派生类中重写
class Car
{
public:
	virtual void Run() = 0; //纯虚函数表示方式，只作声明，=0表示该函数没有实现，必须在派生类中重写
	virtual void Stop() = 0; 
};

class Benz : public Car
{	
public:
	virtual void Run() 
	{                  
		cout << "Benz Run" << endl;
	}
	virtual void Stop() //重写
	{
		cout << "Benz Stop" << endl;
	}
};
*/

/*
//虚函数原理:
//1.虚函数表:每个类都有一个虚函数表，通过一个函数指针数组存储该类的虚函数地址
//2.虚函数表指针:每个对象都有一个虚函数表指针，指向该对象所属类的虚函数表
//3.通过父类指针或引用调用虚函数时，指向的是那个类型的对象，编译器会根据该
//对象的虚函数表指针找到对应的被调用虚函数地址，从而实现动态绑定
//4.子类自己没有虚表指针，子类的虚表是包含在父类继承下来的父类对象的
class Person
{
public :
	virtual void BuyTicket() { cout<< " 全价 " << endl; }
};
class Student : public Person
{
public:
	virtual void BuyTicket() { cout << " 半价 " << endl; }
	//重写，重写完成后，子类会继承父类的虚表指针，但子类的的虚表会覆盖原来函数地址
	//而父类的虚表不变，仍存储的是父类的函数地址
};
void func(Person& p)
{
	p.BuyTicket();
}
void test3()
{
	Person p;
	Student s;
	func(p);
	func(s);
}
*/


//打印虚函数表
//单继承
//class Base
//{
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int _a;
//};
//class Derive : public Base
//{		
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int _b;
//};
typedef void(*FuncPtr)(); //void(*)()是一个函数指针类型，该行代码表示将FuncPtr定义为一个函数指针类型
void PrintVFTable(FuncPtr* pVTable)
{
	
	for (size_t i = 0; pVTable[i] != 0; i++)
	{
		printf(" pVTable[%d]:%p->", i, pVTable[i]);
		FuncPtr f = pVTable[i];
		f(); //表示调用 f 所指向的函数
	}
	cout << endl;
}
//void test4()
//{
//	Base b1;
//	Derive d1;
//	//取出对象前四个字节存的虚函数表指针
//	PrintVFTable((FuncPtr*)(*(size_t*)&b1)); //取出b的地址，转化为int*类型后解引用，最后强转为FuncPtr*
//	PrintVFTable((FuncPtr*)(*(size_t*)&d1));
//}
//多继承
class Base1
{
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int _b1;
};
class Base2
{
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int _b2;
};
class Derive : public Base1, public Base2
{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int _d;
};
void test5()
{
	cout << " sizeof(Derive):" << sizeof(Derive) << endl;
	Derive d2;
	PrintVFTable((FuncPtr*)(*(size_t*)&d2));
	PrintVFTable((FuncPtr*)(*(size_t*)( (char*)&d2 + sizeof(Base1) )));//取出地址后先强转为char*，再加大小移动指针
	//多继承子类有几个父类就有几个虚表
}


int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}