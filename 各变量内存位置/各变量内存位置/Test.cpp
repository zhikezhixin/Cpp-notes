#include <iostream>
using namespace std;

int GlobalVar = 1; 
static int staticGlobalVar = 1;
//GlobalVar��staticGlobalVar����ȫ�ֱ��������ھ�̬������������ȫ����main����֮ǰ�ͳ�ʼ����ȫ�ֿ��á�
// ����ʱGlobalVar�������ļ��пɼ���staticGlobalVarֻ�ڵ�ǰ�ļ��ɼ�


int main()
{
	static int staticVar = 1; 
	//staticVar������ֻ��main�����У�ֻ�е��������е������ǲų�ʼ�������ھ�̬��


	int localVar = 1;//������ջ��

	int num1[10] = { 1,2,3,4 };//������ջ��

	char char2[] = "abcd"; //�������ڴ������洢�ַ�'a''b''c''d''\0'
	                       // char2 ����ջ�����ٵ�����ֽڴ�С�ռ��
						   //��'a'b'c'd'\0'����ַ��Ӵ��������ƹ�ȥ

	const char* pchar3 = "abcd"; //��ջ�������ֲ�ָ��������洢�������ַ�����a���ĵ�ַ


	int* ptr1 = (int*)malloc(sizeof(int) * 4);// ����̬����ռ�
	int* ptr2 = (int*)calloc(4,sizeof(int));// ��̬����ռ䲢��ʼ��Ϊ0
	int* ptr3 = (int*)realloc(ptr2,sizeof(int) * 4);// ���ݺ�ԭ���ݿ������µ�ַ��������ԭ�ڴ�

	free(ptr1);
	free(ptr3);

	return 0;
}