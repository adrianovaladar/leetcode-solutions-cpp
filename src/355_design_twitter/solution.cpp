class Twitter {
    std::unordered_map<int, std::unordered_set<int>> followMap;
    std::unordered_map<int, std::vector<std::pair<int,int>>> userPosts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        static int time {};
        userPosts[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto users = followMap[userId];
        users.insert(userId);
        std::vector<std::pair<int, int>> postsByUser;
        for (const auto &user : users) {
            postsByUser.insert(postsByUser.end(), userPosts[user].begin(), userPosts[user].end());
        }
        std::sort(postsByUser.begin(), postsByUser.end(), [] (const auto &val1, const auto &val2) {return val1 > val2;});
        std::vector<int> answer;
        int index {};
        for (const auto &post: postsByUser) {
            answer.emplace_back(post.second);
            index++;
            if (index == 10) break;
        }
        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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
