class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m1[26]={0};
        int m2[26]={0};
        for(int i=0; i<s1.size(); i++) m1[s1[i]-'a']++;
        int i=0, j=0;
        int match=0;
        while(j<s2.size()) {
            if(m1[s2[j]-'a']==0) {
                if(i==j) {
                    j++;
                    i=j;
                }
                else {
                    if(m2[s2[i]-'a']==m1[s2[i]-'a']) match-=m1[s2[i]-'a'];
                    m2[s2[i]-'a']--;
                    i++;
                }
            }
            else if(m1[s2[j]-'a']>0 && m2[s2[j]-'a']<m1[s2[j]-'a']) {
                m2[s2[j]-'a']++;
                if(m2[s2[j]-'a']==m1[s2[j]-'a']) match+=m1[s2[j]-'a'];
                j++;
            }
            else if(m2[s2[j]-'a']>=m1[s2[j]-'a']) {
                if(m2[s2[i]-'a']==m1[s2[i]-'a']) match-=m1[s2[i]-'a'];
                m2[s2[i]-'a']--;
                i++;
            }
            if(match==s1.size()) return true;
        }
        return false;
    }
};
