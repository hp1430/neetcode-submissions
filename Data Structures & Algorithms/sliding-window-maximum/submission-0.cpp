class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>>pq;
        vector<int>ans;
        int i=0, j=0;
        while(j<nums.size()) {
            pq.insert(nums[j]);
            if(pq.size()==k) {
                ans.push_back(*pq.begin());
                pq.erase(pq.find(nums[i]));
                i++;
            }
            j++;
        }
        return ans;
    }
};
