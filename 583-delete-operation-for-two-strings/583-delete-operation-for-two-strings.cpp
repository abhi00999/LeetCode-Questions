class Solution {
public:
    int dp[505][505];
    
    int f(string s1, string s2, int i, int j){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]= 1+ f(s1, s2, i-1, j-1);
        
        return dp[i][j]= max(f(s1,s2, i-1,j), f(s1,s2,i,j-1));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        memset(dp,-1,sizeof(dp));
        return n+m- 2*f(word1, word2, n-1, m-1);
    }
};