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
    TreeNode* getMinNode(TreeNode* root){
        while(root->left != nullptr) root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(!root->right) return root->left; 
            if(!root->left) return root->right;
            
            TreeNode *min = getMinNode(root->right);
            root->val = min->val;
            root->right=deleteNode(root->right, root->val);
        }
        return root; 
    }
};