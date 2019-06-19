#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, pos=-1, lag=0, t;
    vector<int> B;

    cin>>n;
    for(int i=0; i<n; i++) cin>>a;

    for(int i=0; i<n; i++) {
        cin>>b;
        B.push_back(b);
        if(b == 1) pos = i;
    }

    for(int i=0; i<n; i++){
        t = (n + i - pos) % n;
        if(B[i] != 0){
            if(i < pos && n + i - pos > B[i] - 1){
                // ??
            }
        }
        if(B[i] != 0 && t > B[i] - 1) lag = max(lag, t - (B[i] - 1));
    }
    cout<<lag<<" "<<pos<<endl;

    if(pos == n-1) cout<<lag + pos<<endl;
    else cout<<lag + pos + n + 1<<endl;
    return 0;
}
