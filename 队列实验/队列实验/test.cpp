#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
//�����Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���β��㡣
// �Ա�д��Ӧ���ÿնӡ��жӿա���Ӻͳ��ӵ��㷨����ͨ��������֤֮��

int main()
{
	Queue q;
	InitQueue(&q);
	/*for (char i = 'a'; i <= 'h'; i++)
	{
		Inqueue(&q, i);
	}*/
	//Inqueue(&q, 'i');
	Print(&q);
	Dequeue(&q);

	Destroy(&q);
	return 0;
}