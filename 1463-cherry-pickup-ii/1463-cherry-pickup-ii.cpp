class Solution {
public:
    int dp[75][75][75];
    int f(int i, int j1, int j2, int r, int c, vector<vector<int> > &grid, vector < vector < vector < int >>> & dp){
        //if any of the two cross the borders then that path is invalid 
        if(j1<0 || j2<0 || j1>c-1 || j2>c-1) return -1e9;
        
        // we reach the last row that means we have found one of our possible answers
        if(i==r-1){
            //if both reach same cell then it is counted only once else count separately
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        //after this explore all paths of robots simultaneously and take maximum of all
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value;
                
                if(j1==j2) value=grid[i][j1];
                else value= grid[i][j1]+grid[i][j2];
                
                value+=f(i+1,j1+dj1, j2+dj2, r, c, grid, dp); 
                maxi=max(value,maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int> (m, -1)));
        return f(0,0,m-1, n, m, grid, dp);
    }
};