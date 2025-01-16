class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;

        // If nums2.size() is odd, XOR all elements in nums1
        if (nums2.size() % 2 == 1) {
            for (int num : nums1) {
                result ^= num;
            }
        }

        // If nums1.size() is odd, XOR all elements in nums2
        if (nums1.size() % 2 == 1) {
            for (int num : nums2) {
                result ^= num;
            }
        }

        return result;
    }
};
