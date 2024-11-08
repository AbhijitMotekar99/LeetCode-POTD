class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int allones = (1 << maximumBit) - 1;
        int xorAll = 0;

        for(int num : nums){
            xorAll ^= num;
        }

        vector<int> result(nums.size());
        for(int i=nums.size()-1; i>=0; --i){
            result[nums.size()-1-i] = xorAll ^ allones;
            xorAll ^= nums[i];
        }

        return result;
    }
};
