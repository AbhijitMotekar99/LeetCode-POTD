class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Deque for 0-1 BFS
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        
        // Distance matrix initialized to a large value
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            // Explore all 4 directions
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first;
                int ny = y + directions[d].second;

                // Check bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + (grid[x][y] == d + 1 ? 0 : 1);
                    
                    // Update cost if the new cost is better
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        if (grid[x][y] == d + 1) {
                            dq.push_front({nx, ny}); // No cost, add to front
                        } else {
                            dq.push_back({nx, ny}); // Cost of 1, add to back
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
