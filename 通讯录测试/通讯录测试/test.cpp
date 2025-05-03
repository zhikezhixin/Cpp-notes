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
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.查找联系人 *****" << endl;
    cout << "***** 3.显示联系人 *****" << endl;
    cout << "***** 4.修改联系人 *****" << endl;
    cout << "***** 5.删除联系人 *****" << endl;
    cout << "***** 6.清空通讯录 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}

void InitializeAddressBook(AddressBook* book) {
    book->numContacts = 0;
}

// 修剪字符串函数
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int FindContactIndex(const string& name, AddressBook* book) {
    string trimmedName = trim(name);  // 修剪输入的姓名字符串
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
        cout << "通讯录已满，无法添加新的联系人！" << endl;
        return;
    }

    Contact newContact;
    cout << "请输入姓名：";
    getline(cin, newContact.name);

    if (FindContactIndex(newContact.name, book) != -1) {
        cout << "该联系人已存在！" << endl;
        return;
    }

    cout << "请输入性别：";
    getline(cin, newContact.sex);

    cout << "请输入电话：";
    getline(cin, newContact.number);

    cout << "请输入住址：";
    getline(cin, newContact.address);

    book->people[book->numContacts++] = newContact;
    cout << "添加成功！" << endl;
}

void FindContact(AddressBook* book) {
    cout << "请输入要查找的姓名：";
    string name;
    getline(cin, name);

    int index = FindContactIndex(name, book);
    if (index != -1) {
        cout << "姓名：" << book->people[index].name << "  ";
        cout << "性别：" << book->people[index].sex << "  ";
        cout << "电话：" << book->people[index].number << "  ";
        cout << "住址：" << book->people[index].address << endl;
    }
    else {
        cout << "查无此人！" << endl;
    }
}

void ShowContacts(AddressBook* book) {
    if (book->numContacts == 0) {
        cout << "通讯录为空！" << endl;
    }
    else {
        for (int i = 0; i < book->numContacts; ++i) {
            cout << "姓名：" << book->people[i].name << "  ";
            cout << "性别：" << book->people[i].sex << "  ";
            cout << "电话：" << book->people[i].number << "  ";
            cout << "住址：" << book->people[i].address << endl;
        }
    }
}

void ModifyContact(AddressBook* book) {
    cout << "请输入要修改的联系人姓名：";
    string name;
    getline(cin, name);

    int index = FindContactIndex(name, book);
    if (index != -1) {
        cout << "请输入新的姓名：";
        getline(cin, book->people[index].name);

        cout << "请输入新的性别：";
        getline(cin, book->people[index].sex);

        cout << "请输入新的电话：";
        getline(cin, book->people[index].number);

        cout << "请输入新的住址：";
        getline(cin, book->people[index].address);

        cout << "修改成功！" << endl;
    }
    else {
        cout << "查无此人！" << endl;
    }
}

void DeleteContact(AddressBook* book) {
    cout << "请输入要删除的联系人姓名：";
    string name;
    getline(cin, name);

    int index = FindContactIndex(name, book);
    if (index != -1) {
        for (int i = index; i < book->numContacts - 1; ++i) {
            book->people[i] = book->people[i + 1];
        }
        book->numContacts--;
        cout << "删除成功！" << endl;
    }
    else {
        cout << "查无此人！" << endl;
    }
}

void ClearAddressBook(AddressBook* book) {
    cout << "是否确认清空通讯录？" << endl;
    cout << "     1.确认       " << endl;
    cout << "     0.取消       " << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        InitializeAddressBook(book);
        cout << "通讯录已清空！" << endl;
    }
    else {
        cout << "已取消清空通讯录！" << endl;
    }
}

int main() {
    AddressBook book;
    InitializeAddressBook(&book);

    int choice;
    do {
        Menu();
        cout << "请选择：";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: AddContact(&book); break;
        case 2: FindContact(&book); break;
        case 3: ShowContacts(&book); break;
        case 4: ModifyContact(&book); break;
        case 5: DeleteContact(&book); break;
        case 6: ClearAddressBook(&book); break;
        case 0: cout << "已退出通讯录！" << endl; break;
        default: cout << "选择错误，请重新选择！" << endl; break;
        }
    } while (choice != 0);

    return 0;
}

