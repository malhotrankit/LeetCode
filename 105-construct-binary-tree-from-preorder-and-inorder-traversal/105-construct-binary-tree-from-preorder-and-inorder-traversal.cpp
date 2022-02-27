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
    TreeNode *root ,*node, *ptr;
    int pos1, pos2, n, hm[6001];
    
    inline void create(TreeNode *ptr, int ele, vector<int>& inorder)
    {
        /*for(int i=0;i<n;i++)
        {
            if(inorder[i]==ele)
                pos1=i;
            if(inorder[i]==ptr->val)
                pos2=i;
        }*/
        
        if(hm[ele+3000]<hm[(ptr->val)+3000])
        {
            if(ptr->left==NULL)
            {
                node = new TreeNode;
                node->val= ele;
                node->left= NULL;
                node->right= NULL;
                ptr->left= node;
            }
            else
            {
                create(ptr->left,ele,inorder);
            }
        }
        else
        {
            if(ptr->right==NULL)
            {
                node = new TreeNode;
                node->val= ele;
                node->left= NULL;
                node->right= NULL;
                ptr->right= node;
            }
            else
            {
                create(ptr->right,ele,inorder);
            }
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int i;    
        n= preorder.size();
        root= new TreeNode;
        root->val= preorder[0];
        root->left= NULL;
        root->right= NULL;
        
        for(i=1;i<n;i++)
            hm[inorder[i]+3000]=i;
        
        for(i=1;i<n;i++)
        {
            ptr= root;
            create(ptr, preorder[i],inorder);
        }
        return root;
    }
};