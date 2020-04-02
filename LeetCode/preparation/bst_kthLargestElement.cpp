struct Node{
    int val;
    int counter; 
    Node *left;
    Node *right;
    Node(int x):val(x), counter(1), left(NULL), right(NULL){}
};


class KthLargest {
public:
    
    Node* insertIntoBST(Node* root, int val) {
        if(!root) return new Node(val);
        if(root->val < val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        
        root->counter++;
        return root;
    }
    
    int searchBST(Node* root, int k) {
        if(!root) return 0;
        int nodes_right = 0;
        if(root->right != nullptr) nodes_right = root->right->counter;
        
        int root_largest = nodes_right+1;
        if(root_largest == k) return root->val;
        else if(k < root_largest) return searchBST(root->right, k);
        
         
        k = k - root_largest;
        return searchBST(root->left, k);        
    }
    
    Node* root = NULL; 
    int k; 
    
    KthLargest(int k, vector<int>& nums) {
        for(auto number:nums) this->root = insertIntoBST(this->root, number);
        this->k = k;
    }
    
    int add(int val){
        this->root = insertIntoBST(this->root, val);
        return searchBST(this->root, this->k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
