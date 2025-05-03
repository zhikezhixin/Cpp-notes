#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void Menu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.������ϵ�� *****" << endl;
	cout << "***** 3.��ʾ��ϵ�� *****" << endl;
	cout << "***** 4.�޸���ϵ�� *****" << endl;
	cout << "***** 5.ɾ����ϵ�� *****" << endl;
	cout << "***** 6.���ͨѶ¼ *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
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
        cout << "ͨѶ¼����,�޷���ӣ�" << endl;
        return;
    }
    else
    {
        cout << "������������";
        getline(cin, cont->people[cont->num].name);

        if (ResearchPerson(cont->people[cont->num].name, cont) != -1)
        {
            cout << "����ϵ���Ѵ��ڣ�" << endl;
            return;
        }

        cout << "�������Ա�";
        getline(cin, cont->people[cont->num].sex);

        cout << "������绰��";
        getline(cin, cont->people[cont->num].number);

        cout << "������סַ��";
        getline(cin, cont->people[cont->num].adress);

        cout << "��ӳɹ���" << endl;
        cont->num++;
    }
    system("pause");
    system("cls");
}



void FindContact(struct adressbook* cont)
{
    cout << "������Ҫ���ҵ�������";
    string name;
    getline(cin, name);

    int index = ResearchPerson(name, cont);
    if (index != -1)
    {
        cout << "������" << cont->people[index].name << "  ";
        cout << "�Ա�" << cont->people[index].sex << "  ";
        cout << "�绰��" << cont->people[index].number << "  ";
        cout << "סַ��" << cont->people[index].adress << endl;
    }
    else
    {
        cout << "���޴��ˣ�" << endl;
    }
    system("pause");
    system("cls");
}

void ShowContact(struct adressbook* cont)
{
    if (cont->num == 0)
    {
        cout << "ͨѶ¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < cont->num; i++)
        {
            cout << "������" << cont->people[i].name   << "  ";
            cout << "�Ա�" << cont->people[i].sex    << "  ";
            cout << "�绰��" << cont->people[i].number << "  ";
            cout << "סַ��" << cont->people[i].adress << endl;
        }
    }
    system("pause");
    system("cls");
}
 
void ModifyContact(struct adressbook* cont)
{
    cout << "������Ҫ�޸ĵ���ϵ��������";
    string name;
    getline(cin, name);

    int index = ResearchPerson(name, cont);
    if (index != -1)
    {
        cout << " �������µ�������";
        getline(cin, cont->people[index].name);

        cout << "�������µ��Ա�" ;
        getline(cin, cont->people[index].sex);

        cout << "�������µĵ绰��";
        getline(cin, cont->people[index].number);

        cout << "�������µ�סַ��" ;
        getline(cin, cont->people[index].adress);

    }
    else
    {
        cout << "���޴��ˣ�" << endl;
    }
    system("pause");
    system("cls");
}

void DeletContact(struct adressbook* cont)
{
    cout << "������Ҫɾ������ϵ��������";
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
        cout << "ɾ���ɹ���" << endl;
    }
    else
    {
        cout << "���޴��ˣ�" << endl;
    }
    system("pause");
    system("cls");
}

void ClearContact(struct adressbook* cont)
{
    cout << "�Ƿ�ȷ�����ͨѶ¼" << endl;
    cout << "     1.ȷ��       " << endl;
    cout << "     0.ȡ��       " << endl;
    int  tem = 0;
    cin >> tem;
    if (tem == 1)
    {
        InitialContact(cont);
        cout << "ͨѶ¼����գ�" << endl;
    }
    else
    {
        cout << "��ȡ�����ͨѶ¼��" << endl;
    }
    system("pause");
    system("cls");
}
