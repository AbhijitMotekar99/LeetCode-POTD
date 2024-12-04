class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int j = 0; // Pointer for str2

        for (int i = 0; i < n && j < m; ++i) {
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
                ++j; // Move to the next character in str2
            }
        }

        // If we have matched all characters of str2, return true
        return j == m;
    }
};
