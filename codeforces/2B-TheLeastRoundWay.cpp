#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<bitset>

using namespace std;

const int INF=0x7fffffff;
const int maxn=1010;

char path[maxn][maxn][2];
int dp[maxn][maxn][2];  // 每个数字中2和5的个数
int n, x, cnt, t, min_k;

void dfs(int i, int j) {
    if(i==1 && j==1)
        return ;
    if(path[i][j][min_k]){
        dfs(i-1, j);
        putchar('D');
    }else{
        dfs(i, j-1);
        putchar('R');
    }
}

int main() {

    while(~scanf("%d",&n)) {

        memset(dp, INF, sizeof dp);
        for(int i=2; i<=n; ++i)
		    dp[0][i][0] = dp[0][i][1] = dp[i][0][0] = dp[i][0][1] = INF;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d",&x);
                for(int k=0; k<2; k++){
                    for(cnt=0, t=x; t%2==0; t/=2, cnt++);
                    dp[i][j][k]=cnt;
                }
                for(int k=0; k<2; k++){
                    path[i][j][k] = (dp[i-1][j][k] > dp[i][j-1][k]);
                    if(path[i][j][k]){
                        dp[i][j][k] += dp[i-1][j][k];
                    }else{
                        dp[i][j][k] += dp[i][j-1][k];
                    }
                }
            }
        }
        min_k = (dp[n][n][1] < dp[n][n][0]);
        if(x && dp[n][n][min_k]>1){

        }
        
        dfs(n,n);
    }
    return 0;
}
