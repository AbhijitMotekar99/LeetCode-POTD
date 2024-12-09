#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityMismatch(n - 1, 0);

        // Step 1: Compute parityMismatch array
        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                parityMismatch[i] = 1;
            }
        }

        // Step 2: Compute prefix sum of parityMismatch
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + (i - 1 < parityMismatch.size() ? parityMismatch[i - 1] : 0);
        }

        // Step 3: Process each query
        vector<bool> result;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];

            // Check the range [from, to-1] in parityMismatch
            if (to - 1 >= from) {
                int mismatches = prefixSum[to] - prefixSum[from];
                result.push_back(mismatches == 0);
            } else {
                // Single element subarray is always special
                result.push_back(true);
            }
        }

        return result;
    }
};
