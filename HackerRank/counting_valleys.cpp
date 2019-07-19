int countingValleys(int n, string s) {
    stack <char> base;
    int valleys = 0;
    for(int i = 0; i < s.size(); ++i){
        if(base.empty()){
            // It reached sea leavel
            if(s[i] == 'D'){
                valleys += 1;
            }
            base.push(s[i]);
        }else{
            if(base.top() != s[i]){
                base.pop();
            }else{
                base.push(s[i]);
            }
        }
    }
    return valleys;
}