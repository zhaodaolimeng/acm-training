#include <bits/stdc++.h>

using namespace std;

int A[51][51], B[51][51];


int main(){

    int n, m, t;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
            B[i][j] = 0;
        }
    }

    vector<pair<int,int>> ans;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(A[i][j]==1 && A[i+1][j]==1 && A[i][j+1]==1 && A[i+1][j+1]==1){
                B[i][j]=B[i+1][j]=B[i][j+1]=B[i+1][j+1]=1;
                ans.push_back(make_pair(i+1, j+1));
            }
        }
    }

    bool ok = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] != B[i][j]){
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }

    if(!ok) cout<<-1<<endl;
    else {
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}