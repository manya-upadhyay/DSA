class Twitter {

private:
    int time;
    unordered_map<int, unordered_set<int>>mp; //followers list
    unordered_map<int, vector<pair<int,int>>>mp2; //tweet id with time

public:
    Twitter() {
       time=0;    
    }
    
    void postTweet(int userId, int tweetId) {
        mp2[userId].emplace_back(time,tweetId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto i : mp2[userId])
        {
            pq.push(i);
        }
        for(auto i: mp[userId])
        {
            for(auto j : mp2[i])
            {
                pq.push(j);
            }
        }

        vector<int>feed;
        int cnt=10;
        while(!pq.empty() && cnt)
        {
            feed.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */