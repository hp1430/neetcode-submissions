class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<string>str = s;
        vector<vector<string>>ans;
        unordered_map<string, vector<int>>m;
        for(int i=0; i<s.size(); i++) {
            sort(s[i].begin(), s[i].end());
            m[s[i]].push_back(i);
        }
        for(auto ele : m) {
            vector<int>arr = ele.second;
            vector<string>temp;
            for(int i=0; i<arr.size(); i++) {
                temp.push_back(str[arr[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
