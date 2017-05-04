/**
 * 从n个菜中顺序选择m个菜，每个菜具有一个价值，且如果选择中包含特定的相邻组合，也会增加价值
 * 问可能获得的最大价值是多少？
 *
5 5 5
3 3 3 3 3
3 4 6
4 1 2
1 5 7
5 2 4
2 3 5

5 4 1
10 0000 0000 500000000 1 1000000000 1000000000
3 5 700000000


 */
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

long m, n, rule;
long p, q, r;
long long t;
long long sat[18]; // 价值
long long c[18][18]; // 满足顺序关系之后的价值
long long dp[1<<18][18]; // 当前状态与上一个对应的价值

int main(){

    memset(c, 0, sizeof(c));

    cin>>n>>m>>rule;
    for(int i=0;i<n;i++)
        cin>>sat[i];

    for(int i=0;i<rule;i++){
        cin>>p>>q>>r;
        c[p-1][q-1] = r;
    }

    long long ans = 0;

    for(int i=0; i<n; i++){
        dp[(1<<i)][i] = sat[i];
        if(sat[i] > ans)
            ans = sat[i];
    }

    for(int i = 0; i<(1<<n); i++){

        t = 0; // 检查1的个数
        for(int j=0;j<n;j++){
            if((i&(1<<j)) != 0) t+=1;
        }
        if(t >= m) continue;

        for(int j = 0; j<n; j++){ // 上一次的选择
            if((i & (1<<j)) == 0)
                continue;

            for(int k = 0; k < n; k++){ // 当前的选择
                if((i & (1<<k)) == 0){
                    t = sat[k] + c[j][k] + dp[i][j];
                    if(t > dp[i|(1<<k)][k]){
                        dp[i|(1<<k)][k] = t;
                        if(t > ans) ans = t;
                    }
                }
            }
        }
    }

//    for(int i=0; i<(1<<n); i++){
//        for(int j=0; j<n; j++){
//            if(((1<<j)&i) == 0){
//                cout<<'0';
//            } else
//                cout<<'1';
//        }
//        cout<<"\t";
//        for(int j=0; j<n; j++){
//            cout<<dp[i][j]<<"\t";
//        }
//        cout<<endl;
//    }

    cout<<ans<<endl;
    return 0;
}

