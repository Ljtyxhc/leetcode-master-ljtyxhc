#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    void get_ans(TreeNode* now, vector<int> & ans)
    {
        if(now->left != nullptr)
        get_ans(now->left, ans);
        ans.push_back(now->val);
        if(now->right != nullptr)
        get_ans(now->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root != nullptr)
        get_ans(root,ans);
        return ans;
    }

    vector<int> inorderTraversal_(TreeNode* root){
        stack<TreeNode*> temp_stack;
        TreeNode* temp = root;
        vector<int> ans;
        while (!temp_stack.empty() || temp)
        {
            while (temp != nullptr)
            {
                temp_stack.push(temp);
                temp = temp->left;
            }
            temp = temp_stack.top();
            ans.push_back(temp->val);
            temp_stack.pop();
            temp = temp->right;
        }
        return ans;
    }
};
int main()
{
    return 0;
}