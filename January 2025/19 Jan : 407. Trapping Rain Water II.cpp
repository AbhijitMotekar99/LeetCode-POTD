class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        
        if (m < 3 || n < 3) return 0; // No water can be trapped if dimensions are less than 3x3

        // Min-Heap to store {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Push all boundary cells into the heap
        for (int i = 0; i < m; i++) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    minHeap.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int waterTrapped = 0;

        // Process cells in the heap
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int height = curr[0], x = curr[1], y = curr[2];
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                // Check bounds and whether the cell is visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Water trapped is determined by the difference between the current boundary and the neighbor height
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    // Push the neighbor into the heap with the updated boundary height
                    minHeap.push({max(height, heightMap[nx][ny]), nx, ny});
                }
            }
        }
        
        return waterTrapped;
    }
};
