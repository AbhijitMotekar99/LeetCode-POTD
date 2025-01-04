class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccurrence(26, -1); // First occurrence of each letter
        vector<int> lastOccurrence(26, -1);  // Last occurrence of each letter
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (firstOccurrence[s[i] - 'a'] == -1) {
                firstOccurrence[s[i] - 'a'] = i;
            }
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        int result = 0;

        for (int ch = 0; ch < 26; ch++) {
            int first = firstOccurrence[ch];
            int last = lastOccurrence[ch];
            
            if (first != -1 && last != -1 && last - first > 1) {
                unordered_set<char> middleChars;
                for (int i = first + 1; i < last; i++) {
                    middleChars.insert(s[i]);
                }
                result += middleChars.size();
            }
        }

        return result;
    }
};
