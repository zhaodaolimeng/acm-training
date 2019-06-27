#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back

typedef long long ll;
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(255, -1);
        
        if(s.size() < 2) return s.size();
        int t = 0, tot = 1;
        
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            t ++;
            if(pos[c] == -1) pos[c] = i;
            else {
                if(t - 1 > tot) tot = t - 1;
                i = pos[c];
                for(int j=0; j<255; j++) pos[j] = -1;
                t = 0;
            }
        }
        if(t > tot) tot = t;
        return tot;
    }
};

int main(){

    Solution sl;
    string s = "dvdf";
    // string s = "abcabcbb";
    int l = sl.lengthOfLongestSubstring(s);

    cout<<l<<endl;


    return 0;
}