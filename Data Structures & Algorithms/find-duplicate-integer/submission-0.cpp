class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()) {
            int correctIdx = nums[i]-1;
            if(i==correctIdx) i++;
            else if(nums[i]==nums[correctIdx]) return nums[i];
            else swap(nums[i], nums[correctIdx]);
        }
        return -1;
    }
};
