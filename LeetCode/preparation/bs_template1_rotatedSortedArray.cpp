class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, mid = 0;
        int right = nums.size()-1;
        while(left <= right){
            if(nums[left] == target) return left;
            else if(nums[right] == target) return right;
            else{
                right -= 1;
                left += 1;
            }
        }
        return -1;
    }
};