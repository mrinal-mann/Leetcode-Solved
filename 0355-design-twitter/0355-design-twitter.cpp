#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Twitter {
private:
    struct Tweet {
        int id, time;
        Tweet(int i, int t) : id(i), time(t) {}
    };

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<Tweet>> tweets;
    int timestamp;

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp++);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> followeeList = followers[userId];
        followeeList.insert(userId); // Include self-tweets

        for (int followee : followeeList) {
            auto &tw = tweets[followee];
            for (int i = max(0, (int)tw.size() - 10); i < tw.size(); ++i) {
                pq.emplace(tw[i].time, tw[i].id);
            }
        }

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};