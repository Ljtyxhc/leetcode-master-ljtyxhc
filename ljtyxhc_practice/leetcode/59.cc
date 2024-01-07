#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        if(n == 1)
        {
            cout<<"[[1]]";
            ans.push_back({1});
            return ans;
        }
        int s = n;
        int loc[n][n];
        if(n%2 != 0)
            loc[n/2][n/2] = n*n;
        int i = 0, j = 0;
        int num = 0,ji = 1;
        while (n != 0)
        {
            
            for ( j = num; j < n - 1; j++)
            {
                loc[i][j] = ji++;
            }
            for ( i = num; i < n-1; i++)
            {
                loc[i][j] = ji++;
            }
            for ( j = n - 1; j > num; j--)
            {
                loc[i][j] = ji++;
            }
            for ( i = n - 1; i > num; i--)
            {
                loc[i][j] = ji++;
            }
            n --;
            num++;
            i = j = num;
        }
        vector<int> temp;
        cout<<"[[";
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                temp.push_back(loc[i][j]);
                cout<<loc[i][j];
                if(j != s-1)
                    cout<<",";
            }
            ans.push_back(temp);
            temp.erase(temp.begin(),temp.end());
            if(i!=s-1)
            cout<<"],[";
            else
            cout<<"]";
        }
        cout<<"]";
        return ans;
    }
};
int main()
{
    Solution s;
    s.generateMatrix(3);
    return 0;
}