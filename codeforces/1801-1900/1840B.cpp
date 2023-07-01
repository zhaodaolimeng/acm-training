#include<bits/stdc++.h>

using namespace std;

int main(){

    int t,n,k;
    // std::cout<<(1<<30)<<endl;

    std::cin>>t;
    while(t--){
        std::cin>>n>>k;
        if(k>29 || n<(1<<k)){
            std::cout<<n+1<<endl;
        }else{
            std::cout<<(1<<k)<<endl;
        }
    }
    return 0;
}
