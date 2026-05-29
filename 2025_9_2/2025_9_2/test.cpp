#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> v;
        int arr1[128] = { 0 };
        for (auto x : p) arr1[x]++;
        int len_p = p.size(), len_s = s.size();;
        for (int left = 0, right = 0, count = 0; right < len_s; right++)
        {
            int arr2[128] = { 0 };
            char in = s[right];
            arr2[in]++;

             if (arr2[in] <= arr1[in]) count++;
            if (right - left + 1 > len_p)
            {
                char out = s[left];
                if (arr2[out] <= arr1[out]) count--;
                arr2[out]--;
                left++;
            }

            if (count == len_p) v.push_back(left);
        }
        return v;
    }
};

void test()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution().findAnagrams(s, p);
}

int main()
{
    test();
    return 0;
}