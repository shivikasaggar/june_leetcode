//The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
//The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially 
//positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
//The knight has an initial health point represented by a positive integer.
// If at any point his health point drops to 0 or below, he dies immediately.
//Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering
// these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
//In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

int helper(vector<vector<int> >&d,int m,int n){
    vector<vector<int > >v(m,vector<int>(n));
    v[m-1][n-1] = d[m-1][n-1] > 0? 1: 
                   abs(d[m-1][n-1]) + 1; 
  
    
    for (int i = m-2; i >= 0; i--) 
         v[i][n-1] = max(v[i+1][n-1] - d[i][n-1], 1); 
    for (int j = n-2; j >= 0; j--) 
         v[m-1][j] = max(v[m-1][j+1] - d[m-1][j], 1); 
  
    
    for (int i=m-2; i>=0; i--) 
    { 
        for (int j=n-2; j>=0; j--) 
        { 
            int min_points_on_exit = min(v[i+1][j], v[i][j+1]); 
            v[i][j] = max(min_points_on_exit - d[i][j], 1); 
        } 
     } 
  
     return v[0][0]; 
}
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        if(m==0){
            return 0;
        }
        int n=dungeon[0].size();
        return helper(dungeon,m,n);
    }
};
