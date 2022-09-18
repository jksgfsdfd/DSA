class Twitter {
    int tweet_num;
    unordered_map<int,vector<pair<int,int>>> tweets_of_user;
    unordered_map<int,unordered_set<int>> follow_list;
public:
    
    
    Twitter() {
        tweet_num=0;    
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_num++;
        tweets_of_user[userId].push_back({tweet_num,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count=0;
        //compare the tweets from followee and self and find max 10 tweet_num
        //make map of index in each list
        unordered_map<int,int> index_map;
        unordered_set<int> compare_users = follow_list [userId];
        compare_users.insert(userId);
        priority_queue<pair<int,int>> heap;
        for(int user : compare_users){
            if(tweets_of_user.find(user)==tweets_of_user.end()){
                continue;
            }
            int index = tweets_of_user[user].size()-1;
            index_map[user]=index;
            heap.push({tweets_of_user[user][index].first,user});
        }
        vector<int>ans;
        while(count<10 && !heap.empty()){
            int user=heap.top().second;
            int tweet_index = index_map[user];
            int tweetId = tweets_of_user[user][tweet_index].second;
            ans.push_back(tweetId);
            if(index_map[user]==0){
                heap.pop();
                index_map.erase(user);
            }else{
                index_map[user]--;
                tweet_index = index_map[user];
                heap.pop();
                heap.push({tweets_of_user[user][tweet_index].first,user});
            }
            count++;
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        follow_list[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_list[followerId].erase(followeeId);
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
