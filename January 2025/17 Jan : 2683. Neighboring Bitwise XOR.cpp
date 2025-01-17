class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int totalXOR = 0;

        for (int val : derived) {
            totalXOR ^= val;
        }

        return totalXOR == 0;
    }
};
