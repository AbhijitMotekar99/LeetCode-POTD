class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int totalSquares = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Only proceed if matrix[i][j] is 1 and it's not in the first row/column
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    // Update cell to be the min of the neighbors plus itself
                    matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                }
                // Add the value of this cell to the total count of squares
                totalSquares += matrix[i][j];
            }
        }
        
        return totalSquares;
    }
};
