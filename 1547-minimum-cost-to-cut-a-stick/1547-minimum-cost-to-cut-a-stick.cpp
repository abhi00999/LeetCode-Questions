class Solution {
public:
    
    int f(int i, int j, int st, int en, vector<int> &cuts, vector< vector<int> > &dp){
        
        // cout<<i<<" "<<j<<'\n';
        if(i>j) return 0;
        int mini=1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        for(int x=i;x<=j;x++){
            int cur= en-st + f(i,x-1, st, cuts[x], cuts, dp) + f(x+1, j, cuts[x], en, cuts, dp);
            mini=min(cur, mini);
        }
        
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        
        sort(cuts.begin(),cuts.end());
        int i=0, j=sz-1, st=0, en=n;
        
        vector< vector<int> > dp(101, vector<int> (101,-1));
        return f(i,j,st,en, cuts, dp);
    
    }
};