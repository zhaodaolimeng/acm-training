#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {

        vector<vector<int> > ret;

        sort(nums.begin(),nums.end());
        int p,q,t,pp;

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i]+nums[j]>target) continue;
                p = j+1;
                q = nums.size()-1;
                t = target - nums[i]-nums[j];

                pp = -1;
                while(p<q){
                    if(nums[p]+nums[q] == t){
                        if(p != pp){
                            cout<<nums[i]<<"\t"<<nums[j]<<"\t"<<nums[p]<<"\t"<<nums[q]<<endl;
                            
                            pp = p;
                        }
                        q--;
                    }else if(nums[p]+nums[q] > t){
                        q--;
                    }else{
                        p++;
                    }
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sl;

    vector<int> input;
    input.push_back(-5);
    input.push_back(-4);
    input.push_back(-3);
    input.push_back(1);

    sl.fourSum(input,-11);

}
