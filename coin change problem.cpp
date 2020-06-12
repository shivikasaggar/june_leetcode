
//You are given coins of different denominations and a total amount of money. 
//Write a function to compute the number of combinations that make up that amount. 
//You may assume that you have infinite number of each kind of coin.
int helper(vector<int>&coins,int m,int amount){
     int table[amount+1]; 
 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    for(int i=0; i<m; i++) 
        for(int j=coins[i]; j<=amount; j++) 
            table[j] += table[j-coins[i]]; 
  
    return table[amount];
}

    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        return helper(coins,m,amount);
        
    }
