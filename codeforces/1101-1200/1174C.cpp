#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> prime(n+1, 0);
    int pcnt = 1;

    for(int i=2; i<=n; i++){
        if(prime[i] == 0){
            prime[i] = pcnt;
            for(int j=i+i; j<=n; j+=i){
                if(prime[j]==0)
                    prime[j] = pcnt;
            }
            pcnt ++;
        }
    }

    for(int i=2; i<=n; i++) cout<<prime[i]<<" ";
    cout<<endl;
    return 0;
}