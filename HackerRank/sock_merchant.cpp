int sockMerchant(int n, vector<int> ar) {
    sort(ar.begin(), ar.end());
    stack <int> inpairs;

    for(int i = 0; i < ar.size();++i){
        if(inpairs.empty()){
            inpairs.push(ar[i]);
        }else{
            if(inpairs.top() == ar[i]){
                inpairs.pop();
            }else{
                inpairs.push(ar[i]);
            }
        }
    }
    return (ar.size()-inpairs.size())/2;
}