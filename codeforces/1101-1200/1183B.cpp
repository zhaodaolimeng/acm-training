#include <iostream>

using namespace std;

int main(){
    int q, n, k, t, maxn, minn;
    cin>>q;

    while(q--){
        cin>>n>>k;

        maxn=-1, minn=(1<<30);
        for(int i=0; i<n; i++){
            cin>>t;
            maxn = max(maxn, t);
            minn = min(minn, t);
        }
        
        if(maxn - minn > k * 2){
            cout<<-1<<endl;
        }else{
            cout<<minn + k<<endl;
        }
    }
    return 0;
}
