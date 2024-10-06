class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> countS1(26, 0), countWindow(26, 0);

        for (char c : s1) {
            countS1[c - 'a']++;
        }

        for (int i = 0; i < n1; i++) {
            countWindow[s2[i] - 'a']++;
        }

        if (countS1 == countWindow) return true;

        for (int i = n1; i < n2; i++) {
            countWindow[s2[i] - 'a']++;
            countWindow[s2[i - n1] - 'a']--;

            if (countS1 == countWindow) return true;
        }

        return false;
    }
};
