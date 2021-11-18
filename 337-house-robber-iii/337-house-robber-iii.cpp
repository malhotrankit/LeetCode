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

//int maxi=0;
class Solution 
{
public:
    int rob(TreeNode* root) 
    {
        pair<int,int> r = robb(root);
        return max(r.first,r.second);
    }
    
    pair<int,int> robb(TreeNode* root)
    {
        if(root == NULL)
            return make_pair(0,0);
        
        pair<int,int> p = robb(root->left);
        pair<int,int> q = robb(root->right);
        
        return make_pair(root->val+p.second+q.second,max(p.first,p.second)+max(q.first,q.second));
        
    }
    
};