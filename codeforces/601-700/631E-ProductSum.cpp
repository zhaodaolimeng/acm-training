/**
 * 求一个无向图中简单环的个数
 */
#include <iostream>
#include <math.h>
using namespace std;

int dp[1<<19];
bool edges[19][19];
int connects[19][19]; // 任意两点之间的路径数目

int search(int mask){
    int ret = 0;

    for(int i=0; i<19; i++){
        if((1<<i) & mask != 0) continue;
        ret += search(mask | (1<<i));

        // 计算添加i之后连通的路径的个数
        for(int x=0; x<19; x++){
            if((1<<x) & mask != 0) continue;
            for(int y=0;y<19; y++){
                if((1<<y) & mask !=0 || x == y) continue;
                ret += connects[x][y] - connects[x][i] * connects[i][y];
            }
        }
    }
    dp[mask] = ret;
    return ret;
}

int main() {



    return 0;
}


// 34