#include <bits/stdc++.h>

using namespace std;


void check_cover(int x, int y, vector<pair<int, int>>& pairs){
    for(const auto & p : pairs){
        if(x != p.first && y != p.second && x != p.second && y != p.first) return ;
    }
    cout<<"YES"<<endl;
    exit(0);
}

void check(int num, vector<pair<int, int>>& pairs){
    for(int i=1; i<pairs.size(); i++){
        if(num == pairs[i].first || num == pairs[i].second) continue;
        check_cover(num, pairs[i].first, pairs);
        check_cover(num, pairs[i].second, pairs);
        return ;
    }
    cout<<"YES"<<endl;
    exit(0);
}

int main(){
    int n, m, a, b;
    cin>>n>>m;

    vector<pair<int, int>> pairs;

    for(int i=0; i<m; i++){
        cin>>a>>b;
        pairs.push_back(make_pair(a, b));
    }

    check(pairs[0].first, pairs);
    check(pairs[0].second, pairs);

    cout<<"NO"<<endl;
    return 0;
}
