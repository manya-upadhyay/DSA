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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            bool foundX = false;
            bool foundY = false;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                // Check if current node's children are x and y (Same Parent Condition)
                if (curr->left && curr->right) {
                    if ((curr->left->val == x && curr->right->val == y) ||
                        (curr->left->val == y && curr->right->val == x)) {
                        return false; // Siblings, not cousins
                    }
                }
                
                // Track if we find x or y at the current level
                if (curr->val == x) foundX = true;
                if (curr->val == y) foundY = true;
                
                // Push children to the queue for the next level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            
            // If both are found at the same level, they are cousins
            if (foundX && foundY) return true;
            
            // If only one is found at this level, they can't be cousins (different depths)
            if (foundX || foundY) return false;
        }
        
        return false;
    }
};