class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> hashtable;
        for(int i = 0; i < nums.size(); i++){
            if(hashtable.find(nums[i]) != hashtable.end()){
                // Fond it 
                if(i - hashtable[nums[i]] <= k){
                    return true;
                }else{
                    hashtable[nums[i]] = i;
                }
            }else{
                hashtable[nums[i]] = i;
            }
        }
        return false;
    }
};