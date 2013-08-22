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
private:
    int result;
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = 0;
        if(root==NULL) return 0;
        help(root,0);
        return result;
    }
    
    void help(TreeNode *node, int temp)
    {
        if(node->left==NULL && node->right==NULL)
        {
            result += temp*10+node->val;
            return;
        }
        else if(node->left == NULL)
        {
            help(node->right, temp*10+node->val);
        }
        else if(node->right == NULL)
        {
            help(node->left, temp*10+node->val);
        }
        else
        {
            help(node->left, temp*10+node->val);
            help(node->right, temp*10+node->val);
        }
        return;
    }
};
