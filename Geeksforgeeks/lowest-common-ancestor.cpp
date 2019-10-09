Node* LCA(Node *root, int a, int b)
{
   if(!root) return NULL;
   if(root->data > a && root->data > b) return LCA(root->left, a, b);
   if(root->data < a && root->data < b) return LCA(root->right, a, b);
   return root;
}