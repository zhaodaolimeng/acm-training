#include<bits/stdc++.h>

using namespace std;

int main(){
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>=2 && n<5)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
    return 0;
}