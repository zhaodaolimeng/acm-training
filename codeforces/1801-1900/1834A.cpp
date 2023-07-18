#include<bits/stdc++.h>

using namespace std;

int main(){
    int T,n,t,pos,neg;
    cin>>T;
    while(T--){
        cin>>n;
        pos=0,neg=0;
        for(int i=0;i<n;i++){
            cin>>t;
            if(t>0) pos++;
            else neg++;
        }

        if(pos>=neg){
            if(neg%2 == 0) cout<<0<<endl;
            else cout<<1<<endl;
        }else{
            t = (neg-pos+1)/2;
            if((neg+t)%2==0) cout<<t<<endl;
            else cout<<t+1<<endl;
        }
    }
    return 0;
}