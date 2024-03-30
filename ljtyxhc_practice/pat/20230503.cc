#include <iostream>
 
using namespace std;
typedef long long LL;
const int N=5e6+10;
 
char str[N],ret[N];
int s,cnt,i;
 
int tran(string str,int t){//t进制转十进制
    int ret=0;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])) ret=ret*t+str[i]-'0';
        else ret=ret*t+str[i]-'a'+10;
    }
    return ret;
}
string twostr(char c1,char c2){//16进制转2进制
    string ret="00000000";
    int a=isdigit(c1)?c1-'0':c1-'a'+10,b=isdigit(c2)?c2-'0':c2-'a'+10;//改为数字
    for(int i=3;i>=0&&a;i--){//前四位
        ret[i]=a%2+'0';
        a/=2;
    }
    for(int i=7;i>=4&&b;i--){//后四位
        ret[i]=b%2+'0';
        b/=2;
    }
    return ret;
}
 
int main()
{
    cin>>s;
    for(int i=0;i<(s-1)/8+1;i++) scanf("%s",str+i*16);
 
    for(i=0;i<s*2;i+=2){//引导域
        string ss;ss+=str[i];ss+=str[i+1];
        if(tran(ss,16)<128) break;//最高位为0，退出
    }
 
    for(i+=2;i<s*2;i+=2){
        string ss=twostr(str[i],str[i+1]);
        if(ss[6]=='0'&&ss[7]=='0'){//字面量
            int le=tran(ss.substr(0,6),2),p,ct;//获取字面量长度-1的值
            if(le>=60){//le+1>=61
                int dx=le-59;//存储字面量长度的字节数
                string lee;
                for(p=i+dx*2;p>i;p-=2){//小端序拼接
                    lee+=str[p]; lee+=str[p+1];
                }
                le=tran(lee,16);//获取字面量长度-1的值
                i+=dx*2;
            }
            for(p=i+2,ct=0;ct<le+1;p+=2,ct++){//存储字面量字节
                ret[cnt++]=str[p];
                ret[cnt++]=str[p+1];
            }
            i=p-2;
        }
        else{//回溯引用
            int l,o;
            if(ss[6]=='0'&&ss[7]=='1'){//01形式
                l=tran(ss.substr(3,3),2)+4;
                ss=ss.substr(0,3); ss+=twostr(str[i+2],str[i+3]);
                i+=2;
                o=tran(ss,2);
            }
            else{//10形式
                l=tran(ss.substr(0,6),2)+1;
                ss.clear(); ss+=str[i+4]; ss+=str[i+5]; ss+=str[i+2]; ss+=str[i+3];
                i+=4;
                o=tran(ss,16);
            }
 
            int pcnt=cnt/2;//存一下现在的字节数
            for(int p=2*(pcnt-o),ct=0;ct<l;p+=2,ct++){//从第pcnt-o个字节开始，输出l个字节
                if(o<l&&p==2*pcnt) p=2*(pcnt-o);//如果o<l，且到了末尾，回到起点，反复输出
                ret[cnt++]=ret[p];
                ret[cnt++]=ret[p+1];
            }
        }
    }
 
    for(int i=0;i<cnt;i++){
        if(i&&i%16==0) cout<<endl;
        cout<<ret[i];
    }
    return 0;
}