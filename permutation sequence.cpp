//The set [1,2,3,...,n] contains a total of n! unique permutations.
//Given n and k, return the kth permutation sequence.


// void permute(string s,vector<string>&v,int l,int r){
//     if(l==r){
//         v.push_back(s);
//     }
//      else
//     {  
//         for (int i = l; i <= r; i++)  
//         {  
  
//             swap(s[l], s[i]);  
//             permute(s,v, l+1, r);  
//             swap(s[l], s[i]);  
//         }  
//     }  
// }
class Solution {
public:
    vector<int> fact;
    
    void findfact(int n)
    {
        fact = vector<int>(n);
        
        fact[0] = 1;
        
        if(n==1) return;
        
        fact[1] = 1;
        for(int i=2; i<n; i++)
            fact[i] = i*fact[i-1];
    }
    
    string getPermutation(int N, int K) {
       //  vector<string>v;
       // string s="";
       //  for(int i=1;i<=n;i++){
       //      s=s+to_string(i);
       //  }
       //  permute(s,v,0,n-1);
       //  sort(v.begin(),v.end());
       //  string res=v[k-1];
       //  return res;
        int n = N-1, k = K-1, nt, kt;
        
        findfact(N);
        vector<int> num(N);
        for(int i=0; i<N; i++)
            num[i] = i+1;
        vector<int>::iterator it; 
        
        string ans = "";
        
        while(n>=0)
        {
            nt = k/fact[n];
            kt = k%fact[n];

            ans += (num[nt]+'0');
            it = num.begin(); 
            num.erase(it+nt);
            n--;
            k = kt;   
        }

        return ans;
    
    }
};
