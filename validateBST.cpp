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
    vector<int> v;
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        v.clear();
        travel(root);
        for(int i=1;i<v.size();i++)
            if(v[i]<=v[i-1]) return false;
        return true;
    }
    
    void travel(TreeNode* root)
    {
        if(!root) return;
        travel(root->left);
        v.push_back(root->val);
        travel(root->right);
        return;
    }
};
