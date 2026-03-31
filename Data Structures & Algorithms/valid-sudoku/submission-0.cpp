class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        unordered_map<int, unordered_set<char>>mr, mc, ms;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                char ele = nums[i][j];
                if(ele == '.') continue;
                int square = ((i/3)*3)+(j/3);
                if(mr[i].find(ele)!=mr[i].end()) return false;
                if(mc[j].find(ele)!=mc[j].end()) return false;
                if(ms[square].find(ele)!=ms[square].end()) return false;
                mr[i].insert(ele);
                mc[j].insert(ele);
                ms[square].insert(ele);
            }
        }
        return true;
    }
};