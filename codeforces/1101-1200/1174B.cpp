#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t, odd=0;
    vector<int> a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        if((t & 1) == 1) odd++;
        a.push_back(t);
    }
    
    if(odd !=0 && odd != n) sort(a.begin(), a.end());
    
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}
