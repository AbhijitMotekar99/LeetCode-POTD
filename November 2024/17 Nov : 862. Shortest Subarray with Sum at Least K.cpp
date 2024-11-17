class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0); // Prefix sum array
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq; // Stores indices of the prefix sum
        int minLen = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            // Check if we can form a valid subarray
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front(); // Remove the front as it's no longer useful
            }

            // Maintain increasing order in the deque
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back(); // Remove the back as it's no longer useful
            }

            dq.push_back(i); // Add the current index
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};



// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int currsum = 0;
//         int minsize = INT_MAX;
//         int n = nums.size();
        
//         for(int i=0;i<nums.size();i++){
//             currsum = 0;
//             for(int j=i;j<nums.size();j++){
//                 currsum += nums[j];

//                 if(currsum >= k){
//                     minsize = min(minsize,j-i+1);
//                     break;
//                 }
//             }
//         }

//         return minsize == INT_MAX ? -1 : minsize;
//     }
// };

