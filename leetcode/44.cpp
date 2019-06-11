#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }

    bool solve(string s, string p, int si, int pi){
        if(si == s.size() && pi == p.size())
            return true;

        if(si == s.size() && (pi<p.size()&&p[pi]!='*'&&p[pi]!='?'))
            return false;
        
        if(p[pi]!='*' && p[pi]!='?'){
            if(s[si] != p[pi])
                return false;
            else 
                return solve(s, p, si+1, pi+1);
        }
        
        if(p[pi] == '?'){
            if(si == s.size()) return false;
            return solve(s, p, si+1, pi+1);
        }

        if(p[pi] == '*'){
            if(pi == p.size() - 1) return true;
            while(pi+1 != p.size() && p[pi+1] == '*') pi++;
            if(si == s.size()){
                for(int j=pi; j<p.size(); j++)
                    if(p[j] != '*')
                        return false;
                return true;
            }
            for(int i=si; i<=s.size(); i++){
                if(solve(s, p, i, pi+1))
                    return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sl;
    // bool ret = sl.isMatch("ho", "ho**");
    bool ret = sl.isMatch(
        "bbaaaabaaaaabbabbabbabbababaabababaabbabaaabbaababababbabaabbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa", 
        "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a****");
    // bool ret = sl.isMatch("aa", "*");
    // bool ret = sl.isMatch("abc", "*abc?*");
    cout<<ret<<endl;
}
