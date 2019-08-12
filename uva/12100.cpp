#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, n, p, t;
    vector<int> vi;

    cin>>T;
    while(T--){
        vi.clear();
        cin>>n>>p;
        for(int i=0; i<n; i++){
            cin>>t;
            vi.push_back(t);
        }

        int larger_cnt0 = 0, larger_cnt1 = 0;

        for(int i=0; i<n; i++){
            if(vi[i] > vi[p]){
                if(i < p) larger_cnt0 ++;
                else if(i > p) larger_cnt1 ++;
            }
        }

        int cnt = 0;
        if(p >= larger_cnt0 + larger_cnt1){
            // 不用后移
            for(int i=larger_cnt0 + larger_cnt1; i<p; i++)
                if(vi[i] == vi[p]) cnt ++;
        }else{
            // 后移
            // 1 1 9 1 1 1
            for(int i=n-1; i>p && vi[i]<=vi[p]; i--)
                if(vi[i] == vi[p]) cnt ++;
        }
        cout<<larger_cnt0 + larger_cnt1 + cnt + 1<<endl;
    }
}