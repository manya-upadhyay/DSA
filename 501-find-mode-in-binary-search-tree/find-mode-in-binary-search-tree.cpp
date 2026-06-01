class Solution {
public:
    int curr_freq=0;
    int curr_Num=0;
    int max_freq=0;
    vector<int>res;

    void dfs(TreeNode*root)
    {
        if(!root)
        {
            return;

        }
        dfs(root->left);
        if(root->val==curr_Num)
        {
            curr_freq++;
        }
        else
        {
            curr_Num= root->val;
            curr_freq=1;
        }
        if(curr_freq>max_freq)
        {
            res={};
            max_freq = curr_freq;
        }
        if(curr_freq==max_freq)
        {
            res.push_back(root->val);
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        
        dfs(root);
        return res;
    }
};