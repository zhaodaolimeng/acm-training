#include <bits/stdc++.h>

using namespace std;

// x[i] = 2^(i-2)*a + r[i] + 
//        2^0*r[i-1] + 2^1*r[i-2] + ... + 2^(i-3)r[2]


int main(){
    int q;
    long long a, b, m;
    vector<long long> lower, upper;

    cin>>q;

    while(q--){
        cin>>a>>b>>m;
        lower.empty();
        upper.empty();

        for(int i=2; ; i++){
            lower.push_back((1<<(i-2)) + (1<<(i-2))*a);
            upper.push_back((1<<(i-2))*m + (1<<(i-2))*a);
            if(b > lower.back()){
                if(b <= upper.back()){
                    cout<<lower.size() + 1<<" "<<a;
                    for(int i=0; i<lower.size()-1; i++)
                        cout<<" "<<lower[i] + 1;
                    cout<<" "<<b<<endl;
                    break;
                }
            }else{
                cout<<-1<<endl;
                break;
            }
        }
    }
    return 0;
}
