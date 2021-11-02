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
   
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* root)
    {
        TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
        tmp->right= NULL;
        tmp->left= NULL;
        if(root==NULL)
            return;
        tmp->right = root->right;
        root->right = root->left;
        root->left = tmp->right;
        invertTree(root->left);
        invertTree(root->right);
    }
};