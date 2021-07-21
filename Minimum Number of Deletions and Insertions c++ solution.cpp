int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	   // Find the largest common subsequence, then the extra charachters from
	   //the str1 needs to be deleted and extra charachters from str2 needs to be 
	   //inserted.
	   
	   //Find LCS
	   int m = str1.size();
	   int n = str2.size();
	   
	   int dp[m+1][n+1];
	   
	   for(int i = 0; i <= m ; i++) dp[i][0] = 0;
	   for(int j = 0; j <= n ; j++) dp[0][j] = 0;
	   
	   for(int i = 1; i <= m ; i++)
	   {
	       for(int j = 1; j <= n ; j++)
	       {
	           if(str1[i-1] == str2[j-1])
	                dp[i][j] = 1 + dp[i-1][j-1];
	           else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	       }
	   }
	   
	   return (m + n) - (2 * dp[m][n]);
	} 
