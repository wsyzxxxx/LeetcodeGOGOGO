class TweetCounts {
private:
    std::unordered_map<std::string, std::multiset<int> > mp;
    std::string day = "day";
    std::string hour = "hour";
public:
    TweetCounts() {
        mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].insert(time);
        //std::sort(mp[tweetName].begin(), mp[tweetName].end());
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (mp[tweetName].empty()) {
            return {0};
        }
        std::multiset<int> & arr = mp[tweetName];
        std::vector<int> res;
        //std::sort(arr.begin(), arr.end());
        int interval = 60;
        if (freq == "hour") {
            interval = 3600;
        }
        if (freq == "day") {
            interval = 86400;
        }
        
        auto it = arr.begin();
        while (it != arr.end() && *it < startTime) {
            it++;
        }
        
        while (startTime <= endTime) {
            int currCount = 0;
            while (it != arr.end() && *it < std::min(startTime + interval, endTime+1)) {
                currCount++;
                it++;
            }
            res.push_back(currCount);
            startTime += interval;
        }
        
        // if (res.empty()) {
        //     res.push_back(0);
        // }
        return res;
    }
};
// class TweetCounts {
//     map<string,multiset<int>> m;
//     vector<int> ans;
// public:
//     TweetCounts() {
//         m.clear();
//     }
    
//     void recordTweet(string tweetName, int time) {
//         m[tweetName].insert(time);
//     }
    
//     vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
//         std::cout << freq << " " << tweetName << " " << startTime << " " << endTime << std::endl;
//         multiset<int>::iterator it,it1;
//         int d,l,r,s;
//         if(freq=="minute")d=60;
//         else if(freq=="hour")d=3600;
//         else if(freq=="day")d=86400;
//         else exit(0);
//         ans.clear();
//         for(l=startTime,it=m[tweetName].lower_bound(l),it1=m[tweetName].end();l<=endTime;l+=d)
//         {
//             r=min(l+d-1,endTime);
//             for(s=0;it!=it1&&*it<=r;it++)s++;
//             ans.push_back(s);
//         }
//         return ans;
//     }
// };
/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
