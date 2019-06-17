#include <iostream>

using namespace std;

int main(){
    int T;
    long long n, k, t, ret;

    cin>>T;
    while(T--){
        cin>>n>>k;
        ret = 0;
        while(n>0){
            t = n % k;
            if(t == 0){
                n /= k;
                ret ++;
            }else{
                n -= t;
                ret += t;
            }
            // cout<<n<<" ";
        }
        cout<<ret<<endl;
    }
}