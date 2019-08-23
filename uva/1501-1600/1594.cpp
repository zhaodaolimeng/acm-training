#include <bits/stdc++.h>

using namespace std;

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);

    int T, n, t;
    vector<int> vi;
    set<string> ds;

    cin>>T;
    
    while(T--){
        ds.clear();
        vi.clear();
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>t;
            vi.push_back(t);
        }

        bool is_zero = true, is_loop = false;
        while(true) {
            string s;
            is_zero = true;
            for(int i=0; i<n; i++){
                if(vi[i] != 0) is_zero = false;
                s += ("," + to_string(vi[i]));
            }
            if(ds.find(s) == ds.end()) ds.insert(s);
            else is_loop = true;
            if(is_zero || is_loop) break;
            int fi = vi[0];
            for(int i=0; i<vi.size()-1; i++) vi[i] = abs(vi[i+1] - vi[i]);
            vi[vi.size() - 1] = abs(vi[vi.size() - 1] - fi);
        }

        // for(string s : ds) cout<<s<<" ";
        // cout<<endl;
        if(is_loop) cout<<"LOOP"<<endl;
        else cout<<"ZERO"<<endl;
    }
    return 0;
}
