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
 /*
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>>nodes;
        dfs(root, 0,0,nodes);

        sort(nodes.begin(),nodes.end());

        vector<vector<int>>res;
        int prevCol = INT_MIN;
        
        for(auto[col,row,val]:nodes)
        {
            if(col!=prevCol)
            {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }
        return res;
    }

    void dfs(TreeNode* node, int row, int col, vector<tuple<int,int,int>>&nodes)
    {
        if(!node)
        {
            return;
        }
        nodes.emplace_back(col,row,node->val);
        dfs(node->left,row+1,col-1,nodes);
        dfs(node->right,row+1,col+1,nodes);
    }
};

*/


//second method

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>>temp=q.front();
            q.pop();
            TreeNode*frontNode=temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);
            if(frontNode->left)
            {
               q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }

      for(auto i : nodes)
        {
            vector<int> col;

            for(auto j : i.second)
            {
                sort(j.second.begin(), j.second.end());

                for(auto k : j.second)
                {
                    col.push_back(k);
                }
            }

            ans.push_back(col);
        }
        return ans;
    }
};