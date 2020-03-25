class Solution{
    public: 
        int binarySearch(vector<int>&nums, int target, bool left){
            int left = 0, mid = 0; 
            int right = nums.size();

            while(left < right){
                mid = left + (right - left)/2;
                if(nums[mid] > target || (left && nums[mid] == target)) left = mid;
                else left = mid+1; 
            }
            return left; 
        }

        vector <int> searchRange(vector<int>&nums, int target){
            vector<int>indices = {-1, -1};
            int left = binarySearch(nums, target, true);

            if(left == nums.size() || nums[left] != target) return indices;

            indices[0] = left; 
            indices[1] = binarySearch(nums, target, false)-1;

            return indices;
        }
}