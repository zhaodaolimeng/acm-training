#include <bits/stdc++.h>

using namespace std;

vector<long long> rods;
long long T, depth, num;
string s;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin>>T;
    while(T--){
        cin>>s;
        depth = 0;
        num = -1;
        rods.clear();
        
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(num != -1) num *= 10;
                else num = 0;
                num += (s[i] - '0');
            }else{
                if(num != -1){
                    long long d = (1<<depth);
                    rods.push_back(num*d);
                    num = -1;
                }
                if(s[i] == '[') depth ++;
                else if(s[i] == ']') depth --;
                else continue;
            }
        }
        if(num != -1) rods.push_back(num);
        
        map<long long, int> rod_cnt;
        for(int i=0; i<rods.size(); i++) rod_cnt[rods[i]]++;

        // for(int i=0; i<rods.size(); i++) cout<<rods[i]<<" ";
        // cout<<endl;

        int ans = 0;
        for(auto const & p : rod_cnt) {
            ans = max(ans, p.second);
        }

        cout<<rods.size() - ans<<endl;
    }
}