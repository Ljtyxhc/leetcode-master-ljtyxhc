#include<bits/stdc++.h>
using namespace std;
void PrintVector(vector<int> nums);            //可以用于调用打印一维整形数组
void PrintMatrix(vector<vector<int>> matrix);  //可以用于打印二维整形数组
//在这里放入Solution类
//类开始
 
//类结束
int main(){
    //可以用于存放输入的样例
    vector<int> nums={};
    vector<int> nums1={};
    vector<int> ansnums={};
    vector<vector<int>> matrix={ {1,2},
                                 {3,4},
                                 {5,6}, };
    vector<vector<int>> matrix1={};
    vector<vector<int>> ansmatrix;
    //Solution mysolution;                        //定义一个类的对象
    //根据需求自己编辑输出内容
 
    return 0;
}
//其他函数实现
void PrintVector(vector<int> nums){
    int size=nums.size();
    for(int i=0;i<size;i++){
        if(i) putchar(' ');
        cout<<nums[i];
    }
    putchar('\n');
    return;
}
void PrintMatrix(vector<vector<int>> matrix){
    int row=0,col=0;
    row=matrix.size();
    if(row) col=matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j) putchar(' ');
            cout<<matrix[i][j];
        }
        putchar('\n');
    }
}
