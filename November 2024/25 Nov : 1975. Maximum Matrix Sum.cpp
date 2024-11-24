class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        // Traverse the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = matrix[i][j];
                totalSum += abs(value); // Add absolute value to total sum
                if (value < 0) negativeCount++; // Count negative numbers
                minAbsValue = min(minAbsValue, abs(value)); // Track smallest absolute value
            }
        }

        // If negative count is even, all negatives can be flipped
        if (negativeCount % 2 == 0) {
            return totalSum;
        }
        
        // If negative count is odd, one smallest absolute value remains negative
        return totalSum - 2 * minAbsValue;
    }
};
