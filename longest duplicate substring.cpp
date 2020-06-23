//Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
//Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

int prime = 10000007;
string rabincarp(string s,int mid,vector<int>&p){
    if(mid==0){
        return "";
    }
     int n = s.size(), curr = 0;
     unordered_map<int, vector<int>> hash;
    for(int i = 0; i < mid; i++) {
            curr = (curr * 26 + (s[i]-'a')) % prime;
        }
     hash[curr] = {0};  
      for(int i = mid; i < n; i++) {
          
            curr = ((curr - p[mid-1] * (s[i-mid]-'a')) % prime + prime) % prime;
            curr = (curr * 26 + (s[i]-'a')) % prime;
            
            
            if(hash.find(curr) == hash.end())   
                hash[curr] = {i-mid+1};
            
            else {
                for(int index: hash[curr]) {
                    if(s.substr(index, mid) == s.substr(i-mid+1, mid)) 
                        return s.substr(index, mid);
                }
                
                hash[curr].push_back({i-mid+1});
            }
        }
        return "";      
    
}
class Solution {
public:
    string longestDupSubstring(string S) {
        int n=S.length();
        vector<int>p(n+1,1);
        for(int i=1;i<=n;i++){
            p[i]=(26*p[i-1])%prime;
            
        }
        string res="";
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            string temp=rabincarp(S,mid,p);
            if(temp.size()>res.size()){
                res=temp;
                l=mid+1;
            }
            else{r=mid-1;}
        }
        return res;
}
};
