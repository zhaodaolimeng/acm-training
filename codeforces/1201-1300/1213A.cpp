#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    int even=0, odd=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x%2 == 0) even++;
        else odd ++;
    }
    cout<<min(even, odd)<<endl;
}