int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    int zeros = 0;
    for(int i = 0; i < c.size(); ++i){
        if(c[i] == 0){
            zeros += 1;
        }else{
            zeros = -1;
            break;
        }
    }
    if(zeros > 0){
        return zeros/2;
    }
    for(int i = 0; i < c.size(); ++i){
        cout << i << endl;
        if(c[i+2] == 0){
            i = i+1;
        }       
        jumps += 1;
    }
    return jumps-1;
}
