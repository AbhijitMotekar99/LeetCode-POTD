class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // Maximum frequency for each character across all words in words2

        // Step 1: Calculate max frequency of each character in words2
        for (string word : words2) {
            vector<int> freq(26, 0); // Frequency of characters in the current word
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> result;

        // Step 2: Check each word in words1
        for (string word : words1) {
            vector<int> freq(26, 0); // Frequency of characters in the current word
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) { // Does not satisfy the frequency requirement
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
