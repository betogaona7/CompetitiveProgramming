long repeatedString(string s, long n) {
    long div = n/s.length();
    long mod = n%s.length();
    long as = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'a'){
            as += 1;
        }
    }
    as = as*div;
    for(int i = 0; i < mod; ++i){
        if(s[i] == 'a'){
            as += 1;
        }
    }
    return as;
}