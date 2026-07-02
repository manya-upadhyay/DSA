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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int minVal) {
        if (!node) return -1;
        
        if (node->val > minVal) {
            return node->val;
        }

        int leftRes = dfs(node->left, minVal);
        int rightRes = dfs(node->right, minVal);
    
        if (leftRes != -1 && rightRes != -1) {
            return min(leftRes, rightRes);
        }
        
        return leftRes != -1 ? leftRes : rightRes;
    }
};