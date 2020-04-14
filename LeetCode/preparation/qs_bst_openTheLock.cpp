class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector <int> visited(10001);
        string s = "0000";
        queue<string> q;
        q.push(s);
        visited[0] = 1;
        int steps = 0;
        for(auto &deadend : deadends){
            if(deadend == "0000") return -1;
            visited[stoi(deadend)] = 1;
        }
        while(!q.empty()){
            int len = q.size();
            while(len > 0){
                --len;
                string current = q.front();
                q.pop();
                if(current == target) return steps;
                for(int i = 0; i < 4; ++i){
                    char currentC = current[i];
                    char nextC = currentC == '9' ? '0': currentC + 1;
                    char lastC = currentC == '0' ? '9': currentC - 1;
                    current[i] = nextC;
                    int temp = stoi(current);
                    
                    if(!visited[temp]){
                        q.push(current);
                        visited[temp] = 1;
                    }
                    current[i] = lastC;
                    temp = stoi(current);
                    if(!visited[temp]){
                        q.push(current);
                        visited[temp] = 1;
                    }
                    current[i] = currentC;
                }
            }
            ++steps;
        }
        return -1; 
    }
};