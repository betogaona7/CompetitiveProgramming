#include <algorithm>

class Solution{
    public:
        vector<int> subVector(vector<int>&arr, int left, int right){
            vector <int> sub;
            for(int i = left; i < right; ++i){
                sub.push_back(arr[i]);
            }
            return sub;
        }

        int binarySearch(vector<int>&nums, int target){
            if(nums.size() == 1) return nums[0];

            int left = 0, mid = 0, ind =0;
            int right = nums.size()-1;

            while(left <= right){
                mid = left + (right-left)/2;
                if(nums[mid] == target) return mid; 
                else if(nums[mid] >= target){
                    right = mid-1; 
                    ind = mid; 
                }else left = mid+1; 
            }
            return ind; 
        }

        vector<int> findClosestElements(vector<int>&arr, int k, int x){
            if(x <= arr[0]) return subVector(arr, 0, k);
            else if(x > arr[arr.size()-1]) return subVector(arr, arr.size()-k, arr.size());
            else{
                int index = binarySearch(arr, x);
                if(index < 0) index = -index-1; 
                int low = max(0, index-k-1);
                int a = arr.size()-1; 
                int b = index+k-1; 
                int high =min(a, b)

                while(high - low > k-1){
                    if(low < 0 || (x-arr[low] <= (arr[high]-x))) high--;
                    else if(high > arr.size()-1 || (x-arr[low]) > (arr[high]-x)) low++;
                    else cout << "Unhandled case: " << low << " " << high << endl;
                } 
                return subVector(arr, low, high+1);
            }
        }
}