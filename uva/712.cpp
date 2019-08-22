#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, n_query, t, idx, kase=1;
    string s, dist, ans;
    vector<int> order;

    while(cin>>n && n != 0){

        order.clear();
        for(int i=0; i<n; i++){
            cin>>s;
            order.push_back(s[1] - '0');
        }
        cin>>dist>>n_query;
        ans = "";
        for(int i=0; i<n_query; i++){
            cin>>s;
            idx = 0;
            for(int j=0; j<n; j++){
                idx += s[order[j]-1]=='0'?0:(1<<(n-j-1)); 
                // t = (1<<(n-order[j]));
                // idx += s[j]=='0'?0:t;
            }
            ans += dist[idx];
        }
        printf("S-Tree #%d:\n%s\n\n", kase, ans.c_str());
        kase ++;
    }
}