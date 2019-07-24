#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 5;
int nodes[MAXN];

int main(){
    int n, u, v;

    cin>>n;

    memset(nodes, 0, sizeof(nodes));

    for(int i=1; i<n; i++){
        cin>>u>>v;
        nodes[u]++;
        nodes[v]++;
    }

    for(int i=1; i<=n; i++){
        if(nodes[i] == 2){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}