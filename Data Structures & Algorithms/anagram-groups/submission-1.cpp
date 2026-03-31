class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        for(string s : strs) {
            vector<int>freq(26, 0);
            for(char c : s) {
                freq[c - 'a']++;
            }
            string key = "";
            for(int k : freq) {
                key += '#' + to_string(k);
            }
            m[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto ele : m) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};
