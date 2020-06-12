//If there are lots of incoming S, say S1, S2, ... ,
// Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
bool isSubsequence(string s, string t) {
       int i,j,n,m;
        n = s.size();
        m = t.size();
        i=j=0;
        
        while(i<n and j<m)
        {
            if(s[i]==t[j])      
                i++;
            j++;
        }
        
        return i==n;  
    }
