/*
如果一个字符串回文被二分N次之后变成非回文，则称该字符串的回文度数为N，本题要找到给定字符串所有前缀的回文度数。

方法1：
https://www.cnblogs.com/zmin/p/7847410.html
一种可行的方式是使用manacher算法返回的回文半径数组，计算每个前缀中点的回文半径和回文度数
manacher算法可以O(n)的时间开销计算给定字符串所有位置的回文半径r
manacher原理在于，在计算位置i+k的回文半径r[i+k]时，可以利用i+k关于i的对称位置i-k的回文半径r[i-k]：
如果r[i]>=r[i-k]+k，则r[i+k]=r[i-k]
如果r[i]<r[i-k]+k，则r[i+k]=r[i]-k
计算过程为从左向右扫描，同时维护id、right两个指针，其中right=id+r[id]。
设id的下一个位置为i，利用i与id*2-i关于id对称，可得到r[i]至少为min(r[id*2-i]，right-i)

方法2：
http://codeforces.com/contest/7/submission/989062
使用hash存储前缀i的正向串和逆向串的指纹，同步进行比对，如果指纹相同则计算折半位置的degree
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 5000005;
int p[maxn*2],ans[maxn];
char s[maxn*2];

void manacher(int le) {
    int right=0,id=0;
    for(int i=1;i<2*le+2;++i) {
        p[i]=right>i?min(p[id*2-i],right-i):1; // 
        while(s[i+p[i]]==s[i-p[i]]) p[i]++;
        if(i+p[i]>right) {
            right=i+p[i];
            id=i;
        }
    }
}

int main() {
    long long res=0;
    int t=2;
    char c;
    s[0] = '$', s[1] = '*';
    while(1){
        c=getchar();
        if(c == EOF || c == '\n') break;
        s[t]=c,s[t+1]='*';
        t+=2;
    }
    
    manacher(t/2-1);
    int u=2;
    for(int i=0;i<(t/2-1);++i) {
        if(p[i+2]!=i+2) {
            ans[i]=0;
        }
        else {
            ans[i]=ans[(i-1)/2]+1;
            ans[i]=max(ans[i],1);
        }
        res+=ans[i];
    }
    printf("%lld\n",res);
}

// string s;
// int mem[5000010];
// int main() {
// 	cin>>s;
// 	unsigned f=0,b=0,p=1,ans=0;
// 	for(int i=1;i<=s.size();i++) {
// 		f=f*10007+s[i-1];
// 		b+=p*s[i-1];p*=10007;
// 		if(f==b) {
// 			mem[i]=mem[i/2]+1;
// 			ans+=mem[i];
// 		}
// 	}
// 	cout<<ans;
// }
