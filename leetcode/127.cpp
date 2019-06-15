#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        if(dict.count(endWord) == 0) return 0;
        
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int ret = 0;
        
        while(!q.empty()){
            ret ++;
            for(int size = q.size(); size > 0; size--){
                string s = q.front(); q.pop();
                for(int i=0; i<s.size(); i++){
                    string ts=s;
                    for(char c='a'; c<='z'; c++){
                        ts[i] = c;
                        if(dict.count(ts) != 0 && visited.count(ts) == 0){
                            if(ts == endWord) return ret + 1;
                            visited.insert(ts);
                            q.push(ts);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main(){

    Solution sl;

    string beginWord = "hit";
    string endWord = "cog";
    string wl[] = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList(begin(wl), end(wl));
    int ret = sl.ladderLength(beginWord, endWord, wordList);
    cout<<ret<<endl;
}