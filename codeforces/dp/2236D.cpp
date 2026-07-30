#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
t
n k
a1,a2,...an

E、D轮流拿数字，后者拿的数字必须大于等于前者，且不超过k，是否有一个开始位置，使得E使用有必胜策略

进行搜索
f(x,m)是在值x时，是否有最优策略
f(x,m) = for 1...i...k f(x+i,m+a[y])
每个节点是这些值出现的次数的加和，如果任意节点为偶数，返回yes即可，否则返回no
*/

int b[200001];
int dp[200001];
int t,n,k,v,ans;

// // 方法1：使用递归尝试
// int dfs(int p,int cnt){
//     if(cnt>0 && cnt%2==0)
//         return 1;
//     for(int q=p+1;b[p]-b[q]<=k && q>0;q--)
//         return dfs(cnt + b[q]);
//     return 0;
// }

int main(){
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(b,0,sizeof(b));

        for(int i=1;i<=n;i++){
            cin>>v;
            b[v]++;
        }

        // // 方法1：使用递归尝试
        // ans = dfs(n,0);

        // 方法2：使用dp
        ans = 0;
        memset(dp,0,sizeof(dp));
        dp[n] = b[n];

        // 不需要这样，复杂度高
        for(int i=0;i<n;i++){
            for(int j=n-i;j>0;j--){
                for(int l=0;l<=k && j-l>0;l++){
                    dp[j-l] = dp[j] + b[j-l];
                    if(dp[j-l]%2==0) ans=1;
                }
                if(ans==1) break;
            }
            if(ans==1) break;
        }

        // 关键点，整个升序序列会被规则分为多个段
        // 每个段中，右端序列只要是偶数，则一定A能构造出必胜策略
        // 推演之后有：
        // b[i]如果是偶数则A一定有必胜策略
        // 分情况，b[i]为偶数时
        // b[i]为最右端，A取i，E取i，结束
        // b[i]不为最右端，A取i，E取i+l，剩余为偶数，E有必胜策略
        // 另外b[i]和b[i+l]联通，A也一定有必胜策略
        // A可以根据右端奇偶性选择取b[i]还是b[i+l]
        
        if(ans>0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}