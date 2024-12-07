class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary search boundaries
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if penalty `mid` is feasible
            if (canDivide(nums, maxOperations, mid)) {
                result = mid; // Update result to the current feasible penalty
                right = mid - 1; // Search for a smaller penalty
            } else {
                left = mid + 1; // Search for a larger penalty
            }
        }

        return result;
    }

private:
    // Helper function to check if penalty is feasible
    bool canDivide(const vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;

        for (int balls : nums) {
            // Count operations needed for this bag
            if (balls > penalty) {
                operations += (balls - 1) / penalty; // Equivalent to ceil(balls / penalty) - 1
            }

            // If operations exceed maxOperations, return false
            if (operations > maxOperations) return false;
        }

        return true;
    }
};
