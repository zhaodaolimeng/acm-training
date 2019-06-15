#include <iostream>

using namespace std;


int main(){

    long long n;
    int q, cnt;
    cin>>q;

    for(int i=0; i<q; i++){
        cin>>n;
        cnt =0;
        for(; n%5 == 0; cnt ++) n/=5, n<<=2;
        for(; n%3 == 0; cnt ++) n/=3, n<<=1;
        for(; (n&1) != 1; cnt ++) n>>=1; 
        if(n == 1)
            cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
}
