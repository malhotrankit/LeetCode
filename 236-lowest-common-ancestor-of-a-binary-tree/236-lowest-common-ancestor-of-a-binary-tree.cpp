/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* ans;
    int flag = 0;
    int count = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        inorder(root,p,q);
        return ans;
        
    }
    
    void inorder(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return;
        inorder(root->left, p, q);
        inorder(root->right, p, q);
        count=0;
        lca(root, p, q);
        if(count==2&&flag==0)
        {
            //printf("%d\n",root->val);
            ans=root;
            flag=1;
        }
    }
    
    void lca(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        
        if(root==NULL)
            return;
        //printf("%d\n",root->val);
        if(root->val==p->val)
            count++;
        if(root->val==q->val)
            count++;
        lca(root->left,p,q);
        lca(root->right,p,q);
    }
    
};