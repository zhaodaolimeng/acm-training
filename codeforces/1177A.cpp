#include <bits/stdc++.h>

using namespace std;

int main(){
    long long k, v=0, pos=0;
    cin>>k;

    for(long long i=1, b=1; ;i++, b*=10){
        pos += i*9*b;
        v += 9*b;
        
        if(pos >= k){
            // cout<<pos<<" "<<v<<" "<<i<<endl;
            long long num_of_same_length = (k - (pos-i*9*b)-1)/i;
            // cout<<num_of_same_length<<endl;
            string s = to_string(v-9*b+num_of_same_length+1);
            // cout<<s<<endl;
            // cout<<(k - (pos-i*9*b) - 1)%i<<endl;
            cout<<s[(k - (pos-i*9*b) - 1)%i]<<endl;
            return 0;
        }
    }
    return 0;
}
