class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        
        unordered_set<int> travelDays(days.begin(), days.end());
        
        for (int i = 1; i <= 365; ++i) {
            if (travelDays.find(i) != travelDays.end()) {
                dp[i] = min({
                    dp[i-1] + costs[0],  // 1-day pass
                    dp[max(0, i-7)] + costs[1],  // 7-day pass
                    dp[max(0, i-30)] + costs[2]  // 30-day pass
                });
            } else {
                dp[i] = dp[i-1];
            }
        }
        
        return dp[365];
    }
};
