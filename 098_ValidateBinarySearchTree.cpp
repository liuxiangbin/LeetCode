/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


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
    void inorderTravel(TreeNode *root,vector<int> &inorder)
    {
        if(root==NULL)
            return ;
        
        inorderTravel(root->left,inorder);
        inorder.push_back(root->val);
        inorderTravel(root->right,inorder);
    
    }

    bool isValidBST(TreeNode *root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return true;
        
        vector<int> inorder;
        inorderTravel(root,inorder);
        
        for(int i=1;i<inorder.size();++i){
            if(inorder[i]<inorder[i-1])
                return false;
        }
        
        return true;
    }
};