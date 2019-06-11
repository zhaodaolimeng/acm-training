#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(
        vector<int>& candidates, int target) {
        vector<vector<int> > ret = solve(candidates, 0, target);

        for(int i=0; i<ret.size(); i++)
            sort(ret[i].begin(), ret[i].end());
        
        vector<vector<int> > ret_dedup;
        for(int i=0; i<ret.size(); i++){
            bool find = false;
            for(int j=0; j<ret_dedup.size(); j++){
                // ret[i] ret_dedup[j]
                if(ret[i].size() == ret_dedup[j].size()){
                    bool same = true;
                    for(int k=0; k<ret_dedup.size(); k++){
                        if(ret[i][k] != ret_dedup[j][k]){
                            same = false;
                            break;
                        }
                    }
                    if(same){
                        find = true;
                        break;
                    }
                }
            }
            if(!find)
                ret_dedup.push_back(ret[i]);
        }
        return ret_dedup;
    }

    vector<vector<int> > solve(vector<int>& candidates, int n, int target){
        if(n == candidates.size()){
            vector<vector<int> > ret;
            if(target == 0){
                vector<int> path;
                ret.push_back(path);
            }
            return ret;
        }
        vector<vector<int> > ret1 = solve(candidates, n+1, target-candidates[n]);
        for(int i=0; i<ret1.size(); i++)
            ret1[i].push_back(candidates[n]);
        vector<vector<int> > ret2 = solve(candidates, n+1, target);
        for(int i=0; i<ret2.size(); i++)
            ret1.push_back(ret2[i]);
        return ret1;
    }
};

int main(){
    Solution sl;

    // int arr[] = {10,1,2,7,6,1,5};
    // int target = 8;
    // vector<int> candidates(arr, arr + 7);

    int arr[] = {2,5,2,1,2};
    int target = 5;
    vector<int> candidates(arr, arr + 5);
    
    // for(int i=0; i<candidates.size(); i++){
    //     cout<<candidates[i]<<endl;
    // }

    vector<vector<int> > ret = sl.combinationSum2(candidates, target);
    // cout<<ret.size()<<endl;
    for(int i=0; i<ret.size(); i++){
        // cout<<ret[i].size()<<endl;
        for(int j=0;j<ret[i].size(); j++){
            cout<<ret[i][j]<<' ';
        }
        cout<<endl;
    }

}
