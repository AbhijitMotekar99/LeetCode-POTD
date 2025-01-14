class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> seenA, seenB; // Track elements seen in A and B
        vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            // Add the current elements of A and B to their respective sets
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            // Count the common elements in the intersection of seenA and seenB
            int commonCount = 0;
            for (int x : seenA) {
                if (seenB.count(x)) {
                    ++commonCount;
                }
            }

            // Store the common count at index i
            result[i] = commonCount;
        }

        return result;
    }
};
