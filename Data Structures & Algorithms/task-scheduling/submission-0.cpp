class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // push frequencies into max heap
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push(freq[i]);
        }

        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;

                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            // check if any task is ready from cooldown
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};