class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> elements;
        long long currsum = 0, maxsum = 0;
        int start = 0;

        for(int end = 0;end<nums.size();end++){
            while(elements.count(nums[end])){
                elements.erase(nums[start]);
                currsum -= nums[start];
                start++;
            }

            elements.insert(nums[end]);
            currsum += nums[end];

            if(end-start+1 > k){
                elements.erase(nums[start]);
                currsum -= nums[start];
                start++;
            }

            if(end-start+1 == k){
                maxsum = max(maxsum, currsum);
            }
        }

        return maxsum;

    }
};
