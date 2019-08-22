#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin>>s;

    if(s.size()==1 && s[0] == '0'){
        cout<<0<<endl;
    }else{
        int cnt=0, ans;
        for(int i=0; i<s.size(); i++)
            if(s[i] == '1') cnt ++;
        ans = (s.size()+1)/2;
        if(cnt == 1 && (s.size()-1)%2 == 0) ans --;
        cout<<ans<<endl;
    }
    
}