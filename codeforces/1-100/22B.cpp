#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,m,t,dx,dy,maxc=0;
    cin>>n>>m;
    vector<string> M(n);
    for(int i=0;i<n;i++) cin>>M[i];
    
    // // 1 - 暴力搜索
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(M[i][j]==1) continue;
    //         if(i>0 && M[i-1][j]==0) continue;
    //         if(j>0 && M[i][j-1]==0) continue;
            
    //         for(dx=i;dx<n;dx++){
    //             for(dy=j;dy<m;dy++){
    //                 t = 0;
    //                 for(int x=i;x<=dx;x++)
    //                     for(int y=j;y<=dy;y++)
    //                         t+=M[x][y]-48;
    //                 if(t>0) continue;
    //                 t = (dx-i+1 + dy-j+1)*2;
    //                 if(t>maxc) maxc=t;
    //             }
    //         }
    //     }
    // }
    // cout<<maxc<<endl;

    // 2 - dp， dp[x][y][dx] = dy 
    // x 桌子右下角行数
    // y 桌子右下角列数
    // dx 桌子左上角行数
    // dy 桌子最大时，左上角列数
    // dp[x][y][dx] = min(dp[x-1][y][dx],(y-j+1 for j in y..0 if M[x][j]==0)) 
    vector<vector<vector<int> > > dp(n, 
        vector<vector<int> >(m, vector<int>(n,0)));

    // TODO 初始化

    for(int x=0;x<n;x++){
        for(int y=0;j<m;y++){
            for(dx=0; dx<=x; dx++){
                for(dy=y; dy>=dp[x-1][y][dx] && M[x][dy]==0;dy--);
                dp[x][y][dx] = dy;
                t = (dx-x+1 + dy-y+1)*2;
                if(t>maxc) maxc=t;
            }
        }
    }
    cout<<maxc<<endl;
    return 0;
}
