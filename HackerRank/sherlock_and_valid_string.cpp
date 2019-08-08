string isValid(string s) {
    vector <int> freq(27, 0);
    for(int i = 0; i < s.length(); ++i){
        freq[s[i]-'a'] += 1;
    }

    vector <int> wzeros;
    
    for(int i = 0; i < freq.size(); ++i){
        if(freq[i] == 0) continue;
        wzeros.push_back(freq[i]);        
    }

    int prev = wzeros[0];
    bool comodin = false;
    for(int i = 1; i < wzeros.size(); ++i){
        if(wzeros[i] != prev) {
            if(!comodin){
                comodin = true;
            }else{
                return "NO";
            }
        }
        if(!comodin){
            prev = freq[i];
        }
        
    }
    return "YES";
}