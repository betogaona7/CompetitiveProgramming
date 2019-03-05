class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length() == 1) return false;
        
        int n = s.length();
        
        stack <char> st;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}'){
            return false;
        } else{
            st.push(s[0]);
        }
        
        for(int i=1; i <n; i++){
            if(s[i] ==')' || s[i] == ']' || s[i] == '}'){
                if(st.empty()){
                    return false;
                }else{
                    if(st.top() == '{' && s[i] == '}' || st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};