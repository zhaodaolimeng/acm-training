#include <bits/stdc++.h>

using namespace std;

vector<int> rods, rods_depth;
int T, depth, num;
string s;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>T;
    while(T--){
        cin>>s;
        depth = 0;
        num = -1;
        rods.clear();
        
        rods_depth.clear();
        int max_depth = 0, min_ele = (1<<30), min_ele_idx;

        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(num != -1) num *= 10;
                else num = 0;
                num += (s[i] - '0');
            }else{
                if(num != -1){
                    rods.push_back(num);
                    rods_depth.push_back(depth);
                    max_depth = max(max_depth, depth);
                    if(min_ele > num) min_ele = num, min_ele_idx = rods_depth.size()-1;
                    num = -1;
                }
                if(s[i] == '[') depth ++;
                else if(s[i] == ']') depth --;
                else continue;
            }
        }
        if(num != -1){
            rods.push_back(num);
            rods_depth.push_back(depth);
            max_depth = max(max_depth, depth);
            if(min_ele > num) min_ele = num, min_ele_idx = rods_depth.size()-1;
        }
        // for(int i=0; i<rods.size(); i++) cout<<rods[i]<<" ";
        // cout<<endl;
        // for(int i=0; i<rods_depth.size(); i++) cout<<rods_depth[i]<<" ";
        // cout<<endl;

        // cout<<max_depth<<endl;
        // cout<<rods.size()<<" "<<min_ele<<" "<<min_ele_idx<<" "<<rods_depth[min_ele_idx]<<endl;

        int ans = 0;
        for(int i=0; i<rods.size(); i++){
            int r = rods[i] % (1<<(max_depth-rods_depth[i]));
            int d = rods[i] / (1<<(max_depth-rods_depth[i]));
            if(r == 0 && d == min_ele) ans ++;
        }
        cout<<rods.size() - ans<<endl;
    }
}