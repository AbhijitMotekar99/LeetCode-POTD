class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'U')); // U for unoccupied

        // Mark guards and walls on the grid
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G'; // G for guard
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W'; // W for wall
        }

        // Mark guarded cells
        auto markGuarded = [&](int x, int y, int dx, int dy) {
            while (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] == 'W' || grid[x][y] == 'G') break; // Stop at walls or other guards
                if (grid[x][y] == 'U') grid[x][y] = 'X'; // X for guarded
                x += dx;
                y += dy;
            }
        };

        for (const auto& guard : guards) {
            int x = guard[0], y = guard[1];
            markGuarded(x - 1, y, -1, 0); // North
            markGuarded(x + 1, y, 1, 0);  // South
            markGuarded(x, y - 1, 0, -1); // West
            markGuarded(x, y + 1, 0, 1);  // East
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'U') {
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};
