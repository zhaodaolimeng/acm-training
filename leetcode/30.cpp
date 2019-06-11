/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 * 
 * 因为所有词的长度都是相等的，所以可将全部长度根据词长度的mod进行遍历
 * iter1: |----|----|----|----
 * iter2: -|----|----|----|---
 * iter3: --|----|----|----|--
 */
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        deque<string> q;  // 存储词的ID，判定队列是否包含所有的词
        int t = 0;
        string ts;
        map<string, int> map_counter;
        map<string, int> words_counter;

        for(auto const& w: words){
            if(words_counter.find(w) == words_counter.end()){
                words_counter[w] = 1;
            }else
                words_counter[w] += 1;
        }

        if(words.size() == 0 || s.size() == 0) return ret;
        int wlen = words[0].length();
        if(s.size() < wlen*words.size()) return ret;
        
        
        for(int i=0; i<wlen; i++){
            t = i;
            // cout<<"-----"<<endl;
            while(t + wlen <= s.length()){
                ts = s.substr(t, wlen);
                t += wlen;
                // cout<<ts<<endl;
                if(words_counter.find(ts) == words_counter.end()){
                    q.clear();
                }else{
                    q.push_back(ts);
                    if(q.size() == words.size()){
                        map_counter.clear();
                        for(int i=0; i<q.size(); i++){
                            if(map_counter.find(q[i]) == map_counter.end())
                                map_counter[q[i]] = 1;
                            else
                                map_counter[q[i]] += 1;
                        }
                        bool counter_match = true;
                        // cout<<"-----"<<endl;
                        for(auto const& x: words_counter){
                            // cout<<x.first<<'\t'<<x.second<<endl;
                            if(map_counter.find(x.first) == map_counter.end() ||
                                map_counter[x.first]!=x.second){
                                counter_match = false;
                                break;
                            }
                        }
                        if(counter_match)
                            ret.push_back(t - wlen*words.size());
                        q.pop_front();
                    }
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sl;
    vector<string> v;

    // string s = "wordgoodgoodgoodbestword";
    // v.push_back("word");
    // v.push_back("good");
    // v.push_back("best");
    // v.push_back("good");

    // string s = "barfoothefoobarman";
    // v.push_back("foo");
    // v.push_back("bar");

    string s = "aaa";
    v.push_back("aa");
    v.push_back("aa");
    
    vector<int> ret = sl.findSubstring(s, v);
    cout<<"====="<<endl;
    for(int i=0; i<ret.size(); i++)
        cout<<ret[i]<<endl;
}

