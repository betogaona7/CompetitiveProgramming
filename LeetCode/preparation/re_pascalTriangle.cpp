class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        auto v = getRow(rowIndex-1);
        int s = v.size();
        for(int i = 1; i < s; ++i){
            v[i] = (i <= s/2) ? v[i] + v[s-i] : v[s-i];
        }
        v.push_back(1);
        return v;
    }
};