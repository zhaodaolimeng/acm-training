/*
一个环上有多个不同高度的点，统计所有两点间高度均不高于两点的点对
http://codeforces.com/blog/entry/213

考虑一个简化的题目：检查一个直线上能相互观察到的点对，所有点的高度都是唯一的，则对于每个点：
找到x左边第一个高于它的位置l[x]
找到x右边第一个高于它的位置r[x]
l[x]和r[x]均可以在O(n)的复杂度内求得。
具体方式是从右向左检查每个位置x，检查其右边节点t，如果height[x]>height[t]，则将t移动到r[t]。
可以证明向右检查的步骤至多对每个节点检查1次。

对于原问题，首先找到最高点，将这个环展开为数组，数组共有n+1个元素将以最高点为开始且以最高点结束
对于每个点x：
找到x左边第一个严格高于它的位置l[x]
找到x右边第一个严格高于它的位置r[x]
x与r[x]之间所有高度等于x的位置c[x]
每个点x对最后结果的贡献包括(x,l[x])和(x,r[x])，以及c[x]。

实现技巧：
https://blog.csdn.net/qq_35414878/article/details/85787876
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n,maxi=0,ans=0;
    cin>>n;
    vector<int> vec(n),height(n+1),l(n+1),r(n+1),c(n+1);

    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[maxi]<vec[i]) maxi = i;
    }

    // 平移
    for(int i=0;i<n;i++) height[i] = vec[(i+maxi)%n];
    height[n] = vec[maxi];

    // for(int i=0;i<=n;i++) cout<<height[i]<<" ";
    // cout<<endl;

    // 从左向右检查
    for(int i=1; i<n; i++){
        l[i] = i-1;
        while(l[i]>0 && height[i] >= height[l[i]]) l[i] = l[l[i]];
    }

    // 从右向左检查
    c[n] = 0;
    for(int i = n - 1; i >= 0; --i) {
        r[i] = i + 1;
        while (r[i] < n && height[i] > height[r[i]]) r[i] = r[r[i]];
        if (r[i] < n && height[i] == height[r[i]]) {
            c[i] = c[r[i]] + 1;
            r[i] = r[r[i]];
        }
    }

    for(int i=1;i<n;i++){
        ans += c[i]+2;
        if(l[i]==0 && r[i]==n) ans--;
    }
    cout<<ans<<endl;
    return 0;
}
