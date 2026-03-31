class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++) {
            int ele = nums[i];
            if(s.find(ele)!=s.end()) return true;
            s.insert(ele);
        }
        return false;
    }
};