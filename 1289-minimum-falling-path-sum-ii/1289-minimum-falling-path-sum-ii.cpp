class Solution {
public:
    
    int f(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(row==grid.size()) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        
        int cur= grid[row][col];
        int val=INT_MAX;
        for(int j=0;j<grid.size();j++){
            if(j==col) continue;
            int res= f(row+1, j, dp, grid);
            val= min(val, res);
        }
        
        if(val==INT_MAX) return dp[row][col]=cur;
        return dp[row][col]=cur+val;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), res=INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            res= min(res, f(0,j, dp, grid));
        }
        return res;
    }
};