class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        int count = 0;
        
        for(int i : nums){
            maxOR |= i;
        }

        int n = nums.size();
        
        for(int mask = 1; mask < (1 << n); mask++) {
            int currentOr = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }

            if(currentOr == maxOR){
                count++;
            }
        }
        return count;
    }
};
