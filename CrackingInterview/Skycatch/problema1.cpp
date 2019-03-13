#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool isAdjacent(string actual, string element){
    /* 
    Returns true if the element is adjacent to actual, False otherewise.
        
        actual: 
            Top element in a queue/vector of grid positions
        element: 
            Element that you want to know if it's adjacent
    */
    int row = int(actual[0]) - 48;
    int col = int(actual[1]) - 48;
    
    string right = actual[0] + to_string(col+1);         
    string down = to_string(row+1) + actual[1];         
    string downright = to_string(row+1) + to_string(col+1);  
    string left = to_string(row+1) + to_string(col-1);

    if(element == right || element == down || element == downright || element == left){
        return true;
    }
    return false;
}

int main() {
    unordered_map <string, vector<string> > mines;
    queue <string> rocks;
    
    int rows, cols, i;
    string row;
    
    cin >> rows >> cols;
    cin.ignore(256, '\n'); 
    
    // Get the locations of where there is gold.
    i = 0;
    while(i < rows){
        getline(cin, row);
        for(int j = 0; j < cols; j++){
            if(row[j] == '1'){
                rocks.push(to_string(i)+to_string(j));
            }
        }
        i += 1;
    }
    
    // If there are no golden rocks, there are no golden mines.
    if(rocks.empty()){
        cout << "0" << endl;
        return 0;
    }

    // Add the first golden rock to form a golden mine.
    string actual = rocks.front();
    mines[actual] = vector <string> ();
    rocks.pop();
    
    // Iterate over all the rocks and add them into an existent golden mine or as a new one
    // according to its adjacency.
    while(!rocks.empty()){
        string element = rocks.front();
        if(isAdjacent(actual, element)){  // Is it adjacent to the actual rock?
            mines[actual].push_back(element);
        }else{
            bool found = false;
            for(auto it = mines.begin(); it != mines.end(); it++){ // Is it adjacent to a previous rock?
                int s = mines[it->first].size();
                for(int i = s-1; i >= 0; i--){
                    string actual = mines[it->first][i];
                    if(isAdjacent(actual, element)){
                        mines[it->first].push_back(element);
                        found = true;
                        break;
                    }
                }
                if(isAdjacent(it->first, element)){ // Maybe to the first rock of a new mine?
                    mines[it->first].push_back(element);
                    found = true;
                    break;
                }
            }            
            if(found == false){ // Nothing?, well then, it will be the first for its new mine.
                actual = element;
                mines[actual] = vector <string> ();
            }
        }
        rocks.pop();
    }
    // Print the number of golden mines
    cout << mines.size() << endl;    
    return 0;
}