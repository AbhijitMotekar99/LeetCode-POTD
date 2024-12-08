#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Initialize variables
        int n = events.size();
        vector<int> maxValue(n, 0); // maxValue[i]: max value of events from 0 to i
        int result = 0;

        // Populate maxValue array
        maxValue[0] = events[0][2];
        for (int i = 1; i < n; ++i) {
            maxValue[i] = max(maxValue[i - 1], events[i][2]);
        }

        // Iterate through each event and calculate the max sum
        for (int i = 0; i < n; ++i) {
            int currentValue = events[i][2];
            // Binary search for the latest non-overlapping event
            int lo = 0, hi = i - 1, best = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][1] < events[i][0]) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            // If a non-overlapping event is found, add its value
            if (best != -1) {
                currentValue += maxValue[best];
            }
            // Update the global result
            result = max(result, currentValue);
        }

        return result;
    }
};
