class Solution {
private:
    vector<string> bfs(int start, map<int, vector<string>>& watchVideos, map<int, vector<int>>& friends, int level) {
        vector<string> result;                 
        unordered_set<int> visited;           
        queue<int> q;                         

        visited.insert(start);                
        q.push(start);

        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();

            if (currentLevel == level) {
                for (int i = 0; i < size; i++) {
                    int friendId = q.front();
                    q.pop();

                    for (string& video : watchVideos[friendId]) {
                        result.push_back(video);
                    }
                }
                return result; 
            }

            for (int i = 0; i < size; i++) {
                int friendId = q.front();
                q.pop();

                for (int neighbor : friends[friendId]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            currentLevel++; 
        }

        return result; 
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        map<int, vector<string>> watchVideos; 
        for (int i = 0; i < watchedVideos.size(); i++) {
            watchVideos[i] = watchedVideos[i];
        }

        map<int, vector<int>> friendMap; 
        for (int i = 0; i < friends.size(); i++) {
            friendMap[i] = friends[i];
        }

        vector<string> result = bfs(id, watchVideos, friendMap, level);

        unordered_map<string, int> freq;
        for (const string& video : result) {
            freq[video]++;
        }

        vector<pair<string, int>> freqList(freq.begin(), freq.end());
        sort(freqList.begin(), freqList.end(), [](pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second < b.second; 
        });

        vector<string> sortedResult;
        for (auto& entry : freqList) {
            sortedResult.push_back(entry.first);
        }

        return sortedResult;
    }
};
