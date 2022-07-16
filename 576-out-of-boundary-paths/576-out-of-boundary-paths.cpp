class Solution {
public:
    int dp[100][100][100],mod;
    
    int f(int r, int c, int m, int n, int maxMove){
        if(maxMove<0){
            return 0;
        }
        if(r==m || c==n || r<0 || c<0){
            return 1;
        }
        
        if(dp[r][c][maxMove]!=-1) return dp[r][c][maxMove];
        
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        
        long long ans=0;
        
        for(int i=0;i<4;i++){
            ans+= f(r+dx[i], c+dy[i], m, n, maxMove-1)%mod; 
        }
        
        return dp[r][c][maxMove]=ans%mod;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1, sizeof(dp));
        mod=1e9+7;
        return f(startRow, startColumn, m, n, maxMove);
    }
};