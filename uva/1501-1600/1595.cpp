#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

bool same(double a, double b){
    if(abs(a - b) > eps) return false;
    return true;
}

bool check(map<int, vector<int>> mp){

    double pivot, p, pt;
    bool is_first = true;

    for(auto const& e : mp){
        vector<int> vi = e.second;

        sort(vi.begin(), vi.end());
        if(vi.size()%2 == 1) p = vi[vi.size()/2];
        else p = 1.0*(vi.front() + vi.back())/2;
        if(is_first) pivot = p;
        if(!same(p, pivot)) return false;

        for(int i=1; i<vi.size()/2; i++){
            p = 1.0*(vi[i] + vi[vi.size()-i-1])/2;
            if(!same(p, pivot)) return false;
        }
        if(!same(p, pivot)) return false;
        is_first = false;
        pivot = p;
    }
    return true;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T, n, x, y;

    map<int, vector<int>> mp;

    cin>>T;
    while(T--){
        mp.clear();
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>x>>y;
            if(mp.find(y) == mp.end()){
                vector<int> vi;
                vi.push_back(x);
                mp[y] = vi;
            }else{
                mp[y].push_back(x);
            }
        }
        if(!check(mp)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

}