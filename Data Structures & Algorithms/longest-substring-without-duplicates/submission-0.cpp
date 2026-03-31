class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;;
        int ans = 0;
        int i=0, j=0;
        while(j<s.size()) {
            if(st.find(s[j])==st.end()) {
                // not present in set
                st.insert(s[j]);
                int length = j-i+1;
                ans = max(ans, length);
                j++;
            }
            else {
                // present in set
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
