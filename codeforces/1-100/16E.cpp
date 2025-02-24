#include<bits/stdc++.h>
using namespace std;

// 状态压缩

int main(){

    int n;
    cin>>n;
    vector<vector<double>> A(n,vector<double>(n));
    vector<double> dp(1<<n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>A[i][j];
    }

    dp[(1<<n)-1] = 1.0;
    for(int s=((1<<n)-2); s>0; s--){
        // 遍历每个状态，上一轮中i被j吃掉的概率
        int cnt=0;
        double t=0;
        for(int i=0;i<n;i++){
            if((1<<i)&s){
                cnt++;
                continue;
            }
            for(int j=0;j<n;j++){
                if((1<<j)&s)
                    t += dp[s|(1<<i)]*A[j][i];
            }
        }
        // cout<<cnt<<endl;
        dp[s]+= t*2.0/(cnt*(cnt+1));
    }
    // for(int s=((1<<n)-1); s>0; s--){
    //     cout<<s<<" "<<dp[s]<<endl;
    // }
    for(int i=0;i<n;i++){
        printf("%.6f ",dp[(1<<i)]);
    }
    cout<<endl;
    return 0;
}