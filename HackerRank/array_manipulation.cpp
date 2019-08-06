long arrayManipulation(int n, vector<vector<int>> queries) {
	long maximum = 0;
	long temp = 0;

	vector<int>maxis;
	maxis.assign(n+1, 0);
	for(int i = 0; i < queries.size(); ++i){
	   maxis[queries[i][0]] += queries[i][2];
	   if(queries[i][1]+1 <= n){
	       maxis[queries[i][1]+1] -= queries[i][2];
	   }
	}

	for(int i=0; i < maxis.size(); ++i){
	    temp = temp + maxis[i];
	    if(temp > maximum){
	        maximum = temp;
	    }
	}

    return maximum;
}