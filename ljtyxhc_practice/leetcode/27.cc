#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            if (*i == val)
            {
                nums.erase(i);
                i--;
            }
        }
        return nums.size();
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;
    int k = s.removeElement(nums, val);
    cout << k << endl;
    return 0; // 程序正常退出
}