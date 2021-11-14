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
    int count = 0, value;
    int kthSmallest(TreeNode* root, int k) 
    {
        inorder(root,k);
        return value;
    }
    inline void inorder(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        inorder(root->left,k);
        if(count==k-1)
            value = root->val;
        count++;
        inorder(root->right,k);
    }
};