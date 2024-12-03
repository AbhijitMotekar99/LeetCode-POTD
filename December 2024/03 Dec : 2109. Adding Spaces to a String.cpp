class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.size(), m = spaces.size();
        int spaceIndex = 0, i = 0;

        while (i < n) {
            if (spaceIndex < m && i == spaces[spaceIndex]) {
                result += ' '; 
                spaceIndex++;  
            }
            result += s[i];
            i++;
        }
        
        return result;
    }
};
