class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes;  // Store nodes at the current level
            
            // Process current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);

                // Add children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse values at odd levels
            if (level % 2 == 1) {
                int left = 0, right = nodes.size() - 1;
                while (left < right) {
                    swap(nodes[left]->val, nodes[right]->val);
                    ++left;
                    --right;
                }
            }

            ++level;
        }

        return root;
    }
};
