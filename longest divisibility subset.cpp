//Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
//Si % Sj = 0 or Sj % Si = 0.
//If there are multiple solutions, return any subset is fine.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n=nums.size();
        if(n==0){
            return {};
        }
    sort(nums.begin(), nums.end()); 
   
    vector <int> d(n, 1); 
    vector <int> prev(n,-1); 
  
    int indx = 0; 
    for (int i=1; i<n; i++) 
    { 
        for (int j=0; j<i; j++) 
        { 
            if (nums[i]%nums[j] == 0) 
            { 
                if (d[i] < d[j] + 1) 
                { 
                    d[i] = d[j]+1; 
                    prev[i] = j; 
                } 
            } 
        } 
        if (d[indx] < d[i]) 
            indx = i; 
    } 
   vector<int>res;
    int k = indx; 
    while (k >= 0) 
    { res.push_back(nums[k]);
        k = prev[k]; 
    } 
        return res;
} 
    
};
