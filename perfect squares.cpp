//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            int minel=i;
            int y=1,sq=1;
            while(sq<=i){
                minel=min(minel,1+dp[i-sq]);
                y++;
                sq=y*y;
            }
            dp[i]=minel;
        }
        return dp[n];
    }
};
