void countSwaps(vector<int> a) {
    int total = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size()- 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                total++;
            }
        }
    }
    cout << "Array is sorted in " << total << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size()-1] << endl;
}