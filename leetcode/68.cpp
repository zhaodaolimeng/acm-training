#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ret, line;
        string ts;
        int total_w = 0, slot_cnt = 0, space_cnt, space_rem;
        
        for(int i=0; i<words.size();){
            line.clear();
            total_w = words[i].size();
            line.push_back(words[i]);
            i++;

            while(i<words.size() && 
                total_w + 1 + words[i].size() <= maxWidth) {
                total_w += 1 + words[i].size();
                line.push_back(words[i]);
                i++;
            }

            // for(int j=0; j<line.size(); j++) cout<<line[j]<<" ";
            // cout<<endl;

            ts = line[0];
            if(i == words.size()){
                for(int j=1; j<line.size(); j++)
                    ts += " " + line[j];
                ts += gen_spaces(maxWidth - ts.size());
            }else{
                if(line.size() == 1){
                    ts += gen_spaces(maxWidth - ts.size());
                }else{
                    slot_cnt = line.size() - 1;
                    space_cnt = (maxWidth - total_w + slot_cnt);
                    space_rem = space_cnt%slot_cnt;

                    // cout<<total_w<<" "<<space_cnt<<" "<<space_rem<<" "<<endl;

                    if(space_rem == 0){
                        for(int j=1; j<line.size(); j++)
                            ts += gen_spaces(space_cnt/slot_cnt) + line[j];
                    }else{
                        for(int j=1; j<=space_rem; j++)
                            ts += gen_spaces(space_cnt/slot_cnt + 1) + line[j];
                        for(int j=1+space_rem; j<line.size(); j++)
                            ts += gen_spaces(space_cnt/slot_cnt) + line[j];
                    }
                }
            }
            ret.push_back(ts);
        }
        return ret;
    }

    string gen_spaces(int n){
        string ret = "";
        for(int i=0; i<n; i++) ret += " ";
        return ret;
    }
};

int main(){
    Solution sl;

    // string arr[] = {"This", "is", "an", "example", "of", "text", "justification."};
    // vector<string> words(arr, arr+7);
    // int maxw = 16;

    string arr[] = {"What","must","be","acknowledgment","shall","be"};
    vector<string> words(arr, arr+6);
    int maxw = 16;

    vector<string> ret = sl.fullJustify(words, maxw);

    for(int i=0; i<ret.size(); i++)
        cout<<ret[i]<<endl;
    
    // cout<<endl;
}
