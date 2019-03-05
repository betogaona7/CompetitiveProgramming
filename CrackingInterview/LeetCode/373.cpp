class mycomparison{
    bool min_queue;
    public:
        mycomparison(const bool& min_q=false){
            min_queue = min_q;
        }
        bool operator()(const pair<int, int>& lhs, const pair<int, int>&rhs)const{
            if (min_queue) return (lhs.first+lhs.second > rhs.first+rhs.second);
            else return(lhs.first+lhs.second < rhs.first+rhs.second);
        }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue <pair<int, int>, vector< pair<int, int> >, mycomparison > heap;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(heap.size() < k){
                    heap.push(make_pair(nums1[i], nums2[j]));
                }else{
                    auto top_pair = heap.top();
                    if(top_pair.first + top_pair.second > nums1[i] + nums2[j]){
                        heap.pop();
                        heap.push(make_pair(nums1[i], nums2[j]));
                    }
                }
            }
        }
        if (heap.size()==0) return vector<pair<int, int> >();
        
        vector<pair<int, int> > returns(heap.size());
        int i = heap.size()-1;
        while(!heap.empty()){
            returns[i] = heap.top();
            heap.pop();
            i -= 1;
        }
        return returns;
        
    }
};