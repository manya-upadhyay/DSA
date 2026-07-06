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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current_sum) {
        if (node == nullptr) {
            return 0;
        }

        current_sum = (current_sum << 1) | node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return current_sum;
        }

        return dfs(node->left, current_sum) + dfs(node->right, current_sum);
    }
};