class Solution {
public:
    int dp[500][500];
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size(),m=grid[0].size();
        
        // dp[0][0]=grid[0][0];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                
                else if(i==0) dp[i][j]= grid[i][j]+dp[i][j-1];
                
                else if(j==0) dp[i][j]= grid[i][j]+dp[i-1][j];
                
                else dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        
        return dp[n-1][m-1];
    }
    
};