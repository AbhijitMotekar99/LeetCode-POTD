class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long totalSubarrays = 0;
        int n = nums.size();
        int left = 0;

        // Use multiset to maintain the range of elements in the window
        std::multiset<int> window;

        for (int right = 0; right < n; ++right) {
            // Add the current element to the multiset
            window.insert(nums[right]);

            // Ensure the condition |max - min| <= 2
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }

            // Add the number of valid subarrays ending at 'right'
            totalSubarrays += (right - left + 1);
        }

        return totalSubarrays;
    }
};
