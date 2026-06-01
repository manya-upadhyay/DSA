class Solution {
private:
    TreeNode* prev = nullptr;
    int curr_cnt = 0;
    int max_cnt = 0;
    vector<int> modes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev == nullptr) {
            curr_cnt = 1;
        } else if (root->val == prev->val) {
            curr_cnt++;
        } else {
            curr_cnt = 1;
        }
        if (curr_cnt > max_cnt) {
            max_cnt = curr_cnt;
            modes = {root->val}; 
        } else if (curr_cnt == max_cnt) {
            modes.push_back(root->val); 
        }
        prev = root;
        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        prev = nullptr;
        curr_cnt = 0;
        max_cnt = 0;
        modes.clear();
        
        inorder(root);
        return modes;
    }
};