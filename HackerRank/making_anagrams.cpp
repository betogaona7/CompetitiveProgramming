int makeAnagram(string a, string b) {
    unordered_map<char, int> dict;

    for(int i = 0; i < a.length(); ++i){
        dict[a[i]] += 1;
    }
    for(int i = 0; i < b.length(); ++i){
        dict[b[i]] -= 1;
    }
    
    int total = 0;
    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it->second != 0){
            total += abs(it->second);
        }
    }
    return total;
}