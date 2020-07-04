//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time. 
//The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//How many possible unique paths are there?
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0){
            return 0;
        }
        // if(m==1||n==1){
        //     return 1;
        // }
        // return uniquePaths(m-1,n)+uniquePaths(m,n-1);
        vector<vector<int> >h(m+1,vector<int>(n+1,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                h[i][j]=h[i-1][j]+h[i][j-1];
            }
        }
        return h[m-1][n-1];
    }
};
