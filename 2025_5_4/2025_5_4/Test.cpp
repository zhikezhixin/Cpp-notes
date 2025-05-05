#include <iostream> 
using namespace std;

//��̬
//virtual�ؼ��֣�1.��������ԭ��Ա����������麯������д��2.�����μ̳��������̳У������������Ͷ���������
//��Ȼ�����ط�ʹ��ͬһ���ؼ��֣�����û���κι���

/*
//��̬������������1.�麯������д��2.��������ָ���������ȥ�����麯��
//�����̬:�����ö���������޹أ���ָ������йأ�ָ���Ǹ�����͵����ĸ�������麯��
//�������̬:�����ö���������йأ�������ʲô���õľ���˭���麯��
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
	virtual void BuyTicket() //�麯������д��1.��������ͬ��2.�����б���ͬ��3.����ֵ������ͬ��
	{
		cout << "class Student" << endl;
	}
};
void show(Person& p)  // ��ʽ��������ת������������Ķ���ת��Ϊ��������û�ָ�롣
{                     // ԭ����������̳��˻�������й������ܱ�����Ա����������������Ա���ȫ����Ϊ��������һ��
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
//Э��(����������ຯ������ֵ��ͬ��һ���������):
//1.������麯������ֵ��������ָ����������͡�2.��������麯������ֵ������������ָ����������͡�
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
	//Student* BuyTicket() ����д�����麯��ʱ����������麯�����Բ���virtual�ؼ���
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
// ��������Ҫ���麯����д
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
	virtual ~Student()  //���������ĺ������ᱻ�����destructor
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
	virtual void TEST() //������������A* this �������ָ��
	{                  //A* this = p �������ָ��ָ�����������
		func(); 
	}              
};
class B : public A
{
public:
	virtual void func(int val = 2) //�̳л��ຯ���ķ���ֵ���ͺͲ����б��Ĭ�ϲ���
	{                              //��д����������
		cout << "B::func( " << val << ") " << endl;
	}
};
void test3()
{
	A* p = new B;
	p->TEST(); //��ʽ����ת��:p->func(p)
	delete p;
}
*/

//final�ؼ���:��final���ε�������麯�����ܱ��̳л���д
//override�ؼ���: ��������麯���Ƿ���д�˸�����麯��


//����:������ͬһ�������У���������ͬ�������б�ͬ(����������ͬ��������Ͳ�ͬ)
//��д�����ǣ�:�����ֱ��ڻ�����������������У���������ͬ�������б���ͬ������ֵ������ͬ(����ֵ���Ϳ��Բ�ͬ)��
// �Ժ�����ʵ�ֽ�����д����д��Ḳ���麯�����еĺ�����ַ
//�ض���(����):�����ֱ��ڻ�����������������У���������ͬ

/*
//������:�������麯�����࣬����ʵ��������ֻ����Ϊ����ʹ��
//���麯��:�ڻ�������������ʵ�ֵ��麯��������������������д
class Car
{
public:
	virtual void Run() = 0; //���麯����ʾ��ʽ��ֻ��������=0��ʾ�ú���û��ʵ�֣�����������������д
	virtual void Stop() = 0; 
};

class Benz : public Car
{	
public:
	virtual void Run() 
	{                  
		cout << "Benz Run" << endl;
	}
	virtual void Stop() //��д
	{
		cout << "Benz Stop" << endl;
	}
};
*/

/*
//�麯��ԭ��:
//1.�麯����:ÿ���඼��һ���麯����ͨ��һ������ָ������洢������麯����ַ
//2.�麯����ָ��:ÿ��������һ���麯����ָ�룬ָ��ö�����������麯����
//3.ͨ������ָ������õ����麯��ʱ��ָ������Ǹ����͵Ķ��󣬱���������ݸ�
//������麯����ָ���ҵ���Ӧ�ı������麯����ַ���Ӷ�ʵ�ֶ�̬��
//4.�����Լ�û�����ָ�룬���������ǰ����ڸ���̳������ĸ�������
class Person
{
public :
	virtual void BuyTicket() { cout<< " ȫ�� " << endl; }
};
class Student : public Person
{
public:
	virtual void BuyTicket() { cout << " ��� " << endl; }
	//��д����д��ɺ������̳и�������ָ�룬������ĵ����Ḳ��ԭ��������ַ
	//�����������䣬�Դ洢���Ǹ���ĺ�����ַ
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


//��ӡ�麯����
//���̳�
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
typedef void(*FuncPtr)(); //void(*)()��һ������ָ�����ͣ����д����ʾ��FuncPtr����Ϊһ������ָ������
void PrintVFTable(FuncPtr* pVTable)
{
	
	for (size_t i = 0; pVTable[i] != 0; i++)
	{
		printf(" pVTable[%d]:%p->", i, pVTable[i]);
		FuncPtr f = pVTable[i];
		f(); //��ʾ���� f ��ָ��ĺ���
	}
	cout << endl;
}
//void test4()
//{
//	Base b1;
//	Derive d1;
//	//ȡ������ǰ�ĸ��ֽڴ���麯����ָ��
//	PrintVFTable((FuncPtr*)(*(size_t*)&b1)); //ȡ��b�ĵ�ַ��ת��Ϊint*���ͺ�����ã����ǿתΪFuncPtr*
//	PrintVFTable((FuncPtr*)(*(size_t*)&d1));
//}
//��̳�
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
	PrintVFTable((FuncPtr*)(*(size_t*)( (char*)&d2 + sizeof(Base1) )));//ȡ����ַ����ǿתΪchar*���ټӴ�С�ƶ�ָ��
	//��̳������м���������м������
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