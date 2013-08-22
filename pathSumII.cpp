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
    vector<vector<int> > result;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if(root==NULL) return result;
        vector<int> temp;
        temp.clear();
        nodeHasPathSum(root, sum, temp);
        return result;
    }
    
    void nodeHasPathSum(TreeNode*root, int sum, vector<int> &temp)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val == sum)
            {
                temp.push_back(root->val);
                result.push_back(temp);
                temp.erase(temp.end()-1);
            }
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right!=NULL)
            nodeHasPathSum(root->right, sum-root->val, temp);
        else if(root->right == NULL && root->left!=NULL)
            nodeHasPathSum(root->left, sum-root->val, temp);
        else 
        {
            nodeHasPathSum(root->left, sum-root->val, temp); 
            nodeHasPathSum(root->right, sum-root->val, temp);
        }
        temp.erase(temp.end()-1);
        return;
    }
};
