class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        // Step 1: Build the difference array
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }
        
        // Step 2: Calculate the prefix sum to get net shifts
        int netShift = 0;
        for (int i = 0; i < n; i++) {
            netShift += diff[i];
            diff[i] = netShift; // Now `diff[i]` represents the net shift at index `i`
        }
        
        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26; // Keep the shift within [0, 25]
            if (shift < 0) shift += 26; // Handle negative shifts
            s[i] = (s[i] - 'a' + shift) % 26 + 'a'; // Apply the shift
        }
        
        return s;
    }
};
