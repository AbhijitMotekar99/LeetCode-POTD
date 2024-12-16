class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while(k > 0){
            int min = INT_MAX;
            int ind = 0;
            for(int i=0;i<n;i++){
                if(nums[i] < min){
                    min = nums[i];
                    ind = i;
                }
            }

            nums[ind] = min * multiplier;

            k--;
        }
        return nums;
    }
};
