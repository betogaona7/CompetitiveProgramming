class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> hashtable;
        for(int i = 0; i < s.size(); i++){
            hashtable[s[i]] += 1;
        }
        for(int i = 0; i < t.size(); i++){
            hashtable[t[i]] -= 1;
        }
        for(auto elem : hashtable){
            if(elem.second != 0) return false;
        }
        return true;
    }
};