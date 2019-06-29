#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxl = 1, maxpos = 0, d;
        for(int i=0; i<s.size(); i++){
            for(d=1; i+d<s.size() && i-d>=0; d++)
                if(s[i+d] != s[i-d]) break;
            if(d*2 - 1 > maxl){
                maxl = d*2 - 1;
                maxpos = i - d + 1;
            }
            for(d=1; i+d<s.size() && i-d+1>=0; d++)
                if(s[i+d] != s[i-d+1]) break;
            if((d-1)*2 > maxl){
                maxl = (d-1)*2;
                maxpos = i-d+2;
            }
            // cout<<maxpos<<" "<<maxl<<endl;
        }
        return s.substr(maxpos, maxl);
    }
};

int main(){

    Solution sl;
    // string s = "cbbd";
    // string s = "babad";
    string s = "cbbabbc";

    string ans = sl.longestPalindrome(s);
    cout<<ans<<endl;


    return 0;
}