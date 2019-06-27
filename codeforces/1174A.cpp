#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, t, pre, target=-1;
    cin>>n;
    vector<int> ret;

    for(int i=0; i<2*n; i++){
        cin>>t;
        ret.push_back(t);
    }
    sort(ret.begin(), ret.end());
    bool equal = true;
    for(int i=0; i<n; i++){
        if(ret[i] != ret[n+i]){
            equal = false;
            break;
        }
    }
    if(!equal){
        for(int i=0; i<2*n; i++) cout<<ret[i]<<" ";
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}