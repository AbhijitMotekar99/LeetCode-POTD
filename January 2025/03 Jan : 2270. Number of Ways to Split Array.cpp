class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // int n = nums.size();
        // long long Total_sum = 0;
        // int count = 0;

        // for(int num : nums){
        //     Total_sum += num;
        // }

        // long long left_sum = nums[0];
        // if(left_sum >= (Total_sum - left_sum)) count+=1;
        // else count = 0;

        // for(int i=1;i<n-1;i++){
        //     left_sum = left_sum + nums[i];
        //     long long right_sum = Total_sum - left_sum;
        //     if(left_sum >= right_sum){
        //         count++;
        //     }
        // }
        

        long long leftsum = 0, rightsum = 0;
        int count = 0;

        for(int num : nums){
            rightsum += num;
        }

        for(int i=0;i<nums.size()-1;i++){
            leftsum += nums[i];
            rightsum -= nums[i];

            if(leftsum >= rightsum) count++;
        }

        return count;
    }
};
