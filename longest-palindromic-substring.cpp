string longestPalindrome(string s) {
        int maxLength = 1, n = s.size(), start=0;
        int table[n][n] ;
        memset( &table[0][0], 0, sizeof(table) );
        for(int i =0; i < n; i++){
            table[i][i] = 1;
        }
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                table[i][i+1] = 1;
                maxLength =2;
                start = i;
            }
        }
        int dist ;
        for(dist =2; dist < n; dist++){
            for(int i = 0, j = i+dist; j<n; i++, j++ ){
                 if(s[i] == s[j] && table[i+1][j-1] == 1){
                    table[i][j] = 1;
                    if(j-i+1 > maxLength){
                        maxLength = j-i+1;
                        start = i;
                    }
                }
            }
        }
       
        string ans = "";
        for(int i = start; i < start + maxLength; i++){
            ans += s[i];
        }
        return ans;
        
        
    }

/*  
 step1. Create Table, Where Row index is Start of palindrome substring
        And     , Column Index is End of Palindrome Substring
 step2. Fill diagonal of table with 1. because i,i is itself a palindrome of length 1;
 step3. Fill (i, i+1 ) by checking adjacent charachters. If they are equal : 1 , else 0;
 step4. For every Distance other substring of length > 2; you need to check two conditions 
          I. Is first and last character are equal : (s[i] == s[j])
          II. Is String inside a palindrome        : (table[i+1][j-1] == 1)
  step5. Repeat step4 for every i,j with constant distance, than increment the distance;
    


      0 1 2 3 4 5 6 7
str = a a a a b b a a
          i
	                  j
n = 8
dist = 6
table
j->  0 1 2 3 4 5 6 7
i 0| 1 1 1 1 0 0 0 0
i 1| 0 1 1 1 0 0 0 0
i 2| 0 0 1 1 0 0 0 1
i 3| 0 0 0 1 0 0 1 0
i 4| 0 0 0 0 1 1 0 0
i 5| 0 0 0 0 0 1 0 0
i 6| 0 0 0 0 0 0 1 1
i 7| 0 0 0 0 0 0 0 1
maxLength = 6, start = 2

Example 2:
      0 1 2 3
str = c c c
      i
          j
n = 3
dist = 2
table
j->  0 1 2 
i 0| 1 1 1 
i 1| 0 1 1 
i 2| 0 0 1 
i 3| 0 0 0 

maxLength = 3, start = 0
      
*/
