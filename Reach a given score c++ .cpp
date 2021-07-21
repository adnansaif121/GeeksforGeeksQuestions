long long int count(long long int n)
{
	int coins[3] = {3, 5, 10};
	int l = 3;
	
	int dp[n+1][l+1];
    
    for(int i = 0 ; i <= l; i++) dp[0][i] = 1;
    for(int i = 0 ; i <= n; i++) dp[i][0] = 0;
    
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= l ; j++) 
        {
            dp[i][j] = dp[i][j-1];
            if(coins[j-1] <= i)
                dp[i][j] += dp[i-coins[j-1]][j];
        }
    }
    return dp[n][l];
}
