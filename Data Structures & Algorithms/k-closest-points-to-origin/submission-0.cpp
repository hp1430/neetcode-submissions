#define pp pair<float, vector<int>>

class Solution {
public:
    float distance(vector<int>points) {
        int sq1 = points[0]*points[0];
        int sq2 = points[1]*points[1];
        return sqrt(sq1+sq2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp, vector<pp>, greater<pp>>pq;
        for(int i=0; i<points.size(); i++) pq.push({distance(points[i]), points[i]});
        vector<vector<int>>ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
