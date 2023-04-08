#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                if(nums[l]<nums[r]){
                    l = mid + 1;
                }else{
                    if(target >= nums[l]){
                        if(nums[mid] <= nums[r])
                            r = mid - 1;
                        else
                            l = mid + 1;
                    }else
                        l = mid + 1;
                }
            }else{
                if(nums[l]<nums[r]){
                    r = mid - 1;
                }else{
                    if(target <= nums[r]){
                        if(nums[mid] >= nums[l])
                            l = mid + 1;
                        else
                            r = mid - 1;
                    }else
                        r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,8,1,2,3};
    int target = 1;

    Solution sl;
    cout<<sl.search(nums,target)<<endl;;
    return 0;
}