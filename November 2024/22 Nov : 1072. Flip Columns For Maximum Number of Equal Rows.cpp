class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> rowCount;
        int maxRows = 0;

        for (auto& row : matrix) {
            string canonicalForm = "";
            for (int j = 0; j < row.size(); ++j) {
                canonicalForm += (row[j] == row[0] ? '0' : '1');
            }
            rowCount[canonicalForm]++;
            maxRows = max(maxRows, rowCount[canonicalForm]);
        }

        return maxRows;
    }
};
