#include <bits/stdc++.h>

using namespace std;

int n, m;
bool graph[105][105];
int path[1000010];
bool mark[1000010];


int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            graph[i][j] = getchar() - '0';
    
    cin>>m;
    for(int i=0; i<m; i++) cin>>path[i];

    queue<int> q;
    q.push(path[0]);

    bool done = false;
    memset(mark, false, sizeof(mark));
    mark[0] = true;
    
    while(!q.empty() && !done){
        int qs = q.size();
        for(int i=0; i<qs; i++){
            int t = q.front(); q.pop();
            if(t == path[m-1]){
                done = true;
                break;
            }
            
        }

    }
    
}