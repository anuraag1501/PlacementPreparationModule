vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> pas(n);
     pas[0].push_back(1);
    
    for(int i = 1; i < n; i++){
        pas[i].push_back(1);

        for(int j = 1; j < i; j++){
            pas[i].push_back(pas[i-1][j]+pas[i-1][j-1]);
        }
        
         pas[i].push_back(1);
    }
    return pas;
}
