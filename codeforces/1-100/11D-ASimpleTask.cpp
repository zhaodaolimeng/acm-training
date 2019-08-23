/**
 * codeforces 11D
 * ==============
 * 计算一个无向简单图中环的个数
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

// dp[i][j]表示从i中第一个是1的位置出发，最终到达节点j，且所有节点都在i中的路径数目
long long dp[1<<20][20];
int connect[20][20];

int main() {

    int N,M, u, v;
    cin>>N>>M;
    long long ans = 0;

    for(int i=0; i<M; i++){
        cin>>u>>v;
        connect[u-1][v-1] = connect[v-1][u-1] = 1;
    }

    for (int i = 0; i < N; i++)
        dp[1<<i][i] = 1;

    for(int state=1; state<(1<<N); state++){
        int start = 0; // 能这样选的原因是因为最高位是随着循环从右向左移动的
        for(int i=0; i<N; i++){
            if(state & (1<<i)){
                start = i;
                break;
            }
        }
        for(int e=start; e<N; e++){
            if(state & (1<<e)){
                for(int i=start; i<N; i++){
                    if(!(state&(1<<i)) && connect[i][e]){
                        dp[state|(1<<i)][i] += dp[state][e]; // 此时能保证路径从start出发到达i
                        if (connect[i][start] && __builtin_popcount(state|(1<<i)) >= 3)
                            ans += dp[state][e];
                    }
                }
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
