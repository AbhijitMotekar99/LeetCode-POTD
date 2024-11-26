class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        
        // Build the graph and calculate in-degrees
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        // Use Kahn's algorithm to find nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        // If more than one node has in-degree 0, there is no unique champion
        if (q.size() != 1) return -1;
        
        int candidate = q.front();
        q.pop();
        
        // Check if the candidate is reachable from all other nodes
        vector<bool> visited(n, false);
        queue<int> bfsQueue;
        bfsQueue.push(candidate);
        visited[candidate] = true;
        
        while (!bfsQueue.empty()) {
            int node = bfsQueue.front();
            bfsQueue.pop();
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        // If all nodes are visited, the candidate is the champion
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && i != candidate) return -1;
        }
        
        return candidate;
    }
};
