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
    TreeNode* arrayToBST(vector<int>& nums, int left, int right){
        if(left > right) return NULL; 
        int mid = left + (right-left)/2; 
        TreeNode* new_node = new TreeNode(nums[mid]);
        new_node->left = arrayToBST(nums, left, mid-1);
        new_node->right = arrayToBST(nums, mid+1, right);
        return new_node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size()-1);
    }
};