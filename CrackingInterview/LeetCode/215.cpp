class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > heap;
        for(int i = 0; i < nums.size(); i++){
            if(heap.size() < k){
                heap.push(nums[i]);
            }else{
                int min_elem = heap.top();
                if (min_elem < nums[i]){
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
        return heap.top();
    }
};