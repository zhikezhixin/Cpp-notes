#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

int main()
{
	int select = 0;
	struct adressbook cont;
	InitialContact(&cont);
	do
	{
		Menu();
		cout << "��ѡ��";
		cin >> select;
		cin.ignore();
		switch (select)
		{
		case 1://�����ϵ��
		{
			AddContacts(&cont);
			break;
		}
		case 2://������ϵ��
		{
			FindContact(&cont);
			break;
		}
		case 3://��ʾ��ϵ��
		{
			ShowContact(&cont);
			break;
		}
		case 4://�޸���ϵ��
		{
			ModifyContact(&cont);
			break;
		}
		case 5://ɾ����ϵ��
		{
			DeletContact(&cont);
			break;
		}
		case 6://���ͨѶ¼
		{
			ClearContact(&cont);
			break;
		}
		case 0:
		{
			cout << "���˳�ͨѶ¼��" << endl;
			break;
		}
		default:
		{
			cout << "ѡ�����������ѡ��" << endl;
			break;
		}
		}
	} while (select);

	return 0;
}
