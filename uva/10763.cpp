#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    map<pair<int, int>, int> sp;

    int n, a, b;
    while(cin>>n && n != 0){

        sp.clear();
        for(int i=0; i<n; i++){
            cin>>a>>b;
            if(a<b) sp[make_pair(a, b)] ++;
            else sp[make_pair(b, a)] --;
        }

        int cnt = 0;
        for(auto const& x : sp){
            if(x.second > 0){
                cnt ++;
                break;
            }
        }
        if(cnt > 0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}