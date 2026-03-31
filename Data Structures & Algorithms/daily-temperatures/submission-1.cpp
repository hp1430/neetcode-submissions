class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<pair<int, int>>st;
        for(int i=nums.size()-1; i>=0; i--) {
            // if larger, pop
            while(!st.empty() && nums[i]>=st.top().first) st.pop();

            // put top in ans
            if(st.empty()) ans[i]=0;
            else ans[i] = st.top().second-i;

            // push current in stack
            st.push({nums[i], i});
        }
        return ans;
    }
};
