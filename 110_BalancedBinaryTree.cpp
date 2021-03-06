/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

//Solution 1:O(N^2)
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
    int maxDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
 
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }

    bool isBalanced(TreeNode *root) {
        if(root==NULL)
            return true;
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        return abs(leftHeight-rightHeight)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};