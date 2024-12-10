#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        // Start with the maximum length and decrease
        for (int len = n; len > 0; --len) {
            unordered_map<string, int> countMap;

            // Check all substrings of the current length
            for (int i = 0; i + len <= n; ++i) {
                string substring = s.substr(i, len);

                // Check if the substring is special
                if (isSpecial(substring)) {
                    countMap[substring]++;
                }
            }

            // Check if any substring of this length occurs at least 3 times
            for (auto& entry : countMap) {
                if (entry.second >= 3) {
                    return len;
                }
            }
        }

        return -1; // No special substring found
    }

private:
    // Helper function to check if a string is special
    bool isSpecial(const string& str) {
        for (char c : str) {
            if (c != str[0]) return false;
        }
        return true;
    }
};
