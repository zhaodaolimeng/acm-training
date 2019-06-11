#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int start = 0, end = 0, c, k = 0, k_size = 0;
        string ret = s;
        vector<int> t_cnt(100), s_cnt(100);

        for(int i=0; i<t.size(); i++){
            c = t[i]-'A';
            if(t_cnt[c] == 0) k_size++;
            t_cnt[c] ++;
        }
        
        for(int i=0; i<s.size(); i++) s_cnt[s[i]-'A']++;

        for(int i=0; i<100; i++){
            if(t_cnt[i]>s_cnt[i]) return "";
            s_cnt[i] = 0;
        }

        k = 0;
        c = s[end]-'A';
        s_cnt[c] ++;
        if(t_cnt[c] > 0 && s_cnt[c] == t_cnt[c]) k++;

        while(end < s.size()){
            for(; start<end; start++){

                // for(int i=0;i<26;i++) cout<<s_cnt[i]<<" ";
                // cout<<s.substr(start, end-start+1)<<endl;

                c = s[start]-'A';
                s_cnt[c]--;
                if(s_cnt[c] < t_cnt[c]){
                    k --;
                    if(end-start+1<ret.size())
                        ret = s.substr(start, end-start+1);
                    start++;
                    break;
                }
            }
            cout<<start<<" "<<end<<" "<<ret<<endl;
            // cout<<"-------"<<endl;

            for(end += 1; end<s.size(); end++){

                // for(int i=0;i<26;i++) cout<<s_cnt[i]<<" ";
                // cout<<endl;

                c = s[end]-'A';
                s_cnt[c]++;
                if(t_cnt[c] > 0 && s_cnt[c] == t_cnt[c]){
                    k++;
                    // end++;
                    if(k == k_size) break;
                }
            }
            // cout<<start<<" "<<end<<" "<<ret<<endl;
            // cout<<"========"<<endl;
        }
        return ret;
    }
};

int main(){
    Solution sl;
    // string s = "ADOBECODEBANC";
    // string t = "ABC";

    // string s = "a";
    // string t = "b";

    string s = "cabwefgewcwaefgcf";
    string t = "cae";

    for(int i=0; i<s.size(); i++) cout<<i<<"\t";
    cout<<endl;
    for(int i=0; i<s.size(); i++) cout<<s[i]<<"\t";
    cout<<endl;

    string ret = sl.minWindow(s, t);
    cout<<ret<<endl;
}
