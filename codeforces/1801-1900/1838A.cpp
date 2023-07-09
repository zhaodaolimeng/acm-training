#include<bits/stdc++.h>

using namespace std;

int main(){
    int T,n,t;
    cin>>T;
    
    while(T--){

        cin>>n;

        bool hit = false;
        int ret=-1, maxv=-1;
        for(int i=0;i<n;i++){
            cin>>t;

            if(!hit && t<0) {
                ret = t;
                hit = true;
            }
            if(t>maxv) maxv = t;
        }
        if(hit) cout<<ret<<endl;
        else cout<<maxv<<endl;
    }

    return 0;
}