#include <vector>
#include <sstream> 

void reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);
    string token;
    while(getline(ss, token, '.')){
        words.push_back(token);
    }
    
    string r = "";
    for(int i = words.size(); i >= 0; --i){
        r+= words[i] + ".";
    }
    cout << r;
}