class Solution{
    public: 
        bool isPerfectSquare(int num){
            long left = 1, mid = 0; 
            long right = num/2+1;

            while(left <= right){
                mid = left + (right - left)/2;
                if(mid*mid == num) return true; 
                else if(mid*mid >= num) right = mid-1;
                else left = mid+1;
            }
            return false;
        }
}