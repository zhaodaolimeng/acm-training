/**
 * 递归计算每个表达式在编译过程的状态
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

map<string,int> g;
string f;
char s[100001];
int n,m;

int eval(int l,int r)
{
    for(int i=r-1,w=0;i>=l;i--)
    {
        w+=s[i]=='(';
        w-=s[i]==')';
        if(w==0 && (s[i]=='+' || s[i]=='-'))
        {
            int L=eval(l,i),R=eval(i+1,r);
            return (L && R && (s[i]!='-' || R>1));
        }
    }
    for(int i=r-1,w=0;i>=l;i--)
    {
        w+=s[i]=='(';
        w-=s[i]==')';
        if(w==0 && (s[i]=='*' || s[i]=='/'))
        {
            int L=eval(l,i),R=eval(i+1,r);
            return (((L>1) && (R>1) && (s[i]!='/' || R>2))?2:0);
        }
    }
    if(s[l]=='(')
        return eval(l+1,r-1)?3:0;
    string u(s+l,s+r);
    return (g.count(u)?g[u]:3);
}

int G()
{
    gets(s);
    m=0;
    for(int i=0;s[i];i++)
        if(s[i]!=' ')
            s[m++]=s[i];
    s[m]=0;
    return eval(0,m);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i;
    scanf("%d ",&n);
    for(i=1;i<=n;i++){
        scanf(" #%*s");
        cin>>f;
        g[f]=G();
    }
    puts(G()?"OK":"Suspicious");
    return 0;
}