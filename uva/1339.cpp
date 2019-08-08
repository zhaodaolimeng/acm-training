#include <bits/stdc++.h>

using namespace std;

int main(){

    string sp, so;
    int cnt_sp[26], cnt_so[26];

    while(cin>>sp){
        cin>>so;

        memset(cnt_so, 0, sizeof(cnt_so));
        memset(cnt_sp, 0, sizeof(cnt_sp));

        for(char c : sp) cnt_sp[c - 'A'] ++;
        for(char c : so) cnt_so[c - 'A'] ++;

        sort(cnt_so, cnt_so + 26);
        sort(cnt_sp, cnt_sp + 26);

        bool ok = true;
        for(int i=0; i<26; i++){
            if(cnt_so[i] != cnt_sp[i]){
                ok = false;
                break;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
