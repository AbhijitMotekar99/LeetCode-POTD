class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Function to perform DFS and use memoization
        function<int(int, int)> dfs = [&](int row, int col) -> int {
            if (col == n - 1) return 0; // Last column, no more moves possible
            if (dp[row][col] != -1) return dp[row][col];
            
            int maxMoves = 0;
            vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
            
            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < m && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                    maxMoves = max(maxMoves, 1 + dfs(newRow, newCol));
                }
            }
            
            return dp[row][col] = maxMoves;
        };
        
        int result = 0;
        for (int row = 0; row < m; ++row) {
            result = max(result, dfs(row, 0));
        }
        
        return result;
    }
};
