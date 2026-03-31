class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>>dq;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++) {
            if(!dq.empty() && dq.front().first < i-k+1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=dq.back().second) {
                dq.pop_back();
            }
            pair<int, int>p;
            p.first=i;
            p.second=nums[i];
            dq.push_back(p);
            if(i-k+1 >= 0) ans.push_back(dq.front().second);
        }
        return ans;
    }
};
