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
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double>result;
        if(!root)
        {
            return result;
        }

        std::queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            double levelSum =0;

            for(int i=0; i<levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                levelSum = levelSum+curr->val;

                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }

            }
            result.push_back(levelSum/levelSize);
        }
        return result;
    }
};