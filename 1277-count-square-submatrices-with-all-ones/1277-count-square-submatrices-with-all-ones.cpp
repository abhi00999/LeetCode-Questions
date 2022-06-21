// For eg:
// For matrix= 
// 0 1 1 1
// 1 1 1 1
// 0 1 1 1
// Dp will be
// 0 3 2 1
// 1 2 2 1
// 0 1 1 1
        
class Solution {
public:
    int dp[500][500];
    int f(int x, int y, int row, int col, vector<vector<int>>& matrix){
        if(x>=row || y>=col) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int left= f(x, y+1, row, col, matrix);
        int diag= f(x+1, y+1, row, col, matrix);
        int down= f(x+1, y, row, col, matrix);
        
        int mini= min({left, diag, down});
        if(matrix[x][y]==0) return dp[x][y]=0;
        
        int side= 1+mini;
        return dp[x][y]=side;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        
        int n=matrix.size(), m=matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int ans=0;
        f(0,0, n, m, matrix);
        
        // dp[i][j] denotes maximum possible side of square starting from that point
        // It also denotes how many square submatrices end there(for this question we sum all dp[i][j])
        
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans+=dp[i][j];
        return ans;
    }
};