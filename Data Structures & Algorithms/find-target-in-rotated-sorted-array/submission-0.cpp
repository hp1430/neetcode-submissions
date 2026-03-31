class Solution {
public:
    int binarySearch(vector<int>&nums, int lo, int hi, int target) {
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) {
            if(nums[0]==target) return 0;
            else return -1;
        }
        int lo=0, hi=nums.size()-1, p=-1;
        bool flag=true;
        if(nums[lo]<=nums[hi]) {
            p=0;
            flag=false;
        }
        while(flag && lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(mid<nums.size()-1 && nums[mid]>nums[mid+1]) {
                p=mid+1;
                break;
            }
            else if(mid>0 && nums[mid]<nums[mid-1]) {
                p=mid;
                break;
            }
            else if(mid==0 || nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid-1;
        }
        if(target>=nums[p] && target<=nums[nums.size()-1]) return binarySearch(nums, p, nums.size()-1, target);
        else return binarySearch(nums, 0, p-1, target);
        return -1;
    }
};