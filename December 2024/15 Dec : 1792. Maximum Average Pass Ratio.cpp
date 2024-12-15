class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-Heap to store {gain, passi, totali}
        auto gain = [](const vector<int>& cls) {
            int passi = cls[0], totali = cls[1];
            return (double)(passi + 1) / (totali + 1) - (double)passi / totali;
        };

        priority_queue<pair<double, vector<int>>> maxHeap;
        for (const auto& cls : classes) {
            maxHeap.push({gain(cls), cls});
        }

        // Assign extra students
        while (extraStudents--) {
            auto [currGain, cls] = maxHeap.top();
            maxHeap.pop();

            // Update the class with one more passing student
            cls[0]++;
            cls[1]++;
            maxHeap.push({gain(cls), cls});
        }

        // Compute the final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, cls] = maxHeap.top();
            maxHeap.pop();
            totalRatio += (double)cls[0] / cls[1];
        }

        return totalRatio / classes.size();
    }
};
