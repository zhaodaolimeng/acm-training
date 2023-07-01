#include<bits/stdc++.h>

using namespace std;

int main(){
    long long t,n,k,q,a,l;
    std::cin>>t;
    while(t--){
        std::cin>>n>>k>>q;
        long long prev=-1, prev_a=q+1, ret=0;

        for(int i=0;i<n;i++){
            std::cin>>a;
            if(a > q){
                if(prev < i-1){
                    l = i - prev - 1;
                    if(l>=k) ret += (l-k+2)*(l-k+1)/2;
                }
                prev = i;
                prev_a = a;
            }
        }
        if(prev != n-1){
            l = n - prev - 1;
            if(l>=k) ret += (l-k+2)*(l-k+1)/2;
        }
        std::cout<<ret<<endl;
    }
    return 0;
}