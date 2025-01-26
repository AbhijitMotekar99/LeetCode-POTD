class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> visited(n, -1); // To track visited nodes and their depth
        vector<int> indegree(n, 0); // To calculate indegree of each node
        
        // Step 1: Calculate indegrees
        for (int i = 0; i < n; ++i) {
            indegree[favorite[i]]++;
        }
        
        // Step 2: Process nodes with zero indegree (chains leading to cycles)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        // To track the length of chains
        vector<int> chainLength(n, 0);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int next = favorite[curr];
            chainLength[next] = max(chainLength[next], chainLength[curr] + 1);
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
        
        // Step 3: Detect cycles and calculate maximum size
        int maxCycleSize = 0, mutualPairsSum = 0;
        visited.assign(n, -1); // Reset visited array
        
        for (int i = 0; i < n; ++i) {
            if (indegree[i] > 0) { // Part of a cycle
                int cycleSize = 0;
                int curr = i;
                while (visited[curr] == -1) {
                    visited[curr] = i;
                    curr = favorite[curr];
                    cycleSize++;
                }
                // If the cycle is of size 2, add chains
                if (cycleSize == 2) {
                    mutualPairsSum += 2 + chainLength[i] + chainLength[favorite[i]];
                } else {
                    maxCycleSize = max(maxCycleSize, cycleSize);
                }
            }
        }
        
        // Step 4: Return the maximum of mutual pairs and the largest cycle
        return max(maxCycleSize, mutualPairsSum);
    }
};
