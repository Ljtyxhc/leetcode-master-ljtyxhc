#include<iostream>
using namespace std;
int main()
{
    long long a,b,n;
    while(cin>>n &&n != 0)
    {
        a = 0;
        while (n--)
        {
            cin>>b;
            a += b;
        }
        cout<<a<<endl;  //输出结果
    }
    return 0;
};