class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        int dp[n][n];
        for(int i=0;i<n;i++)
            dp[n-1][i]=m[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                dp[i][j]=m[i][j];
                int mn=dp[i+1][j];
                if(j+1 < n)
                    mn=min(mn,dp[i+1][j+1]);
                if(j-1 >= 0)
                    mn=min(mn,dp[i+1][j-1]);
                dp[i][j]+=mn;
            }
        }
        int mini=dp[0][0];
        for(int i=1;i<n;i++)
            mini=min(mini,dp[0][i]);
        return mini;
    }
};
