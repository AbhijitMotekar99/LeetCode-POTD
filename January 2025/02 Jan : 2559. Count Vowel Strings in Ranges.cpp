class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        int n = words.size();
        vector<int> prefix(n, 0);

        for (int i = 0; i < n; ++i) {
            char first = words[i][0];
            char last = words[i][words[i].size() - 1];
            int isVowelString = (vowels.count(first) > 0 && vowels.count(last) > 0) ? 1 : 0;

            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + isVowelString;
        }

        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            if (l > 0) {
                result.push_back(prefix[r] - prefix[l - 1]);
            } else {
                result.push_back(prefix[r]);
            }
        }

        return result;
    }
};
