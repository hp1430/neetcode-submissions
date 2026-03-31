class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>m1, m2;
        for(int i=0; i<s1.size(); i++) m1[s1[i]]++;
        m2=m1;
        int i=0;
        int j=0;
        while(j<s2.size()) {
            if(m2.find(s2[j])!=m2.end()) {
                m2[s2[j]]--;
                if(m2[s2[j]]==0) m2.erase(s2[j]);
                if(m2.size()==0) return true;
                j++;
            }
            else {
                m2=m1;
                i++;
                j=i;
            }
        }
        return false;
    }
};
