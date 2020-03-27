#include <unordered_set>
class Solution {
public:
    bool binarySearch(vector<int>&nums, int &target){
        int left = 0, mid = 0;
        int right = nums.size()-1; 
        while(left <= right){
            mid = left + (right-left)/2; 
            if(nums[mid] == target) return true;
            else if(nums[mid] >= target) right = mid-1;
            else left = mid+1;
        }
        return false; 
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inters;
        unordered_set <int> uniques; 
        
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums1.size(); ++i){
            auto it = uniques.insert(nums1[i]);
            if(it.second){
                if(binarySearch(nums2, nums1[i])) inters.push_back(nums1[i]);
            }
        }
        return inters;
    }
};
