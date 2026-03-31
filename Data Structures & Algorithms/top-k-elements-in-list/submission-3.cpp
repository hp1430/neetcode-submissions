class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        vector<vector<int>>bucket(nums.size()+1);
        for(auto ele : m) {
            bucket[ele.second].push_back(ele.first);
        }
        vector<int>ans;
        for(int i=nums.size(); i>0, ans.size()<k; i--) {
            for(int x : bucket[i]) {
                ans.push_back(x);
                if(ans.size()>=k) break;
            }
        }
        return ans;
    }
};
