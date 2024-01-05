#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {     
        auto begin = nums.begin();
        auto end = nums.end() - 1;
        vector<int> ans;
        while (begin != end)
        {
            if((*begin)*(*begin) < (*end)*(*end))
            {
                ans.push_back((*end)*(*end));
                end--;
            }
            else
            {
                ans.push_back((*begin)*(*begin));
                begin++;
            }
        }
        ans.push_back((*begin)*(*begin));
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { -4,-1,0,2,3,4,6 };
    int val = 2;
    vector<int> k = s.sortedSquares(nums);
    cout << k.size() << endl;
    return 0; // 程序正常退出
}