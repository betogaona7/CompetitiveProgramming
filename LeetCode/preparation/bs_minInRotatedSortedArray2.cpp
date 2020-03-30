class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, mid = 0, ans = 0;
        int right = nums.size()-1; 
        
        while(left <= right){
            if(nums[left] == nums[right] && left != right){ 
                left++; 
                continue; 
            }
            mid = left + (right - left)/2;
            if(nums[mid] <= nums[nums.size()-1]){
                ans = mid; 
                right = mid-1; 
            }else left = mid+1;
        }
        return nums[ans];
    }
};