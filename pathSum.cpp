/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return false;
        return nodeHasPathSum(root,sum);
    }
    
    bool nodeHasPathSum(TreeNode*root, int sum)
    {
        if(root->left==NULL && root->right==NULL)
            return root->val==sum;
        if(root->left==NULL)
            return nodeHasPathSum(root->right, sum-root->val);
        if(root->right == NULL)
            return nodeHasPathSum(root->left, sum-root->val);
        return nodeHasPathSum(root->left, sum-root->val) || 
                nodeHasPathSum(root->right, sum-root->val);
    }
};
