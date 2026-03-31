class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int nsi[nums.size()], psi[nums.size()];
        stack<int>st;
        for(int i=nums.size()-1; i>=0; i--) {
            while(!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            st.empty() ? nsi[i]=nums.size() : nsi[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            st.empty() ? psi[i]=-1 : psi[i]=st.top();
            st.push(i);
        }
        int ans = -1;
        for(int i=0; i<nums.size(); i++) {
            ans = max(ans, nums[i]*(nsi[i]-psi[i]-1));
        }
        return ans;
    }
};
