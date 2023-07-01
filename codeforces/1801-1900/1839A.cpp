#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,k;
    std::cin>>t;
    while(t--){
        std::cin>>n>>k;
        if(k==1) 
            std::cout<<n<<endl;
        else
            std::cout<<(n/k)+(n%k==0?0:1)+(n%k==1?0:1)<<endl;
    }
    return 0;
}