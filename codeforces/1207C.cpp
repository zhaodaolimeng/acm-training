#include <bits/stdc++.h>

using namespace std;

int main(){

    long long T, n, a, b;
    string s;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        cin>>s;

        long long start=0, end=0, h=1, cost=0;
        while(true){
            // cout<<end<<" "<<start<<endl;
            while(end<s.size() && s[end]=='0') end++;
            if(end==s.size()){
                cost += (end-start)*(a+b)+b;
                if(h==2) cost += a + b;
                // cout<<"1 "<<cost<<endl;
                break;
            }

            long long c1,c2;
            if(h==2){
                c1 = (end-start)*(a+2*b);
                c2 = (end-start)*(a+b) + b + 2*a;
                cost += min(c1, c2);
                // cout<<"2 "<<cost<<endl;
            }else{
                cost += (end-start)*(a+b)+a;
                h = 2;
                // cout<<"3 "<<cost<<endl;
            }

            start = end;
            while(s[end]=='1') end++;
            cost += (end-start)*(a+2*b);
            // cout<<"4 "<<cost<<endl;
            start = end;
        }
        cout<<cost<<endl;
    }
}