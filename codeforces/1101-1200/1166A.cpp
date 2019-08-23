#include <bits/stdc++.h>

using namespace std;

int c[26];

int main(){
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        c[s[0]-'a']++;
    }

    int ret=0, t;
    for(int i=0; i<26; i++){
        t = c[i]>>1;
        ret += t > 1 ? (t*(t-1)/2) : 0;
        t = c[i] - t;
        ret += t > 1 ? (t*(t-1)/2) : 0;
    }
    cout<<ret<<endl;
    return 0;
}