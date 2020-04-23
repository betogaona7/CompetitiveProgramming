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
    vector<TreeNode*> generate(int from, int to){
        vector<TreeNode*> r; 
        if(to - from < 0) r.push_back(NULL);
        else if(to - from == 0) r.push_back(new TreeNode(from));
        else{
            for(int i = from; i <= to; ++i){
                vector<TreeNode*>left = generate(from, i-1);
                vector<TreeNode*>right = generate(i+1, to);
                for(int j = 0; j < left.size(); ++j){
                    for (int k = 0; k < right.size(); ++k){
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        r.push_back(root);
                    }
                }
            }
        }
        return r;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generate(1, n);
    }
};