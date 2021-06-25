#include<bits/stdc++.h>
using namespace std;


int main() {

    int n,ret=0;
    vector<int> v = {100,20,10,5,1};
    cin>>n;

    for(int i=0;i<v.size() && n>0;i++){
        if(n>=v[i]){
            ret+=n/v[i];
            n%=v[i];
        }
    }
    cout<<ret<<endl;
    return 0;
}
