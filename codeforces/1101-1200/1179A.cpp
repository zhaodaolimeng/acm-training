#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back

typedef long long ll;
using namespace std;

int main(){

    int n, q, t;
    int maxn = 0, maxi = 0;
    deque<int> dq;
    vector<pair<int, int>> ab;

    cin>>n>>q;

    for(int i=0; i<n; i++){
        cin>>t;
        if(t > maxn) maxn = t, maxi = i;
        dq.push_back(t);
    }

    if(q == 0) return 0;

    for(int i=0; i<maxi; i++){
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();
        ab.push_back(make_pair(a, b));

        if(a >= b) {
            dq.push_front(a);
            dq.push_back(b);
        }else{
            dq.push_front(b);
            dq.push_back(a);
        }
    }

    vector<int> dv;
    dq.pop_front();
    for(int i=1; i<n; i++){
        t = dq.front(); dq.pop_front();
        dv.push_back(t);
    }
    
    ll m;
    for(int i=0; i<q; i++){
        cin>>m;
        if(m <= maxi){
            cout<<ab[m-1].first<<" "<<ab[m-1].second<<endl;
        }else{
            t = (m-maxi-1)%(n-1);
            cout<<maxn<<" "<<dv[t]<<endl;
        }
    }
    return 0;
}