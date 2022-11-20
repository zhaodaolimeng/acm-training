#include <bits/stdc++.h>
using namespace std;

// https://www.cnblogs.com/int-me-X/p/14423030.html


int main(){
    string s,t;
    cin>>s>>t;
    s = t+"#"+s;
    vector<int>pi(s.length());
    int ans = 0, cont = 0;

    for(int i=1;i<s.length();i++){
        int j=pi[i-1];
        while(j>0 && (s[i]!=s[j] && s[i]!='?' && s[j]!='?' || s[j] == '#'))
            j=pi[j-1];
        
        if(s[j]==s[i] || ((s[j]=='?' || s[i] == '?')&& s[j] != '#')) j++;
        pi[i] = j;
        if(pi[i]==t.length()) {
            ans ++;
            cont = 1;
        } else {
            if(s[i] == '?'){
                if(cont == 1) ans ++;
            }else
                cont = 0;
        }
    }

    cout<<s.substr(1+t.length())<<endl;

    for(int i=t.length()+1;i<s.length();i++){
        cout<<pi[i];
    }
    cout<<endl;

    cout<<ans<<endl;
    return 0;
}

/*
??b??
abba

ab????
ab

aa?????
aab

?????
abc

emnd?t??m?gd?t?p?s??m?dp??t???m?????m?d?ydo????????i??u?d??dp??h??d?tdp???cj?dm?dpxf?hsf??rdmt?pu?tw
dmtdp

*/
