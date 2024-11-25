class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += to_string(board[i][j]);
            }
        }
        
        // Goal state
        string goal = "123450";
        
        // Neighbor mapping for each index of 0
        vector<vector<int>> neighbors = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };
        
        // BFS initialization
        queue<pair<string, int>> q; // Pair of board state and number of moves
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [state, moves] = q.front();
            q.pop();
            
            // Check if we reached the goal
            if (state == goal) return moves;
            
            // Find the index of 0
            int zeroIndex = state.find('0');
            
            // Explore all neighbors
            for (int neighbor : neighbors[zeroIndex]) {
                string newState = state;
                swap(newState[zeroIndex], newState[neighbor]);
                if (visited.find(newState) == visited.end()) {
                    q.push({newState, moves + 1});
                    visited.insert(newState);
                }
            }
        }
        
        // If we exit the loop, no solution is possible
        return -1;
    }
};
