class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // 分别计算nums1和nums2的中位数
        // 在小元素的前部和大元素的后部找到最小的那段，切掉
        // 重复上面的过程

        int l1,r1,mid1,l2,r2,mid2,t;
        l1 = l2 = 0;
        r1 = nums1.size()-1;
        r2 = nums2.size()-1;
        double ret;

        while(l1<=r1-1 && l2<=r2-1){
            mid1 = (l1+r1)/2;
            mid2 = (l2+r2)/2;
            if(nums1[mid1] == nums2[mid2]){
                ret = nums1[mid1];
                break;
            }
            if(l1 == r1-1){
                if(nums2.size()%2 == 0)
                    ret = 1.0*(nums2[mid2]+nums2[mid2])/2;
                else
                    ret = 1.0*nums2[mid2];
            }
            if(l2 == r2 - 1){
                if(nums1.size()%2 == 0)
                    ret = 1.0*(nums1[mid1]+nums1[mid1])/2;
                else
                    ret = 1.0*nums1[mid1];
            }
            if(nums1[mid1]<nums2[mid2]){
                t = min(mid1,r2-mid2);
                l1 = t;
                r2 = r2 - t;
            }else if(nums1[mid1]>nums2[mid2]){
                t = min(mid2,r2-mid1);
                l2 = t;
                r1 = r1 - t;
            }

        }
        return ret;
    }
};