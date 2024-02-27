#include<vector>
#include<iostream>
#include<queue>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> now_level;
        if(root!=nullptr)
        now_level.push(root);
        vector<vector<int>> ans;
        while (!now_level.empty())
        {
            int size = now_level.size();
            vector<int> temp_ans;
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = now_level.front();
                temp_ans.push_back(temp->val);
                now_level.pop();
                if(temp->left)
                now_level.push(temp->left);
                if (temp->right)
                now_level.push(temp->right);
            }
            ans.push_back(temp_ans);
            temp_ans.clear();   
        }
        return ans;
    }
};