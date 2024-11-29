class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;

        // Compute the total sum of the array
        for (int num : arr) {
            totalSum += num;
        }

        // If totalSum is not divisible by 3, splitting is impossible
        if (totalSum % 3 != 0) {
            return {-1, -1};
        }

        long long target = totalSum / 3;
        long long currentSum = 0;
        int firstIndex = -1, secondIndex = -1;

        // Find the first and second partitions
        for (int i = 0; i < n; i++) {
            currentSum += arr[i];

            // Find the first partition
            if (firstIndex == -1 && currentSum == target) {
                firstIndex = i;
            }
            // Find the second partition
            else if (firstIndex != -1 && currentSum == 2 * target) {
                secondIndex = i;
                break;
            }
        }

        // If valid partitions are found, return the indices
        if (firstIndex != -1 && secondIndex != -1) {
            return {firstIndex, secondIndex};
        }

        // Otherwise, splitting is not possible
        return {-1, -1};
    }
};
