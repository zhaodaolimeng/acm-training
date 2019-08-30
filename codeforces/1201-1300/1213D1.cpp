#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k, t;
    cin>>n>>k;

    vector<string> as;
    
    for(int i=0; i<n; i++){
        cin>>t;
        string s;
        while(t!=0){
            s = to_string((t&1)) + s;
            t >>= 1;
        }
        as.push_back(s);
    }

    sort(as.begin(), as.end());

    int ans = (1<<30);

    for(int start=0; start<as.size()-k+1; start++){

        int min_len = (1<<30), min_move = 0;
        for(int i=start; i<start+k; i++)
            min_len = min(min_len, (int)as[i].size());
        for(int i=start; i<start+k; i++)
            min_move += as[i].size() - min_len;

        // cout<<min_move<<" "<<min_len<<endl;
        int p;
        for(p=0; p<min_len; p++){
            bool same = true;
            for(int i=start+1; i<start+k; i++){
                if(as[i][p] != as[start][p]) {
                    same = false;
                    break;
                }
            }
            if(!same) break;
        }
        min_move += (min_len - p) * k;

        // cout<<start<<" "<<min_move<<endl;
        ans = min(ans, min_move);
    }
    cout<<ans<<endl;
}