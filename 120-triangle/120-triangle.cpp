class Solution {
public:
    int f(int x, int y, vector<vector<int>>& v, int n, vector<vector<int>>&dp){
        if(x==n) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int left= v[x][y] + f(x+1, y, v, n, dp);
        int right= v[x][y] + f(x+1, y+1, v, n, dp);
        
        return dp[x][y]= min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int> > dp(n, vector<int> (n,-1));
        return f(0,0, triangle, n, dp);
    }
};