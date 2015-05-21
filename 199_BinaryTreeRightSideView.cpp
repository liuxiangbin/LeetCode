/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
            
        queue<TreeNode*> qt;
        qt.push(root);
        int cnt = 1;
        
        TreeNode* tmp;
        while(!qt.empty()){
            res.push_back(qt.front()->val);
            
            int t = 0;      //for count
            while(cnt--){
                tmp = qt.front();
                qt.pop();
                if(tmp->right!=NULL){
                    qt.push(tmp->right);
                    ++t;
                }
                if(tmp->left!=NULL){
                    qt.push(tmp->left);
                    ++t;
                }
            }
            
            cnt = t;
        }
        
        return res;
    }
};