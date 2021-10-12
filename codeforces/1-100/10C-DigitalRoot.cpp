/*
设ABC均在[1,N]，找到满足d(AB)==d(C)但AB!=C的情况个数，其中d(6543) = d(6 + 5 + 4 + 3) = d(18) = 9

先确定所有满足d(AB)==d(C)的情况数N1
再确定满足AB==C的情况数N2（如果AB==C则必有d(AB)==d(C)）
最终结果为N1-N2

N1可利用求模之后的循环特性求解
需要知道d(x)=(x%9==0?9:x%9)
可以维护一个数组ans[x]存储满足d(i)==x的元素i的个数，则满足d(AB)==d(C)的所有情况数为d(A)*d(B)*d(C)
N2为sum_{i=1.N}floor(N/i)

https://zqy1018.github.io/2019/01/28/cf10c/
http://www.cnblogs.com/zfyouxi/p/4877219.html
*/
#include<bits/stdc++.h>
using namespace std;

long long ans[10];

int main() {

    int n,i,j,tmp;
    scanf("%d",&n);
    long long anw = 0;

    for(i = 1;i <= n; ++i){
        ans[(tmp = i%9) == 0 ? 9 : tmp]++;
        anw -= n/i;
    }

    for(i = 1;i <= 9; ++i)
        for(j = 1;j <= 9; ++j)
            anw += ans[i]*ans[j]*ans[(tmp = (i*j)%9) == 0 ? 9 : tmp];
    cout<<anw<<endl;
    return 0;
}

