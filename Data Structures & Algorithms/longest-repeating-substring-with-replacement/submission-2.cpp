class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int maxFreq = 0;
        int i = 0;
        int ans = 0;
        for(int j=0; j<s.size(); j++) {
            // 1. include s[j]
            counts[s[j]-'A']++;

            // 2. update maxFreq
            maxFreq = max(maxFreq, counts[s[j]-'A']);

            // 3. check if window is invalid
            int length = j-i+1;
            if(length-maxFreq > k) {
                counts[s[i]-'A']--;
                i++;
            }

            // 4. update answer
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
