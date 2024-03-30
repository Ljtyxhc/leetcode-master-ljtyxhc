#include<iostream>
#include<set>
using namespace std;

int find_val(pair<int,int> val_l[500], int num, int len)
{
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (val_l[mid].first == num) 
        {
            return val_l[mid].second;  // 找到了值，返回索引
        } 
        else if (val_l[mid].first < num) 
        {
            l = mid + 1;  // 如果在右边，更新左边界
        } 
        else 
        {
            r = mid - 1;  // 如果在左边，更新右边界
        }
    }

    return -1;  // 未找到值，返回-1
}
bool count_ok(pair<int,int> val_l[500], set<int> val_n,
int num, int value, int flag, int num_v)
{
    //flag为0表达肯定判断，为1表达否定判断; num_v为属性数量
    set<int>::iterator it;
    if((it=val_n.find(num)) != val_n.end())//存在
    {
        if(!flag)
        {
            int temp_v_l = find_val(val_l,num,num_v);
            if(value == temp_v_l)
            return true;
            else
            return false;
        }
        else
        {
            int temp_v_l = find_val(val_l,num,num_v);
            if(value == -temp_v_l)
            return false;
            else
            return true;
        }
    }
    else
    return false;
}
struct user
{
    int DN;//用户编号
    int num_val = 0;//属性个数
    pair<int,int> val_list[500];//属性编号和值
    set<int> val_num;//属性编号集合
    int ptr_val = 0;//位置指针
    void init(int DN_, int num_v_)
    {
        DN = DN_;
        num_val = num_v_;
    }
    void set_val(int num, int val)
    {
        val_list[ptr_val++] = make_pair(num,val);
        val_num.insert(num);
    }
};
struct val_node
{
    int num = -1;
    int val = -1;//是为正值，否为负值
    void init(int n_, int v_){num = n_; val = v_;}
    val_node(int n_, int v_){num = n_; val = v_;}
};
int n_u_num = 0, m_list_num = 0;
user ALL_user[2500];
string command[500];
void make_ans(int ans_num);
pair<val_node,val_node> solve_sentence_(string temp_sen);
val_node solve_sentence(string temp_sen);
int main()
{

    cin>>n_u_num;
    for (int i = 0; i < n_u_num; i++)
    {
        int t_DN,t_num_val;
        cin>> t_DN >>t_num_val; 
        ALL_user[i].init(t_DN,t_num_val);
        for (int j = 0; j < t_num_val; j++)
        {
            int t_num, t_val;
            cin>>t_num>>t_val;
            ALL_user[i].set_val(t_num,t_val);
        }   
    }
    cin>>m_list_num;
    for (int i = 0; i < m_list_num; i++)
    {
        cin>>command[i];
    }
    make_ans(m_list_num);
    return 0;
}
void make_ans(int ans_num)
{
    for (int i = 0; i < ans_num; i++)
    {
        set<int> ans;
        if(command[i][0] == '|')
        {
            pair<val_node,val_node> or_pair = solve_sentence_(command[i]);
            for (int i = 0; i < n_u_num; i++)
            {
                if(count_ok(ALL_user[i].val_list,ALL_user[i].val_num,
                or_pair.first.num, or_pair.first.val,or_pair.first.val<0 ? 1 : 0,
                ALL_user[i].num_val)||count_ok(ALL_user[i].val_list,ALL_user[i].val_num,
                or_pair.second.num, or_pair.second.val,or_pair.second.val<0 ? 1 : 0,
                ALL_user[i].num_val))
                ans.insert(ALL_user[i].DN);
            }
            
        }
        else if (command[i][0] == '&')
        {
            pair<val_node,val_node> and_pair = solve_sentence_(command[i]);
            for (int i = 0; i < n_u_num; i++)
            {
                if(count_ok(ALL_user[i].val_list,ALL_user[i].val_num,
                and_pair.first.num, and_pair.first.val,and_pair.first.val<0 ? 1 : 0,
                ALL_user[i].num_val) && count_ok(ALL_user[i].val_list,ALL_user[i].val_num,
                and_pair.second.num, and_pair.second.val,and_pair.second.val<0 ? 1 : 0,
                ALL_user[i].num_val))
                ans.insert(ALL_user[i].DN);
            }
        }
        else
        {
            val_node node = solve_sentence(command[i]);
            for (int i = 0; i < n_u_num; i++)
            {
                if(count_ok(ALL_user[i].val_list,ALL_user[i].val_num,node.num,node.val,
                node.val < 0 ? 1 : 0,ALL_user[i].num_val))
                ans.insert(ALL_user[i].DN);
            }
        }
        for(auto i : ans)
        cout<<i<<" ";
        cout<<endl;
    }
}
val_node solve_sentence(string temp_sen)
{

    if(temp_sen[1] == ':')
    return val_node(int(temp_sen[0]) - 48, int(temp_sen[2]) - 48);
    else
    return val_node(int(temp_sen[0]) - 48, -int(temp_sen[2]) + 48);
}
pair<val_node,val_node> solve_sentence_(string temp_sen)
{
    val_node t_node1 = (temp_sen[3] == ':') ? 
    val_node(int(temp_sen[2]) - 48, int(temp_sen[4] - 48)) :
    val_node(int(temp_sen[2]) - 48, -(int(temp_sen[4] - 48)));
    val_node t_node2 = (temp_sen[8] == ':') ? 
    val_node(int(temp_sen[7]) - 48, int(temp_sen[9]) - 48) :
    val_node(int(temp_sen[7]) - 48, -(int(temp_sen[9]) - 48));
    return make_pair(t_node1, t_node2);
}

/*

3
3 2 1 1 8 2
5 2 1 7 6 4
7 1 8 1
5
1:1
|(1:7)(8:1)
6~3
|(8~1)(1~1)
&(1:7)(6~4)

*/