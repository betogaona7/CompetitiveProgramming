class Solution {
public:
    bool isValid(string s) {
        stack <char> brackets;
        for(auto character : s){
            if(brackets.empty()) brackets.push(character);
            else{
                char last = brackets.top();
                if(last == '(' && character == ')' ||
                   last == '[' && character == ']' ||
                   last == '{' && character == '}') brackets.pop();
                else brackets.push(character);
            }
        }
        
        if(brackets.empty()) return true;
        else return false;
    }
};