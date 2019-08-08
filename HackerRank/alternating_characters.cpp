int alternatingCharacters(string s) {
    char current = s[0];
    int r = 0;
    for(int i = 1; i < s.length(); i++){
        if (s[i] == s[i-1]){
            r += 1;
        }else{
            current = s[i];
        }
    }
    return r;
}