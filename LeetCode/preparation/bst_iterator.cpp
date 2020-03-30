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

class BSTIterator {
    stack<TreeNode*> elements; 
    
    void _leftMostElement(TreeNode *root){
        while(root != nullptr){
            elements.push(root);
            root = root->left; 
        }
    }
public:
    
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> e;     
        elements = e; 
    
        _leftMostElement(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *top_node = elements.top();
        elements.pop();
        
        if(top_node->right != nullptr) _leftMostElement(top_node->right);
        return top_node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return elements.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */