#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<pair<int, int>> arrivalTimes;
        for (int i = 0; i < n; ++i) {
            arrivalTimes.push_back({times[i][0], i});
        }
        
        sort(arrivalTimes.begin(), arrivalTimes.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); 
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingFriends;
        
        for (const auto& [arrivalTime, friendIdx] : arrivalTimes) {
            while (!leavingFriends.empty() && leavingFriends.top().first <= arrivalTime) {
                availableChairs.push(leavingFriends.top().second);
                leavingFriends.pop();
            }
            
            int assignedChair = availableChairs.top();
            availableChairs.pop();
            
            if (friendIdx == targetFriend) {
                return assignedChair;
            }
            
            leavingFriends.push({times[friendIdx][1], assignedChair});
        }
        
        return -1; 
    }
};
