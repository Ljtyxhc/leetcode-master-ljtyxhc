#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {     
        int size = nums.size() - 1;
        vector<int> ans(nums.size());
        int left = 0, right = size;
        for (int n = 0; n <= size; n++)
        {
            if(nums[left] * nums[left] < nums[right] * nums[right])
            {
                ans[size - n] = nums[right] * nums[right];
                right--;
            }
            else
            {
                ans[size - n] = nums[left] * nums[left];
                left++;
            }
        }
        
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