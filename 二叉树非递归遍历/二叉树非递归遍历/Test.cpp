#include <iostream>  
#include <vector>  
#include <stack>  
using namespace std;
// 定义 TreeNode 结构体  
struct TreeNode  
{  
   int val;  
   TreeNode* left;  
   TreeNode* right;  
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
};  

class Solution  
{  
public:  
   // 前序遍历  
   vector<int> preorderTraversal(TreeNode* root)  
   {  
       vector<int> ret;
       stack<TreeNode*> st;
       TreeNode* cur = root;
       while (cur || !st.empty())
       {
           //节点不为空，不断向左寻找左子树入栈
           while (cur)
           {
               ret.push_back(cur->val);
               st.push(cur);
               cur = cur->left;
           }
           //出栈顶，寻找其右子树
           TreeNode* top = st.top();
           st.pop();
           cur = top->right;
       }

       return ret;  
   }  

   // 中序遍历
   vector<int> inorderTraversal(TreeNode* root)
   {
       vector<int> ret;
       stack<TreeNode*> s;
       TreeNode* cur = root;
       while (cur || !s.empty())
       {
           //左路节点入栈
           while (cur)
           {
               s.push(cur);
               cur = cur->left;
           }
           //取出栈中节点，访问节点的右子树
           cur = s.top();
           s.pop();
           ret.push_back(cur->val);
           cur = cur->right;
       }
       return ret;
   }

   // 后序遍历
   vector<int> postorderTraversal(TreeNode* root)
   {
       vector<int> ret;
       if (!root) return ret;
       stack<TreeNode*> s;
       TreeNode* prev = nullptr;
       TreeNode* curr = root;
       while (curr || !s.empty())
       {
           while (curr)
           {
               s.push(curr);
               curr = curr->left;
           }
           curr = s.top();
           if (!curr->right || curr->right == prev)
           {
               ret.push_back(curr->val);
               s.pop();
               prev = curr;
               curr = nullptr;
           }
           else
           {
               curr = curr->right;
           }
       }
       return ret;
   }
};