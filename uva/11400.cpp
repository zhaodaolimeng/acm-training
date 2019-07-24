#include <bits/stdc++.h>

using namespace std;

/*
3
100 500 10 20
120 600 8 16
220 400 7 18
0
 */

const int maxn = 1000 + 5;

struct Lamp{
    int v,c,k,l;
    bool operator < (const Lamp& rhs) const{
        return v < rhs.v;
    }
};

int main(){

    int n;
    const int inf = (1<<30);

    while(cin>>n && n){
        vector<int> dp(n + 1, inf);
        vector<int> s(n + 1, 0);
        vector<Lamp> lamp(n);

        for(int i=0; i<n; i++)
            cin>>lamp[i].v>>lamp[i].k>>lamp[i].c>>lamp[i].l;
        sort(lamp.begin(), lamp.end());
        
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            s[i] = lamp[i-1].l + s[i-1];
            for(int j=0; j<i; j++){
                dp[i] = min(dp[j]+(s[i]-s[j])*lamp[i-1].c + lamp[i-1].k, dp[i]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

