
int hourglassSum(vector<vector<int>> arr) {
    int sum = 0;
    int max = INT_MIN;
    for(int i = 0; i < arr.size()-2; ++i){
        for(int j = 0; j < arr[0].size()-2; ++j){
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] 
                 +arr[i+1][j+1]
                 +arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if(sum > max){
                max = sum;
            }
        }
    }
    return max;
}