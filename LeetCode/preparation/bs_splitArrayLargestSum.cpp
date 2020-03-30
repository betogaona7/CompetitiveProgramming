#include <algorithm>

class Solution {
public:
    int split(vector<int>& nums, long long x){
        long long sum = 0;
        int subarr = 1; 
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > x) return -1;
            else if(sum + nums[i] > x){
                subarr++;
                sum = nums[i];
            }else sum += nums[i];
        }
        return subarr;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long left = *min_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0ll);
        long long ans = right, mid = 0;
        
        while(right-left>1){
            mid = left + (right-left)/2;
            int cont = split(nums, mid);
            if(cont >=0 && cont <= m){
                right = mid;
                ans = min(ans, mid);
            }else left = mid;
        }
        return ans;
    }
};