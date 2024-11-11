class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> primes = sieveOfEratosthenes(max_num);
        
        int prev = 0;
        for (int num : nums) {
            // Find the largest prime p where num - p > prev
            auto it = upper_bound(primes.begin(), primes.end(), num - prev - 1);
            if (it != primes.begin()) {
                --it;
                num -= *it;
            }
            if (num <= prev) return false;
            prev = num;
        }
        
        return true;
    }
    
private:
    vector<int> sieveOfEratosthenes(int n) {
        vector<bool> is_prime(n + 1, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    }
};
