class Solution {
public:
    //if we take &s and &t then solution gets accepted
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        //j<0 means we have reached end of string t
        if(j<0) return 1;
        
        //i<0 means we have reached end of string s
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j]= f(i-1,j-1,s,t,dp)+ f(i-1, j, s, t, dp);
        
        return dp[i][j]=f(i-1,j,s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return f(n-1,m-1,s,t, dp);
    }
};