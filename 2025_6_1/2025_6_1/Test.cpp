#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 //给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr||head->next == nullptr)
            return head;
        ListNode* pre = head;
        ListNode* mid = pre->next;
        ListNode* tail = mid->next;
        pre->next = nullptr;
        while (mid)
        {
            mid->next = pre;
            pre = mid;
            mid = tail;
            if (tail)
                tail = tail->next;
        }
        return pre;
    }
};
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 
//逆序 的方式存储的，并且每个节点只能存储 一位 数字。请你将两个数相加，
//并以相同形式返回一个表示和的链表。你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur = dummy_head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy_head->next;
    }
};

//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
// 它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* pre = head;
        ListNode* mid = pre->next;
        ListNode* tail = mid->next;
        pre->next = nullptr;
        while (mid)
        {
            mid->next = pre;
            pre = mid;
            mid = tail;
            if (tail)
                tail = tail->next;
        }
        return pre;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur = dummy_head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
       
        return reverse(dummy_head->next);
    }
};

//给定一个整数数组nums和一个整数目标值target,请你在该数组中找出和为目标值target
// 的那两个整数，并返回它们的数组下标。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hash_table;
        for (int i = 0;i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hash_table.count(complement))
            {
                return { hash_table[complement] ,i };
            }
            hash_table[nums[i]] = i;
        }
        return {};
    }
};
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
class Solution {
public:
    int ctoi(const char ch)
    {
        return ch - '0';
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> s;
        unordered_map<string, vector<string>> hash_map;
        for (const auto& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            hash_map[key].push_back(s);
        }
        for (auto& [_,value] : hash_map)
        {
            s.push_back(move(value));
        }
        return s;
    }
};
*/

class MyString {
private:
    char* data;      // 指向字符串数据的指针
    size_t length;   // 字符串长度

public:
    // 普通构造函数
    MyString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];  // 分配内存
        strcpy(data, str);            // 复制数据
        cout << "构造了字符串: " << data << endl;
    }

    // 拷贝构造函数（传统方式）
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];  // 分配新内存
        strcpy(data, other.data);     // 复制所有数据
        cout << "拷贝构造: " << data << endl;
    }

    // 移动构造函数（C++11 新特性）
    MyString(MyString&& other) noexcept {
        data = other.data;       // 直接"拿走"指针
        length = other.length;   // 拿走长度

        other.data = nullptr;    // 清空源对象
        other.length = 0;        // 避免析构时重复释放

        cout << "移动构造: " << data << endl;
    }

    // 析构函数
    ~MyString() {
        if (data) {
            cout << "销毁: " << data << endl;
            delete[] data;
        }
    }

    // 获取字符串内容
    const char* c_str() const {
        return data ? data : "";
    }
};
int main() {
    MyString a("Hello World");  // 创建字符串 a

    // 不使用 move（发生拷贝）
    MyString b = a;  // 调用拷贝构造函数
    cout << "a: " << a.c_str() << endl;  // a 仍然有效
    cout << "b: " << b.c_str() << endl;  // b 也有效

    // 使用 move（发生移动）
    MyString c = move(a);  // 调用移动构造函数
    cout << "a: " << a.c_str() << endl;  // a 变为空
    cout << "c: " << c.c_str() << endl;  // c 获得了 a 的资源

    return 0;
}