class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int islands{0};
        for(auto row = 0; row < grid.size(); ++row){
            for(auto col = 0; col < grid[0].size(); ++col){
                if(grid[row][col] == '1'){
                    ++islands;
                    queue<pair<int, int>> q;
                    q.push({row, col});
                    grid[row][col] = '0';
                    while(!q.empty()){
                        auto row = q.front().first;
                        auto col = q.front().second;
                        q.pop();
                        if(row>0 && grid[row-1][col] == '1'){
                            q.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if(row<grid.size()-1 && grid[row+1][col] == '1'){
                            q.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if(col>0 && grid[row][col-1] == '1'){
                            q.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if(col<grid[0].size()-1 && grid[row][col+1] == '1'){
                            q.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return islands;
    }
};