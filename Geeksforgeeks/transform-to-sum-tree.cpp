int SumTree(Node *node){
    if(!node) return 0;
    
    int old_value = node->data;
    node->data = SumTree(node->left) + SumTree(node->right);
    return node->data + old_value;
}