class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        
        auto canDistribute = [&](int x) -> bool {
            int requiredStores = 0;
            for (int quantity : quantities) {
                requiredStores += (quantity + x - 1) / x;  
                if (requiredStores > n) return false;
            }
            return requiredStores <= n;
        };
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
