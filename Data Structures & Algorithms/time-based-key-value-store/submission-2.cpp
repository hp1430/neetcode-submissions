class TimeMap {
    unordered_map<string, vector<pair<string, int>>>m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";
        vector<pair<string, int>>nums = m[key];
        int lo=0, hi=nums.size()-1;
        string ans = "";
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid].second==timestamp) return nums[mid].first;
            else if(nums[mid].second<timestamp) {
                ans = nums[mid].first;
                lo = mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};
