#include <iostream>

using namespace std;

int main(){
    int q, k, n, a, b;

    cin>>q;
    while(q--){
        cin>>k>>n>>a>>b;

        if(k/b < n || (k/b == n && k%b == 0)){
            cout<<-1<<endl;
        }else{
            int t = (k - b*n) / (a - b);
            if((k - b*n) % (a - b) == 0) t -= 1;
            cout<<min(t, n)<<endl;
        }
    }
    return 0;
}