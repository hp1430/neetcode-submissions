class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++) m[nums[i]] = INT_MIN;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int length = 1;
            int n = nums[i]-1;
            while(m.find(n)!=m.end()) {
                if(m[n]!=INT_MIN) {
                    length += m[n];
                    break;
                }
                else {
                    length++;
                    n--;
                }
            }
            ans = max(ans, length);
        }
        return ans==INT_MIN?0:ans;
    }
};