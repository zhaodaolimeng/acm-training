#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

int n;
int w[5010],h[5010];
int dp[5010];
int to[5010];

int solve(int v){
    if(dp[v] > 0)
        return dp[v];    
    dp[v] =1;
    for(int i=0; i<=n; i++){
        if(w[v] < w[i] && h[v] < h[i])
            if(1 + solve(i) > dp[v]){
                dp[v] = 1 + solve(i);
                to[v] = i;
            }
    }
    return dp[v];
}

int main(){    
    memset(dp, -1, sizeof(dp));
    memset(to, -1, sizeof(to));
    cin>>n;
    for(int i=0; i<=n; i++)
        cin>>w[i]>>h[i];
    solve(0);
    cout<<dp[0]-1<<endl;    
    for(int i=to[0]; i!=-1; i=to[i])
        cout<<i<<" ";
    return 0;
}

