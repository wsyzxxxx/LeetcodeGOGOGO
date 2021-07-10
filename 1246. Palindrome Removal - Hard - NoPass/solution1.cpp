    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        std::vector<std::vector<int> > dp(n, std::vector<int>(n, n));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = 0; i < n-1; i++) {
            if (arr[i] == arr[i+1]) {
                dp[i][i+1] = 1;
            } else {
                dp[i][i+1] = 2;
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0, j = len-1; j < n; i++, j++) {
                if (arr[i] == arr[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }
                
                for (int mid = i; mid < j; mid++) {
                    dp[i][j] = std::min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
