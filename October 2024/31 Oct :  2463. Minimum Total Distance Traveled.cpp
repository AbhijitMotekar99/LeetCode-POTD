class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());
        
        int n = robot.size();
        int m = factory.size();
        
        // Define a high value without causing overflow
        long long INF = std::numeric_limits<long long>::max();
        
        // DP array to store the minimum distance
        std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1, INF));
        dp[0][0] = 0;  // Base case: no distance if no robots and factories
        
        for (int j = 1; j <= m; ++j) {  // Loop over factories
            dp[j][0] = 0;  // No robots to repair, cost is 0
            for (int i = 1; i <= n; ++i) {  // Loop over robots
                dp[j][i] = dp[j - 1][i];  // Initial value: skip current factory
                long long cost = 0;
                for (int r = 1; r <= std::min(i, factory[j - 1][1]); ++r) {
                    // Cumulative cost of moving r robots to this factory
                    cost += std::abs(factory[j - 1][0] - robot[i - r]);
                    if (dp[j - 1][i - r] != INF) {
                        dp[j][i] = std::min(dp[j][i], dp[j - 1][i - r] + cost);
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
