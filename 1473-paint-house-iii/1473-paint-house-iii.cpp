class Solution {
public:
    
    int dp[105][105][50];
    
    int f(int idx, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int prev){
        // cout<<idx<<" "<<target<<"\n";
        if(target<0) return 1e7;
        if(idx == m)      // If we have visited all houses
        {
            if(target == 0)       // If neighbours are same as required, then no more cost is required.
                return 0;
            return 1e7;     // If neighbours are not same, then this build is not valid.
        }
        
        if(dp[idx][target][prev]!=-1) return dp[idx][target][prev];   
        
        if(houses[idx] != 0)       // If house is already coloured.
        {
            return dp[idx][target][prev] = f(idx+1,houses, cost, m ,n, target-(prev!=houses[idx]), houses[idx]);
        }
        int ans = INT_MAX;         // If we are colouring house, then find minimum cost.
        for(int i=1;i<=n;i++)
        {
            ans = min(ans,cost[idx][i-1]+f(idx+1,houses, cost, m ,n, target-(prev!=i), i));
        }
        return dp[idx][target][prev] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans= f(0, houses, cost, m, n, target,40);
        cout<<ans<<" "; 
        return (ans>=1e7)? -1: ans;
    }
};