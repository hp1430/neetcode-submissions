class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = -1;
        int lo=0, hi=nums.size()-1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>nums[nums.size()-1]) lo = mid+1;
            else {
                ans = nums[mid];
                hi=mid-1;
            }
        }
        return ans;
    }
};
