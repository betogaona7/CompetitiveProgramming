void printKdistance(Node *root, int k){
    if(!root) return;
    if(k == 0){
        cout << root->data << " "; 
        return;
    }else{
        printKdistance(root->left, k-1);
        printKdistance(root->right, k-1);
    }
}