#include <bits/stdc++.h>
using namespace std;
using db_t = map<int, map<int, int> >; // u:用户, a:属性
db_t db; // 数据库，{uid: {attrib_id : value} }
set<int> eval_base() { // 基础表达式求值
int aid, x;
char op;
cin >> aid >> op >> x;
set<int> usr;
for(auto& m : db) 
{
    const int DN = m.first;
    for(auto& a : m.second) 
    {if(a.first == aid) 
    { // 存在目标属性
    if((op == ':' && a.second == x) ||(op == '~' && a.second != x)) 
    {
        usr.insert(DN);
        }
        break; // 这个用户不用再检查其他属性
        }}}
        return usr;
}
set<int> eval_expr() 
{ // 表达式求值
set<int> usr;
char c;
if(!(cin >> c)) 
{// 
EOF} 
else if(isdigit(c)) 
{ // 
baseexprcin.unget(); // 回退字符
cusr = eval_base();
} else {assert(false); // 未实现}return usr;
}void print(const set<int>& usr) {bool first = true;for(auto DN : usr) {if(first) {first = false;} else {cout << ' ';}cout << DN;}cout << '\n';
}
int main()
{
    int n, m;
    cin >> n;
    for(int DN, ak; n > 0 && cin >> DN >> ak; --n) 
    {
        map<int, int>& attribs = db[DN];
        for(int aid, x; ak > 0 && cin >> aid >> x; --ak) 
        {
            attribs[aid] = x;
            }
            }
            cin >> m >> ws;
            for(int i = 0; i < m; ++i)
             {print(eval_expr());
             }
}