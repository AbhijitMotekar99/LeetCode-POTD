class Solution {
public:
    char findKthBit(int n, int k) {
        // Helper function to recursively find the kth bit
        return findKthBitHelper(n, k);
    }

private:
    char findKthBitHelper(int n, int k) {
        if (n == 1) {
            // Base case: S1 is "0"
            return '0';
        }

        int length = (1 << n) - 1; // length of Sn is 2^n - 1
        int mid = (length / 2) + 1; // middle position

        if (k == mid) {
            // The middle element is always '1'
            return '1';
        } else if (k < mid) {
            // If k is in the first half, it's the same as in Sn-1
            return findKthBitHelper(n - 1, k);
        } else {
            // If k is in the second half, we map it to the first half and invert it
            int mirrorK = length - k + 1; // map to the mirrored position in the first half
            char mirroredBit = findKthBitHelper(n - 1, mirrorK);
            return (mirroredBit == '0') ? '1' : '0'; // invert the bit
        }
    }
};
