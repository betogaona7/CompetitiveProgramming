int countLeaves(Node* root){
    if(!root) return 0;
    else if(!root->right && !root->left) return 1;
    else return countLeaves(root->left) + countLeaves(root->right);  
}