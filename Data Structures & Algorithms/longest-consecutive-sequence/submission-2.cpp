class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int>s(nums.begin(), nums.end());
        for(int x : s) {
            if(s.find(x-1)==s.end()) {
                int curr = x;
                int length = 1;
                while(s.find(x+1)!=s.end()) {
                    length++;
                    x++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};
