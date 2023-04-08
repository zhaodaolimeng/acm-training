#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ret,t,mid,p,q,diff;
        int min_diff = (1<<30);
        
        for(int i=0;i<nums.size();i++){

            for(int j=i+1;j<nums.size();j++){

                t = target - nums[i] - nums[j];
                p = j+1;
                q = nums.size()-1;

                while(p<q-1){
                    mid = (p+q)/2;
                    if(nums[mid] == t)break;
                    if(nums[mid]>t) q = mid;
                    else p = mid;
                }

                if(p<nums.size()){
                    diff = abs(t - nums[p]);
                    if(diff<min_diff) {
                        min_diff = diff;
                        ret = nums[i] + nums[j] + nums[p];
                    }
                }
                if(q>j){
                    diff = abs(t - nums[q]);
                    if(diff<min_diff) {
                        min_diff = diff;
                        ret = nums[i] + nums[j] + nums[q];
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
    input.push_back(-1);
    input.push_back(2);
    input.push_back(1);
    input.push_back(-4);

    cout<<sl.threeSumClosest(input,1)<<endl;

}
