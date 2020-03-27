class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtle = nums[0];
        int rabbit = nums[0];
        
        do{
            turtle = nums[turtle];
            rabbit = nums[nums[rabbit]];
        }while(turtle != rabbit);
        
        int ptr1 = nums[0];
        int ptr2 = turtle; 
        while(ptr1 != ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};