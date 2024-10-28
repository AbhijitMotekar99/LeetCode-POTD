class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        
        // Insert all elements into a set for quick lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int maxStreak = 1; // At least one number as single streak
        
        for (int num : nums) {
            int currentNum = num;
            int streakLength = 0;
            
            // Check for a streak
            while (numSet.find(currentNum) != numSet.end()) {
                streakLength++;
                
                // Check for overflow before squaring
                if (currentNum > 316) break; // 316^2 = 99856, close to 10^5 limit
                
                // Square the current number safely
                currentNum *= currentNum;
            }
            
            // Update the max streak length
            maxStreak = max(maxStreak, streakLength);
        }
        
        // If the maximum streak found is less than 2, return -1 (no valid streak)
        return maxStreak >= 2 ? maxStreak : -1;
    }
};
