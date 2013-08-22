#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        setNext(root,root,0,0);
        return;
    }
    
    void setNext(TreeLinkNode *root, TreeLinkNode *current,int depth, int sequence)
    {
        if(current==NULL) return;
        current->next = getNext(root,depth,sequence);
        setNext(root, current->left, depth+1, 2*sequence);
        setNext(root, current->right, depth+1, 2*sequence+1);
    }
    
    TreeLinkNode* getNext(TreeLinkNode* root, int depth, int sequence)
    {
        TreeLinkNode* temp = root;
        if(sequence == pow(2,depth)-1)
            return NULL;
        sequence += 1;
        int temp_depth = 0, temp_sequence = sequence;
        while(temp_depth!=depth)
        {
            if(temp_sequence<int(pow(2,depth-temp_depth-1)))
            {
                temp = temp->left;
                temp_depth++;
            }
            else
            {
                temp = temp->right;
                temp_sequence -= pow(2,depth-temp_depth-1);
                temp_depth++;
            }
        }
        return temp;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
	my_solution->solve();

//print your output here
    cout<<endl;
}
