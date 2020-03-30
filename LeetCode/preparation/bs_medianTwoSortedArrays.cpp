class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n){
            vector <int> temp = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }
        
        int left = 0, mid = (m+n+1)/2;
        int right = m;
        while(left <= right){
            int i = (left + right)/2;
            int j = mid-i;
            if(i < right && nums2[j-1] > nums1[i]) left = i+1; // too small
            else if(i > left && nums1[i-1] > nums2[j]) right = i-1; //too big
            else{ // perfect
                int max_left = 0; 
                if(i == 0) max_left = nums2[j-1];
                else if(j == 0) max_left = nums1[i-1];
                else max_left = max(nums1[i-1], nums2[j-1]);
                
                if((m+n)%2 == 1) return max_left;
                
                int min_right = 0;
                if(i == m) min_right = nums2[j];
                else if(j == n) min_right = nums1[i];
                else min_right = min(nums2[j], nums1[i]);
                
                return (max_left + min_right) / 2.0;
                
            }
        }
        return 0;
    }
};