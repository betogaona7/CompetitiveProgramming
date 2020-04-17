class Solution {
public:
    pair <int, int> findPositions(string &s, int idx){
        pair <int, int> result; 
        stack <int> st; 
        for(int i = idx; i < s.size(); ++i){
            if(s[i] == '[') st.push(i+1);
            if(s[i] == ']'){
                if(st.size() == 1){
                    result.first = st.top();
                    result.second = i-1;
                    return result;
                }
                st.pop();
            }
        }
        return result;
    }
    
    string decode(string& s, int start, int end){
        string result = "";
        int i = start;
        while(i <= end){
            if(isdigit(s[i])){
                int num = stoi(s.substr(i, end-i+1));
                pair<int, int> pos = findPositions(s, i);
                string tmp = decode(s, pos.first, pos.second);
                for(int j = 0; j < num; ++j) result += tmp;
                i = pos.second+2; 
            }else if(isalpha(s[i])) result += string(1, s[i++]);
            else ++i;
        }
        return result;
    }
    
    string decodeString(string s) {
        return decode(s, 0, s.size()-1);
    }
};