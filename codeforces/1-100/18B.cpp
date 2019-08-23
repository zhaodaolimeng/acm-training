#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000001;
bool vis[maxn];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long n, d, m, l;  // [(k-1)*m, (k-1)*m+l]
    long long p = 0, t;
    
    cin>>n>>d>>m>>l;

    memset(vis, 0, sizeof(vis));
    vis[0] = true;

    while(true){
        p += d;
        t = p%m;

        if(vis[t]){
            long long ans = 0;
            if(m*n%d == 0) ans = m*n;
            else ans = (m*n/d + 1)*d;
            cout<<ans<<endl;
            break;
        }
        if((t>l && t<m) || (p > n*m)){
            cout<<p<<endl;
            break;
        }
        vis[t] = true;
    }
    return 0;
}
