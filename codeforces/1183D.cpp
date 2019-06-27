#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int q, n, t;

    cin >>q;
    while(q--){
        vector<int> a(200005, 0);
        vector<int> o;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>t;
            a[t] ++;
        }

        for(int i=0;i<a.size(); i++){
            if(a[i] != 0)
                o.push_back(a[i]);
        }
        sort(o.begin(), o.end());

        int ans = 0;
        int p, last_cnt = 0, cur_cnt = 0;
        for(int i=o.size()-1 ; i>=0; i--){
            cout<<o[i]<<" "<<last_cnt<<" "<<cur_cnt<<endl;
            if(i == o.size() - 1){
                cur_cnt = o[i];
                ans += cur_cnt;
            } else if(o[i] == o[i+1]){
                cur_cnt --;
                ans += cur_cnt;
            }else{
                if(cur_cnt < o[i]) ans += cur_cnt;
                else{
                    ans += o[i];
                    cur_cnt = o[i];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
