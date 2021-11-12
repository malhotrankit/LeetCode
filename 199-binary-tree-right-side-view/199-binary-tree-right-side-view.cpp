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

class Solution 
{
public:
    vector<int> v;
    vector<int> rightSideView(TreeNode* root) 
    {
        int i;
        view(root,0);
        return v;
    }
    void view(TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        
        if(level==v.size())
            v.push_back(root->val);
        view(root->right, level+1);
        view(root->left, level+1);
        
        
    }
};