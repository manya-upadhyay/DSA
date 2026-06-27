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
    bool isUnivalTree(TreeNode* root) {
        // An empty tree is vacuously uni-valued
        if (!root) return true;
        
        // Pass the root's value to the helper function to check all nodes
        return checkValue(root, root->val);
    }

private:
    bool checkValue(TreeNode* node, int target) {
        // If we reach a null child, it doesn't violate the rule
        if (!node) return true;
        
        // If the current node's value doesn't match the target, it's not uni-valued
        if (node->val != target) return false;
        
        // Recursively check both the left and right subtrees
        return checkValue(node->left, target) && checkValue(node->right, target);
    }
};