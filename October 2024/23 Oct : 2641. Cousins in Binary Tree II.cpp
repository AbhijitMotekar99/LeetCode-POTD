/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        
        // BFS approach to process each level
        queue<TreeNode*> q;
        q.push(root);
        
        root->val = 0;  // Root has no cousins, set it to 0
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            vector<TreeNode*> levelNodes;
            
            // Collect all nodes at this level and calculate the level sum
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                levelNodes.push_back(node);
                if (node->left) {
                    q.push(node->left);
                    levelSum += node->left->val;
                }
                if (node->right) {
                    q.push(node->right);
                    levelSum += node->right->val;
                }
            }
            
            // Now we have the sum of the current level and the nodes at this level.
            // Let's calculate cousin sums for each node
            for (auto node : levelNodes) {
                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;
                
                // Set the cousin sum for left child
                if (node->left) {
                    node->left->val = levelSum - siblingSum;
                }
                
                // Set the cousin sum for right child
                if (node->right) {
                    node->right->val = levelSum - siblingSum;
                }
            }
        }
        
        return root;
    }
};
