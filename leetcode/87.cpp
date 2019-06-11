#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    bool isScramble(string s, string t) {
        return solve(s, t, 0, 0, s.size());
    }

    bool solve(string s, string t, int si, int ti, int len){
        if(len == 1 && s[si] == t[ti]) return true;

        // cout<<s.substr(si, len)<<" "<<t.substr(ti, len)<<endl;

        bool ok = true;
        for(int i=0; i<len; i++)
            if(s[si+i] != t[ti+i]){
                ok = false;
                break;
            }
        if(ok) return true;

        int alpha[26] = {0};
        for(int i=0; i<len; i++){
            alpha[s[si+i]-'a'] ++;
            alpha[t[ti+i]-'a'] --;
        }
        for(int i=0; i<26; i++)
            if(alpha[i] != 0)
                return false;

        for(int i=1; i<len; i++){
            if(solve(s, t, si, ti, i) && 
                solve(s, t, si+i, ti+i, len-i))
                return true;
            if(solve(s, t, si, ti+(len-i), i)&&
                solve(s, t, si+i, ti, len-i))
                return true;
        }
        return false;
    }
};

int main(){
    Solution sl;
    cout<<sl.isScramble("abc", "acb")<<endl;
}
