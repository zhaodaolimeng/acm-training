/*
Beads
对于一个长度为n的二进制序列，认为逆序序列、取反序列的值与原序列的类别号相同
类别号为同类别最小二进制序列的值，求第k小的类别号
http://codeforces.com/contest/8/submission/20497484
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,s[52];
ll f[52][2][2],k;

// 状态f[x][p][q]指已经确认至前x位和后x位
// p为前x位和后x位的逆序是否相等，q为前x位和后x位的逆序取反是否相等
ll F(int x,int p,int q) {
    ll &t=f[x][p][q];
    if(t!=-1) return t;
    t=0;
    if(x*2>=n) return t=1;  // 中轴

    for(int i=0;i<2;i++)
        if(s[x]<0||s[x]==i)
            for(int j=0;j<2;j++)
                if(s[n-1-x]<0||s[n-1-x]==j)
                    if((i==j||x*2+1!=n)&&(p||i<=j)&&(q||!i||!j))
                        t+=F(x+1,p||i<j,q||!i&&!j);
    return t;
}

int main() {
    cin>>n>>k,k++;
    memset(f,-1,sizeof(f));
    memset(s,-1,sizeof(s));
    if(F(0,0,0)<k){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=0;i<n;i++){
        s[i]=0;
        memset(f,-1,sizeof(f));
        if(F(0,0,0)<k){
            s[i]=1;
            k-=F(0,0,0);
            // 从前向后计算每个二进制位为1时的类别数
            // 此时前缀s已经固定
        }   
        cout<<s[i]<<endl;

        cout<<"-----"<<endl;
        cout<<k<<endl;
        for(int ii=0;ii<2;ii++){
            for(int jj=0;jj<2;jj++){
                for(int kk=0;kk<5;kk++) cout<<f[kk][ii][jj]<<"\t";
                cout<<endl;
            }
        }
    }
    
    return 0;
}
