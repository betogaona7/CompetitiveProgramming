#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector <string> pactions(string value){
    int row = int(value[0]) - 48;
    int col = int(value[1]) - 48;
    
    string down = to_string(row-1) + value[1];
    string left = value[0] + to_string(col-1);
    string right =value[0] + to_string(col+1); 
    string top = to_string(row+1) + value[1];

    vector <string> a {down, left, right, top};
    return a;
}

int main() {

    unordered_map <string, int> visited;
    vector <string> grid {"0000000011",
                          "0000000100",
                          "1100000110",
                          "1000100000",
                          "0000000000",
                          "0001001000",
                          "0100000111",
                          "1000000011",
                          "0000000000",
                          "0111100000"};
    
    // Get valid indices  O(n2)
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            int value = 0;
            if(grid[i][j] == '1'){
                value = 1;
            }
            visited.insert(make_pair(to_string(i)+to_string(j), value));
        }
    }
    int rows = 10; // x
    int cols = 10; // y
    int limit = stoi(to_string(rows-1) + to_string(cols-1));
    string start = "57";
    string end = "76";

    stack < string > nodes;  
    queue < string > nodesq;
    
    nodes.push(start);
    nodesq.push(start);
    visited[start] = 1;

    // build the tree
    while(nodes.top() != end){
        vector <string> actions = pactions(nodesq.front());
        for(int i = 0; i < 4; i++){
			int row = int(actions[i][0]) - 48;
			int col = int(actions[i][1]) - 48;
			if(row >= 0 && col >= 0 && stoi(actions[i]) <= limit){
                if(visited[actions[i]] != 1){
                	nodes.push(actions[i]);
                    nodesq.push(actions[i]);
                    visited[actions[i]] = 1;
                }
            }
        }
        nodesq.pop();
    }
    
    // Get the path 
    stack <string> path;
    path.push(nodes.top());
    vector <string> actions = pactions(nodes.top());
    nodes.pop();

    while(!nodes.empty()){
    	if(binary_search(actions.begin(), actions.end(), nodes.top())){
    		path.push(nodes.top());
    		actions = pactions(nodes.top());
    		nodes.pop();
    	}else{
    		nodes.pop();
    	}
    }
    
    // Print path 
    cout << path.size() << endl;
    int src = stoi(path.top());
    path.pop();
    while(!path.empty()){
    	int dst = stoi(path.top());
    	switch(src-dst){
    		case 10: cout << "UP" << endl;
    			break;
    		case 1: cout << "LEFT" << endl;
    			break;
    		case -1: cout << "RIGHT" << endl;
    			break;
    		case -10: cout << "DOWN" << endl;
    	}
    	src = dst;
    	path.pop();
    }
    cout << "GRAB" << endl;
    
    return 0;
}