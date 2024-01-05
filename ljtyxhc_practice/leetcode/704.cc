#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if(target > nums[mid])
            left  = mid + 1;
            else
            right = mid - 1;
        }
        return -1;
    }
};

int main() 
{
    Solution Solution_; // 创建 Solution 类的实例
    vector<int> nums= {-1,0,5};
    int t = Solution_.search(nums, -1);
    cout << t << endl;
}