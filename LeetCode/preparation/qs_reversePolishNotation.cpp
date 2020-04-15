class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i].back() >= '0' && tokens[i].back() <= '9'){
                st.push(stoi(tokens[i]));
                continue;
            }
            
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if (tokens[i].front() == '+') st.push(b+a);
            else if (tokens[i] == "-") st.push(b-a);
            else if (tokens[i] == "*") st.push(b*a);
            else if (tokens[i] == "/") st.push(b/a);
        }
        return st.top();
    }
};