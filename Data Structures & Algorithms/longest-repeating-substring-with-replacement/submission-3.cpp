class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int maxFreq = 0;
        int ans = 0;
        int l=0, r=0;
        while(r<s.size()) {
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);
            if(r-l+1-maxFreq > k) {
                hash[s[l]-'A']--;
                l++;
            }
            else {
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};
