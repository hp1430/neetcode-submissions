class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        for(int i=0; i<nums.size(); i++) {
            int target = 0-nums[i];
            unordered_set<int>s;
            for(int j=i+1; j<nums.size(); j++) {
                vector<int>temp;
                if(s.find(target-nums[j])!=s.end()) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(target-nums[j]);
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>>ansv;
        for(vector<int> x : ans) ansv.push_back(x);
        return ansv;
    }
};
