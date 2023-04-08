#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int> > ret;
        int i,p,q,pre;
        
        for(i=0;i<nums.size();i++){

            p = i+1;
            q = nums.size()-1;
            pre = -999999;

            while(p<q){
                if(nums[p]+nums[q] == -nums[i]){
                    if(nums[p] != pre){
                        vector<int> r;
                        r.push_back(nums[i]);
                        r.push_back(nums[p]);
                        r.push_back(nums[q]);
                        ret.push_back(r);

                        pre = nums[p];
                    }
                } else if(nums[p]+nums[q]>-nums[i]){
                    q--;
                }else {
                    p++;
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sl;

    vector<int> input;
    input.push_back(-1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);
    input.push_back(-1);
    input.push_back(-4);

    sl.threeSum(input);

}
