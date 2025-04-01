#include <iostream>
using namespace std;

int GlobalVar = 1; 
static int staticGlobalVar = 1;
//GlobalVar和staticGlobalVar都是全局变量存在于静态区，作用域是全局在main函数之前就初始化，全局可用。
// 链接时GlobalVar在所有文件中可见，staticGlobalVar只在当前文件可见


int main()
{
	static int staticVar = 1; 
	//staticVar作用域只在main函数中，只有当程序运行到这里是才初始化存在于静态区


	int localVar = 1;//存在于栈区

	int num1[10] = { 1,2,3,4 };//存在与栈区

	char char2[] = "abcd"; //编译器在代码区存储字符'a''b''c''d''\0'
	                       // char2 是在栈区开辟的五个字节大小空间后，
						   //将'a'b'c'd'\0'五个字符从代码区复制过去

	const char* pchar3 = "abcd"; //在栈区创建局部指针变量，存储代码区字符串‘a’的地址


	int* ptr1 = (int*)malloc(sizeof(int) * 4);// 仅动态申请空间
	int* ptr2 = (int*)calloc(4,sizeof(int));// 动态申请空间并初始化为0
	int* ptr3 = (int*)realloc(ptr2,sizeof(int) * 4);// 扩容后将原内容拷贝到新地址，并销毁原内存

	free(ptr1);
	free(ptr3);

	return 0;
}