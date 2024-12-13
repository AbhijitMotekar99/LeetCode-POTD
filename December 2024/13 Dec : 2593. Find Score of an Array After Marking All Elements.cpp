class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        // Priority queue to store elements and their indices (min-heap by value and index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Fill the priority queue
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // Boolean array to track marked elements
        vector<bool> marked(n, false);

        // Process the priority queue
        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();

            // If the element is already marked, skip it
            if (marked[index]) continue;

            // Add the value to the score
            score += value;

            // Mark the element and its adjacent ones
            marked[index] = true;
            if (index > 0) marked[index - 1] = true;
            if (index < n - 1) marked[index + 1] = true;
        }

        return score;
    }
};
