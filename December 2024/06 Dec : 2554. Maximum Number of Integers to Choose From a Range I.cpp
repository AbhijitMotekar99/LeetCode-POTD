class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Store banned numbers in a set for O(1) lookups
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        int count = 0;     // Number of valid integers chosen
        int currentSum = 0; // Current sum of chosen integers
        
        for (int i = 1; i <= n; ++i) {
            // If the number is not banned and can be added without exceeding maxSum
            if (bannedSet.find(i) == bannedSet.end() && currentSum + i <= maxSum) {
                currentSum += i; // Add the number to the sum
                count++;         // Increment the count
            }
        }
        
        return count;
    }
};
