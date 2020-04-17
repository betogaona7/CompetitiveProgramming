bool DFS(Node* current, Node* target, set<Node>& visited){
    if(current->val == target->val) return true;
    for(auto neighbor : current->neighbors){
        auto it = visited.insert(neighbor);
        if(it.secod) return DFS(neighbor, target, visited);
    }
    return false;
}