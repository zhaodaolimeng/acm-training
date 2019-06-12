#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, c;

// qualification这个条件没有用

int main(){

    const int inf = (1<<30);
    
    cin>>n;
    vector<int> qual(n);
    for(int i=0; i<n; i++) cin>>qual[i];

    cin>>m;
    vector<int> min_cost(n, inf);

    for(int i=0; i<m; i++) {
        cin>>a>>b>>c;
        min_cost[b-1] = min(min_cost[b-1], c);
    }

    int ret = 0, cnt = 0;
    for(int i=0; i<n; i++){
        if(min_cost[i] == inf) cnt++;
        else ret += min_cost[i];
    }
    // cout<<ret<<" "<<cnt<<endl;

    if(cnt > 1) cout<<-1<<endl;
    else cout<<ret<<endl;
}
