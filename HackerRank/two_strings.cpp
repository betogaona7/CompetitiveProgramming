string twoStrings(string s1, string s2) {
    unordered_map<char, int> dict;
    for(int i = 0; i < s1.length(); ++i){
        dict[s1[i]] += 1;
    }

    for(int i = 0; i < s2.length(); ++i){
        if(!(dict.find(s2[i]) == dict.end())){
            return "YES";
        }
    }

   return "NO";
}