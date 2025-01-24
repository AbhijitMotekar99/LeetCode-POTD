class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Step 1: Reverse the graph
        vector<vector<int>> reversedGraph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reversedGraph[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        // Step 2: Topological sorting using a queue
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reversedGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Sort the result
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
