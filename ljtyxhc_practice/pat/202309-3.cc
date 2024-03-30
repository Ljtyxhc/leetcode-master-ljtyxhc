#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
stack<formula>st;//栈S
vector<ll>val;//存储求导时的变量值
struct item
{
	ll coefficient;//系数或常数 
	map<int,int>mp;//一个下标对应一个指数 例如x2的5次方 那么key值为2，value值为5
	item(ll coe,map<int,int>mp):coefficient(coe),mp(mp) {}//结构体构造函数
};//乘积项 
struct formula
{
	vector<item>vec;//规定所有乘积项均用+连接
	formula(vector<item>vec):vec(vec) {}
};//多项式 
ll convert(string str)//字符串转换成数字 
{
	ll num=0;
	for(int i=(str[0]=='-')?1:0;i<str.length();i++){
		num*=10;
		num+=str[i]-'0';
	}
	return (str[0]=='-')?-1*num:num; 
}
item item_mul(item A,item B)//乘积项乘法函数 
{
	ll coefficient_c=A.coefficient*B.coefficient;
	map<int,int>mp_c;
	map<int,int>::iterator it;
	for(it=A.mp.begin();it!=A.mp.end();it++){
		mp_c[it->first]=A.mp[it->first]+B.mp[it->first];
		B.mp.erase(it->first);
	}
	for(it=B.mp.begin();it!=B.mp.end();it++){
		mp_c[it->first]=B.mp[it->first];
	}
	return item(coefficient_c,mp_c);
}
formula formula_mul(formula A,formula B)//多项式乘法 
{
	vector<item>vec;
	for(int i=0;i<A.vec.size();i++){
		for(int j=0;j<B.vec.size();j++){
			vec.push_back(item_mul(A.vec[i],B.vec[j]));
		}
	}
	return formula(vec);
}
formula formula_add(formula A,formula B)//多项式加法 
{
	for(int i=0;i<B.vec.size();i++){
		A.vec.push_back(B.vec[i]);
	}
	return A;
}
formula formula_sub(formula A,formula B)//多项式减法 
{
	for(int i=0;i<A.vec.size();i++){
		A.vec[i].coefficient*=-1;
	}
	return formula_add(B,A);
}
ll function(formula A,int goal)//求导函数 对最终的formula求导 
{
	ll sum=0,mul;
	for(int i=0;i<A.vec.size();i++){
		item now=A.vec[i];
		mul=1;
		if(now.mp.find(goal)!=now.mp.end()){//此乘积项含有要求导的变量才拥有计算价值
			mul=(now.coefficient*now.mp[goal])%mod;
			now.mp[goal]--;
			for(map<int,int>::iterator it=now.mp.begin();it!=now.mp.end();it++){
				for(int k=0;k<it->second;k++){
					mul=(mul*val[it->first])%mod;
				}
			}
			sum=(sum+mul)%mod;
		}
	}
	return sum;
}
int main()
{
	int n,m;
	cin>>n>>m;//求解函数中所含自变量的个数和要求解的偏导数的个数
    getchar();//很重要，如果缺少这行代码会导致str为空
	string str,temp;
	getline(cin,str);
	stringstream sin(str);
	while(sin>>temp){
		if(temp=="+" || temp=="-" || temp=="*"){//运算符
			formula A=st.top(); st.pop();//从栈中依次弹出两个formula
			formula B=st.top(); st.pop(); 
			if(temp=="*"){
				st.push(formula_mul(B,A));
			}else if(temp=="+"){
				st.push(formula_add(B,A));
			}else{
				st.push(formula_sub(A,B));//A B的顺序很重要 
			}
		}else{
			map<int,int>mp;//下标 指数 
			vector<item>vec;
			if(temp[0]=='x'){//自变量 
				mp[convert(temp.substr(1,temp.length()-1))]=1;
				vec.push_back(item(1,mp));//把乘积项包装成多项式 
			}else{//常数
				vec.push_back(item(convert(temp),mp));//把乘积项包装成多项式 
			}
			st.push(formula(vec));
		}
	}
	for(int i=0;i<m;i++){
		ll value;
		for(int j=0;j<n+1;j++){
			cin>>value;
			val.push_back(value);
		}
		ll ans=function(st.top(),val[0]);
		cout<<((ans<0)?ans+mod:ans)<<endl;//当计算整数n对M的模时，若n为负数,需要注意将结果调整至区间[0,M)内
		val.clear();
	}
	
	return 0;
}
