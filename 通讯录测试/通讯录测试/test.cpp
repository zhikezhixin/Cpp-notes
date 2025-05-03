#include <iostream>
#include <string>

#define MAX_CONTACTS 1000

using namespace std;

struct Contact {
    string name;
    string sex;
    string number;
    string address;
};

struct AddressBook {
    Contact people[MAX_CONTACTS];
    int numContacts;
};

void Menu() {
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

void InitializeAddressBook(AddressBook* book) {
    book->numContacts = 0;
}

// �޼��ַ�������
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int FindContactIndex(const string& name, AddressBook* book) {
    string trimmedName = trim(name);  // �޼�����������ַ���
    for (int i = 0; i < book->numContacts; ++i) {
        string trimmedCurrentName = trim(book->people[i].name);
        if (trimmedCurrentName == trimmedName) {
            return i;
        }
    }
    return -1;
}

void AddContact(AddressBook* book) {
    if (book->numContacts == MAX_CONTACTS) {
        cout << "ͨѶ¼�������޷�����µ���ϵ�ˣ�" << endl;
        return;
    }

    Contact newContact;
    cout << "������������";
    getline(cin, newContact.name);

    if (FindContactIndex(newContact.name, book) != -1) {
        cout << "����ϵ���Ѵ��ڣ�" << endl;
        return;
    }

    cout << "�������Ա�";
    getline(cin, newContact.sex);

    cout << "������绰��";
    getline(cin, newContact.number);

    cout << "������סַ��";
    getline(cin, newContact.address);

    book->people[book->numContacts++] = newContact;
    cout << "��ӳɹ���" << endl;
}

void FindContact(AddressBook* book) {
    cout << "������Ҫ���ҵ�������";
    string name;
    getline(cin, name);

    int index = FindContactIndex(name, book);
    if (index != -1) {
        cout << "������" << book->people[index].name << "  ";
        cout << "�Ա�" << book->people[index].sex << "  ";
        cout << "�绰��" << book->people[index].number << "  ";
        cout << "סַ��" << book->people[index].address << endl;
    }
    else {
        cout << "���޴��ˣ�" << endl;
    }
}

void ShowContacts(AddressBook* book) {
    if (book->numContacts == 0) {
        cout << "ͨѶ¼Ϊ�գ�" << endl;
    }
    else {
        for (int i = 0; i < book->numContacts; ++i) {
            cout << "������" << book->people[i].name << "  ";
            cout << "�Ա�" << book->people[i].sex << "  ";
            cout << "�绰��" << book->people[i].number << "  ";
            cout << "סַ��" << book->people[i].address << endl;
        }
    }
}

void ModifyContact(AddressBook* book) {
    cout << "������Ҫ�޸ĵ���ϵ��������";
    string name;
    getline(cin, name);

    int index = FindContactIndex(name, book);
    if (index != -1) {
        cout << "�������µ�������";
        getline(cin, book->people[index].name);

        cout << "�������µ��Ա�";
        getline(cin, book->people[index].sex);

        cout << "�������µĵ绰��";
        getline(cin, book->people[index].number);

        cout << "�������µ�סַ��";
        getline(cin, book->people[index].address);

        cout << "�޸ĳɹ���" << endl;
    }
    else {
        cout << "���޴��ˣ�" << endl;
    }
}

void DeleteContact(AddressBook* book) {
    cout << "������Ҫɾ������ϵ��������";
    string name;
    getline(cin, name);

    int index = FindContactIndex(name, book);
    if (index != -1) {
        for (int i = index; i < book->numContacts - 1; ++i) {
            book->people[i] = book->people[i + 1];
        }
        book->numContacts--;
        cout << "ɾ���ɹ���" << endl;
    }
    else {
        cout << "���޴��ˣ�" << endl;
    }
}

void ClearAddressBook(AddressBook* book) {
    cout << "�Ƿ�ȷ�����ͨѶ¼��" << endl;
    cout << "     1.ȷ��       " << endl;
    cout << "     0.ȡ��       " << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        InitializeAddressBook(book);
        cout << "ͨѶ¼����գ�" << endl;
    }
    else {
        cout << "��ȡ�����ͨѶ¼��" << endl;
    }
}

int main() {
    AddressBook book;
    InitializeAddressBook(&book);

    int choice;
    do {
        Menu();
        cout << "��ѡ��";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: AddContact(&book); break;
        case 2: FindContact(&book); break;
        case 3: ShowContacts(&book); break;
        case 4: ModifyContact(&book); break;
        case 5: DeleteContact(&book); break;
        case 6: ClearAddressBook(&book); break;
        case 0: cout << "���˳�ͨѶ¼��" << endl; break;
        default: cout << "ѡ�����������ѡ��" << endl; break;
        }
    } while (choice != 0);

    return 0;
}

