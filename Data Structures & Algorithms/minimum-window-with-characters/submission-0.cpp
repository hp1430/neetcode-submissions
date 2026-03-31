class Solution {
public:
    string minWindow(string s, string t) {
        int hash[128] = {0};   // 🔴 CHANGED: use 128 instead of 58 (safer for full ASCII)

        int minLen = INT_MAX, index = -1;
        int count = 0;
        int l = 0, r = 0;

        for(int i = 0; i < t.size(); i++) 
            hash[t[i]]++;     // 🔴 CHANGED: no need for -'A' when using 128

        while(r < s.size()) {

            hash[s[r]]--;     // 🔴 CHANGED: always decrement (even if extra)

            if(hash[s[r]] >= 0)   // 🔴 CHANGED: check >= 0 instead of > 0
                count++;

            while(count == t.size()) {   // 🔴 CHANGED: moved outside any if-condition

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    index = l;
                }

                hash[s[l]]++;   // restore character

                if(hash[s[l]] > 0)   // 🔴 CHANGED: count-- (not count++)
                    count--;

                l++;
            }

            r++;
        }

        return index == -1 ? "" : s.substr(index, minLen);
    }
};
