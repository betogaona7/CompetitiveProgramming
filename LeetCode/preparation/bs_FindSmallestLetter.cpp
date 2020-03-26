class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, mid = 0;
        int right = letters.size();
        while(left < right){
            mid = left + (right - left)/2; 
            if(letters[mid] > target) right = mid;
            else left = mid + 1; 
        }
        
        return letters[left%letters.size()];
    }
};