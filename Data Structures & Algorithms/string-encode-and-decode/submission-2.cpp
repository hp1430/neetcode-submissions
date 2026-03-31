class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs.size(); i++) {
            ans += to_string(strs[i].size())+'#'+strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string>ans;
        while(i<s.size()) {
            int found = s.find('#', i);
            int len = stoi(s.substr(i, found-i));
            string content = s.substr(found+1, len);
            ans.push_back(content);
            i=found+1+len;
        }
        return ans;
    }
};
