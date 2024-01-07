#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0;
        int n = nums.size();
        int ans = INT_MAX;
        for (; j < n; ++j) 
        {
            sum += nums[j];
            while (sum >= target)
            {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 2,3,1,2,4,3 };
    s.minSubArrayLen(7, nums);
    return 0;//
}