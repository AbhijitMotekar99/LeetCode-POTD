#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int backtrack(const string &s, int start, unordered_set<string> &uniqueSubstrings) {
        if (start == s.length()) {
            return 0;
        }
        
        int maxSplit = 0; 
        
        string currentSubstr;
        for (int i = start; i < s.length(); ++i) {
            currentSubstr += s[i];
            
            if (uniqueSubstrings.find(currentSubstr) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstr);
                
                int result = 1 + backtrack(s, i + 1, uniqueSubstrings);
                maxSplit = max(maxSplit, result);
                
                uniqueSubstrings.erase(currentSubstr);
            }
        }
        
        return maxSplit;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings; 
        return backtrack(s, 0, uniqueSubstrings);
    }
};
