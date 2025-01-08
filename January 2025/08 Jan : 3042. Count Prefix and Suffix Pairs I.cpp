class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();

        auto isPrefixAndSuffix = [](const string& str1, const string& str2) -> bool {
            int len1 = str1.length(), len2 = str2.length();
            if (len1 > len2) return false; 
            return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};
