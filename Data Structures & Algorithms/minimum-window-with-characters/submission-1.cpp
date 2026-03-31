class Solution {
public:
    string minWindow(string s, string t) {
        int ans = INT_MAX, cnt = 0, idx=-1;
        int hash[256] = {0};
        for(int i=0; i<t.size(); i++) hash[t[i]]++;
        int l = 0, r = 0;
        while(r<s.size()) {
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==t.size()) {
                if(r-l+1 < ans) {
                    ans = r-l+1;
                    idx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return idx==-1 ? "" : s.substr(idx, ans);
    }
};
