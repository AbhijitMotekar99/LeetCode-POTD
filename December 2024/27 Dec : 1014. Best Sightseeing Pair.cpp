class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int m = values[0];

        for (int i = 1; i < values.size(); i++) {
            if (values[i] - i + m > ans) 
                ans = values[i] - i + m;
            
            if (values[i] + i > m) 
                m = values[i] + i;
        }

        return ans;
    }
};
