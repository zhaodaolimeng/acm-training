#include <bits/stdc++.h>

using namespace std;

int main(){

    long long q, n, m;
    vector<int> last_v;

    cin>>q;
    while(q--){
        cin>>n>>m;
        if(n < m) {
            cout<<0<<endl;
            continue;
        }

        long long first, last, t, cnt = 1, loop_sum;
        first = m % 10;
        loop_sum = first;
        for(t = first; ; cnt++){
            t += first;
            if(t>=10) t-= 10;
            if(t == first) break;
            loop_sum += t;
        }

        long long loop_pages = cnt * m;
        long long loop_cnt = n / loop_pages;
        long long remain = n % loop_pages, ans;

        ans = loop_cnt*loop_sum;
        // cout<<cnt<<" "<<loop_pages<<" "<<loop_cnt<<" "<<loop_sum<<endl;

        t = first;
        for(long long i=m; i<=remain; i+=m){
            ans += t;
            t += first;
            if(t>=10) t-=10;
        }
        cout<<ans<<endl;
    }
}