#include <iostream>
using namespace std;

//�̳�
/*
class Person
{
public:
	Person(string name, int age) : m_name(name), m_age(age) {} //����Ĺ��졢��������������Ҫ
	Person(const Person& p) : m_name(p.m_name), m_age(p.m_age) {} //�����Լ��ĺ���
	Person& operator=(const Person& p) //���ظ�ֵ�����
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
	// �������еĹ��캯��������û���Ĺ��캯����ʼ������ĳ�Ա
	Student(string name, int age, int score) : Person(name, age), m_score(score) {}
	Student(const Student& s) : Person(s), m_score(s.m_score) {} 
	Student& operator=(const Student& s) //���ظ�ֵ�����
	{
		if (this != &s)
		{
			Person::operator=(s); //���û���ĸ�ֵ�����
			m_score = s.m_score;
		}
		return *this;
	}
	~Student() //���������������ͻ������������������أ���������������ʽ����
	{          //�������������������󣬻��������������Զ�����
	}         

	void show() //���أ�Ҳ��Ϊ�ض���
	{
		Person::show();
		cout << "score: " << m_score << endl;
	}
private:
	int m_score;
};
*/

//���м̳�
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
       cout << Public_Value << endl; //public�г�Ա�ɷ���
	   cout << Protected_Value << endl; //protected�г�Ա�ɷ���
	   cout << Private_Value << endl;// ����:private�г�Ա���ɷ���
   }  
};
*/


//�����̳�
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
		cout << Public_Value << endl; //public�г�Ա�ɷ���,��Base���public��Ա��Derived���б�Ϊprotected
		cout << Protected_Value << endl; //protected�г�Ա�ɷ��ʣ�Base���protected��Ա��Derived���б�Ϊprotected
		cout << Private_Value << endl;// ����:private�г�Ա���ɷ���
	}
}; 
*/

//˽�м̳�
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
		cout << Public_Value << endl; //public�г�Ա�ɷ���,��Base���public��Ա��Derived���б�Ϊprivate
		cout << Protected_Value << endl; //protected�г�Ա�ɷ��ʣ�Base���protected��Ա��Derived���б�Ϊprivate
		cout << Private_Value << endl;// ����:private�г�Ա���ɷ���
	}
};

*/


//������������Ĺ���������
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

//������������Ĺ���������
/*
class Base 
{
private:
	int value;
public:
	Base(int x) :value(x) // ��ʼ���б�
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
	// ʹ�ó�ʼ���б���û��๹�캯��
	Derived(int baseVal, int derivedVal) 
		: Base(baseVal), data(derivedVal) //���������г�ʼ�������Ա������������û���Ĺ��캯��
	{                                     //���������п�����������ԱҲ��ͬ�����û���Ŀ������캯��
		cout << "Derived constructor: " << data << endl;		

	}
	~Derived() // ����������������ʽ���û��������������
	{          //�������������������󣬻��������������Զ�����
		cout << "Derived destructor: " << endl;
	}
};

void test2()
{
	Derived d(10, 20); // �������������
}
*/


//�������ض�������еĳ�Ա����
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
	void show() //�ض�������еĳ�Ա����
	{
		Base::show(); //���û����show����
		cout << "Derived_value : " << Derived_value << endl;
	}
private:
	int Derived_value;
};

void test3()
{
	Derived d(10);
	d.show(); //�����������show����
}
*/


//���ؼ̳�


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