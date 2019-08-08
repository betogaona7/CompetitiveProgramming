int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int maxi = 0;
    int total = 0;
    int i = 0;
    while(total <= k){
        total += prices[i];
        i++;
        maxi++;
    }
    return maxi-1;
}