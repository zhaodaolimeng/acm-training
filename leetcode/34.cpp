#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        nums.insert(nums.begin(), -(1<<30));
        nums.push_back((1<<30));
        int a=-1,b=-1,mid;
        int l=0,r=nums.size()-1;

        // first
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid]<target && mid+1<nums.size() && nums[mid+1]>target){
                break;
            }else if(nums[mid]<target && mid+1<nums.size() && nums[mid+1]==target){
                a = mid+1;
                break;
            }else if(nums[mid]>=target){
                r = mid-1;
            }else if(mid+1<nums.size() && nums[mid+1]<target){
                l = mid+1;
            }else{
                l = mid;
            }
        }

        // last
        l=0,r=nums.size()-1;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid]<target && mid+1<nums.size() && nums[mid+1]>target){
                break;
            }else if(nums[mid]==target && mid+1<nums.size() && nums[mid+1]>target){
                b = mid;
                break;
            }else if(nums[mid]>target){
                r = mid-1;
            }else if(mid+1<nums.size() && nums[mid+1]<=target){
                l = mid+1;
            }else{
                l = mid;
            }
        }

        if(a==-1){
            a = 0;
            b = 0;
        }
        vector<int> ret = {a-1,b-1};
        return ret;
    }
};


int main(){
    Solution sl;
    vector<int> nums = {7,7,8,8,10};
    int target = 7;
    vector<int> ret = sl.searchRange(nums,target);
    cout<<ret[0]<<" "<<ret[1]<<endl;
    return 0;
}