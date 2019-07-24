#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){

    int n, m;
    string s, name;
    cin>>n>>s>>m;
    vector<vector<int>> scnt(26, vector<int>(n, 0));

    scnt[s[0] - 'a'][0] ++;
    for(int i=1; i<n; i++){
        for(int j=0; j<26; j++) scnt[j][i] = scnt[j][i - 1];
        scnt[s[i] - 'a'][i] = scnt[s[i] - 'a'][i] + 1;
    }
    
    while(m--){
        vector<int> ncnt(26, 0);
        cin>>name;
        for(char c : name) ncnt[c - 'a'] ++;

        int t, ans = 0;
        for(int i=0; i<26; i++){
            auto p = lower_bound(scnt[i].begin(), scnt[i].end(), ncnt[i]);
            t = p - scnt[i].begin();
            if(ans < t) ans = t;
        }
        cout<<ans + 1<<endl;
    }
    return 0;
}
