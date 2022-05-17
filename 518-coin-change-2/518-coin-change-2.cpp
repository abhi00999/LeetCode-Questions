// dp[ind][target] denotes different no. of ways we can achieve sum==target if we use coins from (0 to ind);

class Solution {
public:
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==0){
            if(amount%coins[ind]==0) return 1;            
            return 0;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int notTake=f(ind-1, amount, coins, dp);
        int take=0;
        
        if(coins[ind]<=amount) take=f(ind, amount-coins[ind], coins, dp);
        
        return dp[ind][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> > dp(n, vector<int>(amount+1,-1));
        
        return f(n-1,amount, coins, dp);
    }
};