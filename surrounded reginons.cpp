//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
void dfs(vector<vector<char> >&board,int i,int j,int m,int n){
    if(i<0 || j<0 || i>=m || j>=n || board[i][j] != 'O') 
        return;
        board[i][j] = 'y';
        dfs(board, i-1, j, m, n);
        dfs(board, i+1, j, m, n);
        dfs(board, i, j-1, m, n);
        dfs(board, i, j+1, m, n);
}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
          if(m == 0) return;  
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,m,n);
            }
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1,m,n);
            }
        }
         for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i,m,n);
            }
            if(board[m-1][i]=='O'){
                dfs(board,m-1,i,m,n);
            }
        }
          for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == 'y')
                 board[i][j] = 'O';
         }
    }  
};
