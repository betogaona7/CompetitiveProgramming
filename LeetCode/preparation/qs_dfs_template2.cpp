bool DFS(int root, int target){
    set <Node> visited;
    stack <Node> s; 
    s.push(root);
    while(!s.empty()){
        Node current = s.top();
        s.pop();
        if(current->val == target) return true;
        for(auto neighbor: current->neighbors){
            auto it = visited.insert(neighbor);
            if(it.second) s.push(neighbor);
        }
    }
    return false;
}