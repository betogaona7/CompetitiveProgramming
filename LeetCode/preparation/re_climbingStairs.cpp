class Solution {
public:
    
    int climb(int i, int n, vector<int>&memo){
        if(i > n) return 0;
        if(i == n) return 1;
        if(memo[i] > 0) return memo[i];
        
        memo[i] = climb(i+1, n, memo) + climb(i+2, n, memo);
        return memo[i];
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1, 0);
        return climb(0, n, memo);
    }
};