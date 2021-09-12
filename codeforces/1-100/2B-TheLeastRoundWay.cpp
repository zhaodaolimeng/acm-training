#include<bits/stdc++.h>
using namespace std;

// 找到一个路径使得路径上所有数值相乘结果的后缀0最少
// 状态为xy位置因子z出现的最小次数
// 只要找到当前位置累计2或5最小的路径就可得到0的个数

// 执行速度太慢，第29个用例无法通过，需要优化

const int maxn=1010;
int dp[maxn][maxn][2];
char path[maxn][maxn][2];

void print_path(int x, int y, int type){
    if(x==1&&y==1) return;
    if(path[x][y][type]=='R') print_path(x,y-1,type);
    else print_path(x-1,y,type);
    putchar(path[x][y][type]);
}

// void print_path_fast(int x, int y, int type){
//     vector<char> s;
//     for(int px=x, py=y; px!=1||py!=1; ){
//         s.push_back(path[px][py][type]);
//         if(path[px][py][type]=='R') py--;
//         else px--;
//     }
//     for(int i=s.size()-1;i>=0;i--)cout<<s[i];
//     cout<<endl;
// }

int main() {
    int n,t,t1,f2,f5,x0=0;
    scanf("%d",&n);
    memset(dp, 0, sizeof(dp));
    for(int i=2; i<=n; ++i)
        dp[0][i][0] = dp[0][i][1] = dp[i][0][0] = dp[i][0][1] = INT_MAX;
    // tricks，i如果不从2开始，下面循环中需要对首行进行特判
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d",&t);
            if(t == 0) x0 = i;
            else {
                t1 = t;
                for(f2=0;t1%2==0;f2++,t1/=2);
                for(f5=0;t%5==0;f5++,t/=5);
            }
            if(dp[i-1][j][0] >= dp[i][j-1][0]){
                dp[i][j][0] = dp[i][j-1][0] + f2;
                path[i][j][0] = 'R';
            }else{
                dp[i][j][0] = dp[i-1][j][0] + f2;
                path[i][j][0] = 'D';
            }

            if(dp[i-1][j][1] >= dp[i][j-1][1]){
                dp[i][j][1] = dp[i][j-1][1] + f5;
                path[i][j][1] = 'R';
            }else{
                dp[i][j][1] = dp[i-1][j][1] + f5;
                path[i][j][1] = 'D';
            }
            
            // cout<<dp[i][j][0]<<"\t";
        }
        // cout<<endl;
    }

    // cout<<"======"<<endl;
    // for(int i=0; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<dp[i][j][0]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<"======"<<endl;
    // for(int i=0; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<path[i][j][1]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<"======"<<endl;
    // for(int i=0; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<dp[i][j][1]<<"\t";
    //     }
    //     cout<<endl;
    // }

    t = dp[n][n][0] > dp[n][n][1]; 

    if(x0 > 0 && dp[n][n][t]){
        // 当数据中有一个0时
        puts("1");
        for (int i = 2; i <= x0; ++i) putchar('D');
		for (int i = 2; i <= n; ++i) putchar('R');
		for (int i = x0 + 1; i <= n; ++i) putchar('D');
    } else {
        cout<<dp[n][n][t]<<endl;
        print_path(n,n,t);
    }
    return 0;
}
