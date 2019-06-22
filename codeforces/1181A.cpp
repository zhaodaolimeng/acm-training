#include <bits/stdc++.h>

using namespace std;

int main(){
    long long x,y,z;
    cin>>x>>y>>z;
    cout<<(x+y)/z<<" ";

    if(x/z+y/z == (x+y)/z) {
        cout<<0<<endl;
    }else{
        cout<<min(z-x%z, z-y%z)<<endl;
    }
    return 0;
}