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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return help(root->left, root->right);
    }
    
    bool help(TreeNode *left, TreeNode *right)
    {
        if( (!left&&right) || (!right&&left))
            return false;
        if(!left && !right) return true;
        if(left->val!=right->val) return false;
        return help(left->left,right->right) && help(left->right, right->left);
    }
};
