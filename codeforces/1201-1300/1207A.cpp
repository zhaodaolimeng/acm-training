#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, b, p, f, h, c;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>b>>p>>f;
        cin>>h>>c;
        int profit = 0;
        if(b < 2) cout<<0<<endl;
        else{
            if(h>c){
                if(b/2 >= p){
                    profit += p*h;
                    profit += min((b/2-p), f)*c;
                }else{
                    profit +=b/2*h;
                }
            }else{
                if(b/2 >= f){
                    profit += f*c;
                    profit += min((b/2-f), p)*h;
                }else{
                    profit += b/2*c;
                }
            }
            cout<<profit<<endl;
        }
    }
}