//Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
class Solution {
public:
    int numTrees(int n) {
        vector<int>v(n+1,1);
        for(int i=1;i<=n;i++){
            v[i]=0;
            for(int j=1;j<=i;j++){
                v[i]=v[i]+v[i-j]*v[j-1];
            }
        }
        return v[n];
    }
};
