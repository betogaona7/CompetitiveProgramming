#include <set>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inters;
        multiset<int> set;
        for(auto number:nums1) set.insert(number);
        for(auto number:nums2){
            auto it =set.find(number);
            if(it != set.end()){
                inters.push_back(number);
                set.erase(it);
            }
        }
        return inters;
    }    
};