/*
Nim博弈：

由于双方都是最优策略，所以游戏只可能处于先手必胜（N）或先手必败（P）两个状态；
当所有石子堆数量的异或为0时，当前游戏处于先手必败局面。

证明：
1. 设Ai为第i堆石子数量，A1 = A2 = ... = AN = 0时，对应P状态，此时A1 xor A2 xor ... AN = 0；
2. 需要说明石子堆数量异或为0对应P状态，不为0对应N状态，且N状态通过变换一定可以转换为P状态。假设当前A1 xor A2 xor A3 ... AN = k，k的二进制为1的最高位是第i位，则一定能找到任意满足二进制为1的最高位是第i位的Aj，将Aj减少为Aj xor k，则原表达式变更为A1 xor A2 xor A3 xor ... (Aj xor k) ... AN = 0。

题目中x和m为大整数，需要特殊处理
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    long long x,m,n,ans=0;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>x>>m;
        // x为最少数量，m为堆数
        if(m%2 == 0 && x%2 == 0){
            ans ^= (m%4/2);
        } else if(m%2 == 0 && x%2 == 1){
            ans ^= ((m-2)%4/2)^x^(x+m-1);
        } else if(m%2 == 1 && x%2 == 0){
            ans ^= (m%4/2)^(x+m-1);
        } else {
            ans ^= (m%4/2)^x;
        }
    }
    if(ans!=0) cout<<"tolik"<<endl;
    else cout<<"bolik"<<endl;
    return 0;
}

