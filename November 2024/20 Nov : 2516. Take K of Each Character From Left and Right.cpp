class Solution {
public:
    int takeCharacters(string s, int k) {
        // Step 1: Count total frequency of each character
        int n = s.size();
        vector<int> total(3, 0); // Frequency of 'a', 'b', 'c'

        for (char c : s) {
            total[c - 'a']++;
        }

        // Step 2: Check if it's possible to have at least k of each character
        if (total[0] < k || total[1] < k || total[2] < k) {
            return -1;
        }

        // Step 3: Sliding window to find the longest valid substring
        vector<int> current(3, 0); // Frequency of 'a', 'b', 'c' in the current window
        int maxWindowSize = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            // Add the current character to the window
            current[s[r] - 'a']++;

            // Ensure the window is valid
            while (current[0] > total[0] - k || 
                   current[1] > total[1] - k || 
                   current[2] > total[2] - k) {
                current[s[l] - 'a']--;
                l++;
            }

            // Update the maximum window size
            maxWindowSize = max(maxWindowSize, r - l + 1);
        }

        // Step 4: Calculate the minimum time needed
        return n - maxWindowSize;
    }
};
