class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        // Build the graph and track degrees
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Find the start node
        int start = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outDegree[node] > inDegree[node]) {
                start = node;
                break;
            }
        }

        // Perform Hierholzer's algorithm to find the Eulerian path
        vector<int> path;
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int node = stk.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stk.push(next);
            } else {
                path.push_back(node);
                stk.pop();
            }
        }

        reverse(path.begin(), path.end());

        // Reconstruct the arrangement
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};
