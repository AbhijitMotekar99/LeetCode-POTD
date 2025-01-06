class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);

        int balls = 0;
        int operations = 0; 
        for (int i = 0; i < n; ++i) {
            result[i] += operations;
            balls += (boxes[i] == '1') ? 1 : 0;
            operations += balls;
        }

        balls = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += operations;
            balls += (boxes[i] == '1') ? 1 : 0;
            operations += balls;
        }

        return result;
    }
};
