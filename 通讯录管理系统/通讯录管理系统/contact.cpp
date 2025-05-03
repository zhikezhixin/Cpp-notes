#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void Menu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.查找联系人 *****" << endl;
	cout << "***** 3.显示联系人 *****" << endl;
	cout << "***** 4.修改联系人 *****" << endl;
	cout << "***** 5.删除联系人 *****" << endl;
	cout << "***** 6.清空通讯录 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}

void InitialContact(struct adressbook* cont)
{
    cont->num = 0;
    memset(cont->people, 0, sizeof(cont->people));
}

int ResearchPerson(string name, struct adressbook* cont)
{
    for (int i = 0; i < cont->num; i++)
    {
        if (name == cont->people[i].name)
        {
            return i;
        }
    }
    return -1;
}

void AddContacts(struct adressbook* cont)
{
    if (cont->num == max)
    {
        cout << "通讯录已满,无法添加！" << endl;
        return;
    }
    else
    {
        cout << "请输入姓名：";
        getline(cin, cont->people[cont->num].name);

        if (ResearchPerson(cont->people[cont->num].name, cont) != -1)
        {
            cout << "该联系人已存在！" << endl;
            return;
        }

        cout << "请输入性别：";
        getline(cin, cont->people[cont->num].sex);

        cout << "请输入电话：";
        getline(cin, cont->people[cont->num].number);

        cout << "请输入住址：";
        getline(cin, cont->people[cont->num].adress);

        cout << "添加成功！" << endl;
        cont->num++;
    }
    system("pause");
    system("cls");
}



void FindContact(struct adressbook* cont)
{
    cout << "请输入要查找的姓名：";
    string name;
    getline(cin, name);

    int index = ResearchPerson(name, cont);
    if (index != -1)
    {
        cout << "姓名：" << cont->people[index].name << "  ";
        cout << "性别：" << cont->people[index].sex << "  ";
        cout << "电话：" << cont->people[index].number << "  ";
        cout << "住址：" << cont->people[index].adress << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}

void ShowContact(struct adressbook* cont)
{
    if (cont->num == 0)
    {
        cout << "通讯录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < cont->num; i++)
        {
            cout << "姓名：" << cont->people[i].name   << "  ";
            cout << "性别：" << cont->people[i].sex    << "  ";
            cout << "电话：" << cont->people[i].number << "  ";
            cout << "住址：" << cont->people[i].adress << endl;
        }
    }
    system("pause");
    system("cls");
}
 
void ModifyContact(struct adressbook* cont)
{
    cout << "请输入要修改的联系人姓名：";
    string name;
    getline(cin, name);

    int index = ResearchPerson(name, cont);
    if (index != -1)
    {
        cout << " 请输入新的姓名：";
        getline(cin, cont->people[index].name);

        cout << "请输入新的性别：" ;
        getline(cin, cont->people[index].sex);

        cout << "请输入新的电话：";
        getline(cin, cont->people[index].number);

        cout << "请输入新的住址：" ;
        getline(cin, cont->people[index].adress);

    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}

void DeletContact(struct adressbook* cont)
{
    cout << "请输入要删除的联系人姓名：";
    string name;
    getline(cin,name);



    int index = ResearchPerson(name, cont);
    if (index != -1)
    {
        for (int i = index; i < cont->num - 1; i++)
        {
            cont->people[i] = cont->people[i + 1];
        }
        memset(&(cont->people[cont->num - 1]), 0, sizeof(cont->people[cont->num - 1]));
        cont->num--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}

void ClearContact(struct adressbook* cont)
{
    cout << "是否确认清空通讯录" << endl;
    cout << "     1.确认       " << endl;
    cout << "     0.取消       " << endl;
    int  tem = 0;
    cin >> tem;
    if (tem == 1)
    {
        InitialContact(cont);
        cout << "通讯录已清空！" << endl;
    }
    else
    {
        cout << "已取消清空通讯录！" << endl;
    }
    system("pause");
    system("cls");
}
