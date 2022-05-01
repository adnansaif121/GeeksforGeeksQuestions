int longestUniqueSubsttr(string s){
        //code
       // This is in linear time
        vector<int> lastIndex(256, -1);
        int i =0, j = 0, n = s.size();
        int window_size = 0;
        
        for(j = 0; j < n; j++){
            i = max(i, lastIndex[s[j]] + 1);
            window_size = max(window_size, j-i+1);
            lastIndex[s[j]] = j;
        }
        
         return window_size;
      }
        // This Works but not optimal
        // int maxLen = 0, n = s.size();
        // for(int i = 0; i< n ; i++){
        //     unordered_map<char, int> m;
        //     int maxTillNow = 0;
        //     int j = i;
        //     while(j < n){
        //         if(m.find(s[j]) == m.end()){
        //             maxTillNow++;
        //             m[s[j]] ++;
        //             if(maxTillNow > maxLen)maxLen = maxTillNow;
        //             j++;
        //         }       
        //         else {
        //             break;
        //         }
        //     }
        // }
        // return maxLen;

// EXPLANATION
/*
    1. Create Two pointers i and j;
    2. i will be the starting index of our window.
    3. j will be the last index of window.
    4. at every iteration we note 3 things:
        I. i : we check if s[j] is already been encountered or not(We check this using lastIndex Array, if lastIndex[s[j]] returns -1 means not encountrered, else number means its last occurence index)
                  if encountered : then we remove the last occurence of s[i] out of window : i = lastIndex[s[j]] + 1;
                  else : i remains the same.
           <> i = max[i, lastIndex[s[j]];
        II. window_size: according to i, window size increses or remains same. window size is just the distance between i and j index;
           <> window_size = max[window_size, j-i+1];
        III. lastIndex of s[j] : we update the last Index of s[j] to j;
           <> lastIndex[s[j]] = j;
     5.At last return window_size;
     
     
     
     Dry Run Example:
     ////////////////////////////     
     abcabcdd
            i
            j

      w_size = 0 = max(w_size, j-i+1)
      .............(0, 0-0+1) = 1
      .............(1, 1-0+1) = 2
      .............(2, 2-0+1) = 3
      .............(3, 3-1+1) = 3
      .............(3, 4-2+1) = 3
      .............(3, 5-3+1) = 3
      .............(3, 6-3+1) = 4
      .............(4, 0+1)   = 4
      i = 0 = max(i, lastIndex[str[j]]+1)
      ...........(0, -1+1) = 0
      ...........(0, -1+1) = 0
      ...........(0, -1+1) = 0
      ...........(0,  0+1) = 1
      ...........(1,  1+1) = 2
      ...........(2,  2+1) = 3
      ...........(3, -1+1) = 3
      ...........(3, 6+1) = 7

      lastIndex
      a : 3
      b : 4
      c : 5
      d : 6
     
*/
