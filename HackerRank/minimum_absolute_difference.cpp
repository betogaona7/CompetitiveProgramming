int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int mini = INFINITY;
    int prev = arr[0];
    for(int i = 1; i < arr.size(); ++i){
        if(abs(prev-arr[i]) < mini){
            mini = abs(prev-arr[i]);
        }
        prev = arr[i];
    }

    return mini;
}