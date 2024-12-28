class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(3, 0);

        vector<int> sum(n - k + 1, 0);
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            if (i >= k) currSum -= nums[i - k];
            if (i >= k - 1) sum[i - k + 1] = currSum;
        }

        vector<int> left(n - k + 1, 0);
        int bestLeft = 0;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > sum[bestLeft]) {
                bestLeft = i;
            }
            left[i] = bestLeft;
        }

        vector<int> right(n - k + 1, 0);
        int bestRight = sum.size() - 1;
        for (int i = sum.size() - 1; i >= 0; i--) {
            if (sum[i] >= sum[bestRight]) { // Use >= to prefer smaller indices
                bestRight = i;
            }
            right[i] = bestRight;
        }

        int maxSum = 0;
        for (int mid = k; mid < sum.size() - k; mid++) {
            int leftIdx = left[mid - k];
            int rightIdx = right[mid + k];
            int totalSum = sum[leftIdx] + sum[mid] + sum[rightIdx];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {leftIdx, mid, rightIdx};
            }
        }

        return result;
    }
};
