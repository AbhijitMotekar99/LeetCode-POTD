class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        // Traverse both strings
        while (i < n || j < n) {
            // Skip blanks in start
            while (i < n && start[i] == '_') i++;
            // Skip blanks in target
            while (j < n && target[j] == '_') j++;

            // If one string ends but the other doesn't, they can't match
            if ((i < n) != (j < n)) return false;

            // If both have reached the end, strings match
            if (i == n && j == n) return true;

            // Check if the characters differ
            if (start[i] != target[j]) return false;

            // Verify movement constraints
            if (start[i] == 'L' && i < j) return false; // 'L' cannot move right
            if (start[i] == 'R' && i > j) return false; // 'R' cannot move left

            // Move to the next character
            i++;
            j++;
        }

        return true;
    }
};
