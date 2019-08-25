#include <bits/stdc++.h>

using namespace std;

int m, n, K, xt, yt;
int area[21][21];
int dp[21][21];  // 在位置x,y，还剩k次机会时的最短路径

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void min_path(int x, int y, int k_left){

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // // cout<<x<<" "<<y<<" "<<k_left<<endl;
    // cout<<"====="<<endl;

    for(int d=0; d<4; d++){
        int x_ = x + dx[d], y_ = y + dy[d];
        if(x_>=m || x_<0 || y_>=n || y_<0) continue;
        if(area[x_][y_] == 1 && k_left == 0) continue;

        if((dp[x_][y_] == -1 && dp[x][y] != -1) || 
            (dp[x_][y_] != -1 && dp[x_][y_] >= dp[x][y]+1)){
            dp[x_][y_] = dp[x][y] + 1;
        }else continue;

        if(area[x_][y_] == 0){
            min_path(x_, y_, K);
        }else{
            if(area[x][y] == 0) min_path(x_, y_, K-1);
            else min_path(x_, y_, k_left-1);
        }
    }
}


int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    while(T--){
        cin>>m>>n>>K;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>area[i][j];
        
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        min_path(0, 0, K);

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        cout<<dp[m-1][n-1]<<endl;
    }
}