/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void DFS(Node* node, unordered_map<Node*, Node*>& map){
        if(map.find(node) == map.end()){
            Node *head = new Node(node->val);
            map[node] = head;
        }    
        for(auto neighbor : node->neighbors){
            if(map.find(neighbor) != map.end()){
                map[node]->neighbors.push_back(map[neighbor]);
            }else{
                Node *tmp = new Node(neighbor->val);
                map[neighbor] = tmp;
                map[node]->neighbors.push_back(map[neighbor]);
                DFS(neighbor,map);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> map;
        DFS(node, map);
        return map[node];
    }
};