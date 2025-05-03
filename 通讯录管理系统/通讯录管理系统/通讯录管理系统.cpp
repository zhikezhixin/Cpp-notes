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
		cout << "请选择：";
		cin >> select;
		cin.ignore();
		switch (select)
		{
		case 1://添加联系人
		{
			AddContacts(&cont);
			break;
		}
		case 2://查找联系人
		{
			FindContact(&cont);
			break;
		}
		case 3://显示联系人
		{
			ShowContact(&cont);
			break;
		}
		case 4://修改联系人
		{
			ModifyContact(&cont);
			break;
		}
		case 5://删除联系人
		{
			DeletContact(&cont);
			break;
		}
		case 6://清空通讯录
		{
			ClearContact(&cont);
			break;
		}
		case 0:
		{
			cout << "已退出通讯录！" << endl;
			break;
		}
		default:
		{
			cout << "选择错误，请重新选择！" << endl;
			break;
		}
		}
	} while (select);

	return 0;
}
