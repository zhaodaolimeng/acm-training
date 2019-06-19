#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n;
    m = 1 + n/2;

    cout<<m<<endl;
    for(int i=0; i<m; i++)
        cout<<1<<" "<<i+1<<endl;
    n -= m;
    for(int i=0; i<n; i++)
        cout<<i+2<<" "<<m<<endl;
    
    return 0;
}