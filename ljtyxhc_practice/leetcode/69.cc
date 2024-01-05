#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = x;
        while (left <= right)
        {
            long mid = (left + right) / 2;
            if (mid * mid > x)
            {
                right = mid - 1;
            }
            else if(mid * mid < x)
            {
                left = mid + 1;
            }
            else
            return mid;
        }
        return right;
    }
};
int main()
{
    Solution s;
    int t = s.mySqrt(20);
    cout << t << endl;
    return 0; // 程序正常退出
}