#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/**
 * ref: https://leetcode.com/problems/word-ladder-ii/discuss/40434/
 *      C++-solution-using-standard-BFS-method-no-DFS-or-backtracking
 */
class Solution {
public:
    bool one_char_diff(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        int cnt = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) cnt ++;
            if(cnt == 2) break;
        }
        if(cnt == 1) return true;
        return false;
    }
    
    vector<vector<string> > findLadders(
        string beginWord, string endWord, vector<string>& wl) {
        
        unordered_set<string> wordList(wl.begin(), wl.end());
        vector<vector<string> > ret;
        
        queue<vector<string> > q;
        vector<string> vs;
        vs.push_back(beginWord);
        q.push(vs);
        
        queue<set<string> > qs; // 加速查询
        set<string> ss(vs.begin(), vs.end());
        qs.push(ss);
        
        map<string, vector<string> > adj;
        vector<string> vs0;
        for(string s : wordList)
            if(one_char_diff(beginWord, s))
                vs0.push_back(s);
        adj[beginWord] = vs0;
        
        for(string s1: wordList){
            vector<string> vst;
            for(string s2 : wordList)
                if(one_char_diff(s1, s2))
                    vst.push_back(s2);
            adj[s1] = vst;
        }

        unordered_set<string> visited; 
        int cur_len = 1, res_len = wordList.size() + 2;
        while(!q.empty()){
            vector<string> path = q.front(); q.pop();
            set<string> spath = qs.front(); qs.pop();

            if(path.size() >= res_len) break;
            if(path.size() > cur_len){
                for (string w : visited) wordList.erase(w);
                visited.clear();
                cur_len = path.size();
            }
            string last_s = path.back();
            
            for(string s : adj[last_s]){
                if(wordList.find(s) == wordList.end()) continue;
                if(spath.find(s) == spath.end()){
                    vector<string> nvs(path);
                    nvs.push_back(s);
                    visited.insert(s);
                    if(s == endWord){
                        if(res_len == wordList.size() + 2)
                            res_len = nvs.size();
                        ret.push_back(nvs);
                    }
                    q.push(nvs);
                    qs.push(set<string> (nvs.begin(), nvs.end()));
                }
            }
        }
        return ret;
    }
};

int main(){

    Solution sl;

    string beginWord = "hit";
    string endWord = "cog";
    string wl[] = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList(begin(wl), end(wl));
    vector<vector<string> > ret = sl.findLadders(beginWord, endWord, wordList);

    for(vector<string> vs : ret){
        for(string s : vs) cout<<s<<" ";
        cout<<endl;
    }
}