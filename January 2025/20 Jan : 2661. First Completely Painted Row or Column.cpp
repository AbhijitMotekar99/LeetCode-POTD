class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();     // Number of rows
        int n = mat[0].size();  // Number of columns
        int total = m * n;      // Total elements in the matrix

        // Step 1: Map each value in the matrix to its position
        unordered_map<int, pair<int, int>> valuePosition;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                valuePosition[mat[i][j]] = {i, j};
            }
        }

        // Step 2: Track painted rows and columns
        vector<int> rowCount(m, 0); // Counts painted cells in each row
        vector<int> colCount(n, 0); // Counts painted cells in each column

        // Step 3: Process arr to paint cells
        for (int i = 0; i < total; ++i) {
            int value = arr[i];
            auto [row, col] = valuePosition[value];

            // Paint the cell
            rowCount[row]++;
            colCount[col]++;

            // Check if the row or column is fully painted
            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }

        return -1; // Should never reach here since a solution is guaranteed
    }
};
