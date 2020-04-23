class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1) return 0;
        
        int nlevel = pow(2, N-1);
        nlevel /= 2;
        
        if(K <= nlevel) return kthGrammar(N-1, K);
        else return kthGrammar(N-1, K-nlevel) ^ 1;
    }
};