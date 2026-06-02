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
private:
    int total_tilt = 0;
    int calculateSumAndTilt(TreeNode* node)
    {
        if(node==nullptr)
        {
            return 0;
        }
        int leftSum = calculateSumAndTilt(node->left);
        int rightSum = calculateSumAndTilt(node->right);

        total_tilt = total_tilt+std::abs(leftSum-rightSum);

        return leftSum+rightSum+node->val;
    }
     
public:
    int findTilt(TreeNode* root) {
        total_tilt=0;
        calculateSumAndTilt(root);
        return total_tilt;
    }
};