class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> userTweets;
    unordered_map<int, unordered_set<int>> followings;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        // max heap: {time, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        // ensure user follows themselves
        followings[userId].insert(userId);

        for(auto user : followings[userId]) {
            auto &tweets = userTweets[user];
            if(!tweets.empty()) {
                int idx = tweets.size() - 1;
                pq.push({tweets[idx].first, tweets[idx].second, user, idx});
            }
        }

        while(!pq.empty() && ans.size() < 10) {
            auto top = pq.top(); pq.pop();

            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            ans.push_back(tweetId);

            if(idx > 0) {
                auto &tweets = userTweets[user];
                pq.push({tweets[idx-1].first, tweets[idx-1].second, user, idx-1});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followings[followerId].erase(followeeId);
        }
    }
};