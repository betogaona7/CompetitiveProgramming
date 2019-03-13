#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector <string> movements(string value){
    /* 
    Returns a sorted vector of allowed postions to move.
        value: 
            Value of the current position
    */
    int row = int(value[0]) - 48;
    int col = int(value[1]) - 48;

    string down = to_string(row-1) + value[1];
    string left = value[0] + to_string(col-1);
    string right =value[0] + to_string(col+1); 
    string top = to_string(row+1) + value[1];

    vector <string> m {down, left, right, top};
    return m;
}

int main() {
    unordered_map <string, int> visited;
    
    int rows, cols, dx, dy, bx, by, limit, i;
    string start, end, row; 
    
    cin >> rows >> cols;
    cin >> dx >> dy;
    cin >> bx >> by;
    
    limit = stoi(to_string(rows-1) + to_string(cols-1));
    start = to_string(dy) + to_string(dx);
    end = to_string(by) + to_string(bx);
    
    cin.ignore(256, '\n'); 
    
    // Build the map
    i = 0;
    while(i < rows){
        getline(cin, row);
        for(int j = 0; j < cols; j++){
            int value = 0;
            if(row[j] == '1'){
                value = 1;
            }
            visited.insert(make_pair(to_string(i)+to_string(j), value));
        }
        i += 1;
    }

    stack < string > nodes;  
    queue < string > nodesq;
    
    // If the drone is already where the battery is, then why to move?
    if(start == end){
        cout << 0 << endl;
        cout << "GRAB" << endl;
        return 0;
    }else if(stoi(end) > limit || bx < 0 || by < 0){ // If the battery isn't on valid coordinates, then the drone will need a human.
        cout << -1 << endl;
        return 0;
    }

    // If the battery has valid coordinates and the drone isn't already there, then calculate the shortest path.
    nodes.push(start);
    nodesq.push(start);
    visited[start] = 1;

    // Build an ordered tree with the possible paths until finding the goal.
    while(nodes.top() != end){
        vector <string> actions = movements(nodesq.front());
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
        if(nodesq.empty()){
            break;
        }
    }
    
    // If we din't find any path, then help!
    if(nodes.top() != end){
        cout << -1 << endl;
        return 0;
    }

    // If we did, then use the tree to get the shortest path.
    stack <string> path;
    path.push(nodes.top());
    vector <string> actions = movements(nodes.top());
    nodes.pop();

    while(!nodes.empty()){
        if(binary_search(actions.begin(), actions.end(), nodes.top())){
            path.push(nodes.top());
            actions = movements(nodes.top());
            nodes.pop();
        }else{
            nodes.pop();
        }
    }
    
    // Print number of steps to reach the battery. 
    cout << path.size() << endl;

    // Once we got the path, print the commands.
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
    // If the drone is where the battery is, then just grab. 
    cout << "GRAB" << endl;
    
    return 0;
}