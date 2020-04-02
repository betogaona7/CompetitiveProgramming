struct Node {
        long key,val;
        Node* left;
        Node* right;
        Node(long k,long v):key(k),val(v),left(NULL),right(NULL){}
};

class Solution {
public:
    Node *root = NULL;
    bool result = false;
    
    Node* insert(Node* root, long key, long val, int k, int t){
        if(root && abs(root->val - val)<=t && key-root->key<=k) result=true;
        if(!root) return new Node(key, val);
        if(root->val==val) root->key=key;
        if(root->val<val) root->left=insert(root->left,key,val,k,t);
        if(root->val>val) root->right=insert(root->right,key,val,k,t);
        return root;
    }
    
    Node* deleten(Node* root,long key,long val){
        if(!root) return root;
        if(val > root->val) root->right=deleten(root->right, key, val);
        if(val < root->val) root->left=deleten(root->left, key, val);
        if(root->key==key){
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            Node* temp= root->right;
            while(temp->left) temp=temp->left;
            root->val = temp->val; 
            root->key = temp->key;
            root->right = deleten(root->right, root->key, root->val);
        }
        return root;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, Node*> map;
        for(int i = 0; i < nums.size(); ++i){
            if(i>k) root=deleten(root, i-k-1, nums[i-k-1]);
            root = insert(root, i, nums[i], k, t);
            if(result) return true;
        }
        return result;
    }
};