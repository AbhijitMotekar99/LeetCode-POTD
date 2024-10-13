class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue to keep track of the smallest element in the window
        // Each element in the heap will be a tuple (value, row, col)
        using Element = tuple<int, int, int>;
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        
        int maxVal = INT_MIN;
        int start = 0, end = INT_MAX;

        // Insert the first element from each list into the heap
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]); // Track the maximum element in the initial window
        }

        // Process the heap until we can't find a valid window
        while (true) {
            auto [minVal, row, col] = minHeap.top(); // Get the smallest element
            minHeap.pop();

            // Check if we have a smaller range
            if (maxVal - minVal < end - start) {
                start = minVal;
                end = maxVal;
            }

            // Move to the next element in the current list
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                minHeap.push({nextVal, row, col + 1});
                maxVal = max(maxVal, nextVal); // Update the maximum element in the current window
            } else {
                // If we've exhausted one of the lists, we can't find any more valid ranges
                break;
            }
        }

        return {start, end};
    }
};
