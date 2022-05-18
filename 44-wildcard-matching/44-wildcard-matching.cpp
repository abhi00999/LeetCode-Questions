class Solution {
public:
    bool f(int i, int j, string &pattern, string &text, vector<vector<int> > &dp){
        
        // both strings exhausted
        if(i<0 && j<0) return true;
        
        // pattern exhausted but string is already there
        if(i<0 && j>=0) return false;
        
        if(j<0 && i>=0){
            // in this case text has length 0, so it will match with pattern only of it contains all stars
            // so we run a for loop
            
            for(int ii=0;ii<=i;ii++) if(pattern[ii]!='*') return false;
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(pattern[i]==text[j] || pattern[i]=='?'){
            return dp[i][j]=f(i-1, j-1, pattern, text, dp);
        }
        
        //in the below case we are considering if '*' corresponds to a zero or single character, it will deal with all 
        //cases of all length too
        if(pattern[i]=='*'){
            return dp[i][j]=f(i-1,j,pattern, text, dp) | f(i, j-1, pattern, text, dp);
        }
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        
        vector<vector<int> > dp(n, vector<int>(m,-1));
        return f(n-1,m-1, p, s, dp);
    }
};