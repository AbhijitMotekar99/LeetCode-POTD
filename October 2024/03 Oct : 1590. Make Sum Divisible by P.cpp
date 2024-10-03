class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum % p;
        if (target == 0) {
            return 0;
        }
        
        unordered_map<int, int> remainderIndexMap;
        remainderIndexMap[0] = -1; 
        long long currentPrefixSum = 0;
        int minLen = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            currentPrefixSum += nums[i];
            int currentRemainder = currentPrefixSum % p;
            
            if (currentRemainder < 0) currentRemainder += p;
            
            int requiredRemainder = (currentRemainder - target + p) % p;
            
            if (remainderIndexMap.find(requiredRemainder) != remainderIndexMap.end()) {
                int subarrayLength = i - remainderIndexMap[requiredRemainder];
                minLen = min(minLen, subarrayLength);
            }
            
            remainderIndexMap[currentRemainder] = i;
        }
        
        return (minLen == nums.size()) ? -1 : minLen;
    }
};
