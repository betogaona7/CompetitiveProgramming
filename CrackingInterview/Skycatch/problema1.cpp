#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool isAdjacent(string actual, string element){
    int row = int(actual[0]) - 48;
    int col = int(actual[1]) - 48;
    
    string pos1 = actual[0] + to_string(col+1);         // Right
    string pos2 = to_string(row+1) + actual[1];         // Down
    string pos3 = to_string(row+1) + to_string(col+1);  // Down right
    string pos4 = to_string(row+1) + to_string(col-1);  // Down left

    if(element == pos1 || element == pos2 || element == pos3 || element == pos4){
        return true;
    }
    return false;
}

int main() {
    queue <string> gold;
    unordered_map <string, vector<string> > hash_table;
    
    
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
            if(grid[i][j] == '1'){
                gold.push(to_string(i)+to_string(j));
            }
        }
    }
    
    string actual = gold.front();
    hash_table[actual] = vector <string> ();
    gold.pop();
    
    while(!gold.empty()){
        string element = gold.front();
        if(isAdjacent(actual, element)){  // Is it adjacent to the actual element?
            hash_table[actual].push_back(element);
        }else{
            bool found = false;
            for(auto it = hash_table.begin(); it != hash_table.end(); it++){ // Is it adjacent to a previous element?
                int s = hash_table[it->first].size();
                for(int i = s-1; i >= 0; i--){
                    string actual = hash_table[it->first][i];
                    if(isAdjacent(actual, element)){
                        hash_table[it->first].push_back(element);
                        found = true;
                        break;
                    }
                }
                if(isAdjacent(it->first, element)){ // Is it adjacent to the key?
                    hash_table[it->first].push_back(element);
                    found = true;
                    break;
                }

            }            
            if(found == false){ // Nothing?, well then, it is a new one.
                actual = element;
                hash_table[actual] = vector <string> ();
            }
        }
        gold.pop();
    }


    for(auto it = hash_table.begin(); it != hash_table.end(); it++){
        cout << it->first << " ";
        for(string i : hash_table[it->first]){
            cout << i << " ";
        }    
        cout <<""<< endl;
    }
    
    cout << hash_table.size() << endl;
    
    
    return 0;
}
