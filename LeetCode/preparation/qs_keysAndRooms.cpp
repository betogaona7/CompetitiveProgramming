class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen (rooms.size(), false);
        seen[0] = true;
        stack <int> s;
        s.push(0);
        
        while(!s.empty()){
            int node = s.top(); s.pop();
            for(auto i : rooms[node]){
                if(!seen[i]){
                    seen[i] = true;
                    s.push(i);
                }
            }
        }
        for(auto wasSeen : seen){
            if(!wasSeen) return false;
        }
        return true;
    }
};