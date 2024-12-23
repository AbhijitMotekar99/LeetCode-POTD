class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        // Helper to calculate minimum swaps to sort an array
        auto minSwapsToSort = [](vector<int>& arr) {
            int n = arr.size();
            vector<pair<int, int>> indexedArr(n);
            for (int i = 0; i < n; i++) {
                indexedArr[i] = {arr[i], i};
            }
            
            // Sort based on the values
            sort(indexedArr.begin(), indexedArr.end());
            
            vector<bool> visited(n, false);
            int swaps = 0;
            
            // Count cycles
            for (int i = 0; i < n; i++) {
                if (visited[i] || indexedArr[i].second == i) continue;

                int cycleSize = 0;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = indexedArr[j].second;
                    cycleSize++;
                }
                if (cycleSize > 1) {
                    swaps += cycleSize - 1;
                }
            }
            
            return swaps;
        };

        // BFS to collect levels
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Calculate minimum swaps for this level
            totalSwaps += minSwapsToSort(levelValues);
        }

        return totalSwaps;
    }
};
