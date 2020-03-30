/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack> 
#include <limits>

class Solution {
public:    
    bool isValidBST(TreeNode *root) {
        stack<TreeNode*> tree;
        double prev_elem = -std::numeric_limits<double>::infinity();
        while(!tree.empty() || root != nullptr){
            while(root != nullptr){
                tree.push(root);
                root = root->left;
            }
            root = tree.top();
            tree.pop();
            
            if(root->val <= prev_elem) return false;
            prev_elem = root->val;
            root = root->right;
        }
        return true;
    }
};