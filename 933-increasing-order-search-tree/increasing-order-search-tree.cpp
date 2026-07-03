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
    TreeNode* head = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;

        // 1. Traverse the left subtree
        inorder(node->left);

        // 2. Process the current node
        if (!head) {
            head = node; // The leftmost node becomes the new root
        } else {
            prev->right = node; // Link the previous node to the current one
        }
        node->left = nullptr; // Set left child to nullptr as required
        prev = node;          // Move the prev pointer forward

        // 3. Traverse the right subtree
        inorder(node->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return head;
    }
};