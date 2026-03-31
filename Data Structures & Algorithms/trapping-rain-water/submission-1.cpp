class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int>pre(nums.size()), suff(nums.size());
        int maxi = 0;
        for(int i=0; i<nums.size(); i++) {
            pre[i]=maxi;
            if(nums[i]>maxi) maxi=nums[i];
        }
        maxi=0;
        for(int i=nums.size()-1; i>=0; i--) {
            suff[i]=maxi;
            if(nums[i]>maxi) maxi=nums[i];
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int temp = min(pre[i], suff[i])-nums[i];
            if(temp>0) ans += temp;
        }
        return ans;
    }
};
