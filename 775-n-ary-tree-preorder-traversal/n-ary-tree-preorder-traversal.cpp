class Solution {
public:
    void traverse(Node* root, vector<int>& result)
    {
        if(root==nullptr)
        {
            return;
        }

        result.push_back(root->val);

        for(Node* child: root->children)
        {
            traverse(child,result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>result;
        traverse(root,result);
        return result;
    }
};