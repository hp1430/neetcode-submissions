bool cmp(pair<int, int>&a, pair<int, int>&b) {
    return a.first < b.first;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>nums;
        for(int i=0; i<position.size(); i++) nums.push_back({position[i], speed[i]});
        sort(nums.begin(), nums.end(), cmp);
        stack<double>st;
        for(int i=0; i<nums.size(); i++) {
            double ele = (double(target-nums[i].first)/double(nums[i].second));
            cout<<ele<<endl;
            while(!st.empty() && st.top()<=ele) st.pop();
            st.push(ele);
        }
        return st.size();
    }
};
