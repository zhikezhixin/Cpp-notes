#include <iostream>
using namespace std;

//class Building;//提前声明
//class GoodGay
//{
//public:
//	GoodGay();
//	
//	Building* building;//类内声明另一个类 但是不会调用构造函数
//	void visit1();//让visit函数可以访问Building中的属性
//	void visit2();//让visit函数可以访问Building中的属性
//
//};
//
//class Building
//{
//	friend void GoodGay::visit1();//全局函数visit1作为Building的好朋友，可以访问Building中的私有成员
//public:
//	Building();//类外实现构造函数
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
//
//Building::Building() //类外实现构造函数
//{
//	m_BedRoom = "卧室";
//	m_SittingRoom = "客厅";
//}
//
//GoodGay::GoodGay()//类外构造函数的实现
//{
//	building = new Building;//在构造函数中创建对象
//	//用new在堆区创建对象，并且返回地址（new出来的空间需要手动释放）
//}
//
//void GoodGay::visit1()
//{
//	cout << "好基友正在访问：" << building->m_SittingRoom << endl;
//	cout << "好基友正在访问：" << building->m_BedRoom << endl;
//}
//void GoodGay::visit2()
//{
//	cout << "好基友正在访问：" << building->m_SittingRoom << endl;
//	//cout << "好基友正在访问：" << building->m_BedRoom << endl;
//}
//void test01()
//{
//	GoodGay gg;//创建对象
//	gg.visit1();//访问函数
//	gg.visit2();
//}
//
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

