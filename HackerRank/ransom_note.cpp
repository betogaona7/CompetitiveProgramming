void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map <string, int> n_words;

    for(int i = 0; i < note.size(); ++i){
        n_words[note[i]] += 1;
    }

    for(int i = 0; i < magazine.size(); ++i){
       if(!(n_words.find(magazine[i]) == n_words.end())){
           n_words[magazine[i]] -= 1;
       }
    }

    for(auto i = n_words.begin(); i != n_words.end(); ++i){
        if(i->second > 0){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}