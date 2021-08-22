#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    void search(int n, int lb, int rb, string pre, vector<string> &ret){
        if(lb == n) {
            for(int i=0; i<(n-rb); i++) pre += ")";
            ret.push_back(pre);
            return;
        }
        if(lb < n) 
            search(n, lb+1, rb, pre+"(", ret);
        if(lb > rb) 
            search(n, lb, rb+1, pre+")", ret);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        search(n, 0, 0, "", ret);
        return ret;
    }
};

int main(){
    Solution sl;
    vector<string> ret = sl.generateParenthesis(3);
    for(auto s : ret){
        cout<<s<<"\t";
    }
    cout<<endl;
}
