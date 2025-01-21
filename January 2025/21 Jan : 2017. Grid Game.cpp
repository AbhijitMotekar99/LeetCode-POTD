class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        // Prefix sums for row 0 and row 1
        vector<long long> prefixRow0(n + 1, 0), prefixRow1(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixRow0[i + 1] = prefixRow0[i] + grid[0][i];
            prefixRow1[i + 1] = prefixRow1[i] + grid[1][i];
        }
        
        long long result = LLONG_MAX;

        // Iterate through each column to calculate the score for the second robot
        for (int i = 0; i < n; ++i) {
            // Points left on top row after the first robot crosses column `i`
            long long top = prefixRow0[n] - prefixRow0[i + 1];
            // Points left on bottom row before the first robot reaches column `i`
            long long bottom = prefixRow1[i];
            
            // The second robot will take the maximum of the points left
            result = min(result, max(top, bottom));
        }
        
        return result;
    }
};
