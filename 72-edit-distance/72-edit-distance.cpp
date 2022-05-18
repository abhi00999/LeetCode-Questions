class Solution {
public:
    int dp[505][505];
    int f(int i,int j, string s, string t){
        
        if(j<0) return i+1;
        if(i<0) return j+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=f(i-1,j-1,s,t);
        
//op1-> insertion
//op2->deletion
//op3->replacement
        int op1= 1+f(i,j-1,s,t), op2= 1+f(i-1,j,s,t), op3= 1+f(i-1,j-1,s,t);
        
        return dp[i][j]=min({op1,op2,op3});
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        if(n==0) return m;
        if(m==0) return n;
        memset(dp,-1,sizeof(dp));
        return f(n-1, m-1, word1, word2 );
    }
};