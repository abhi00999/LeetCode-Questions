class Solution {
public:
    
    int dp[105][105][22];
    
    int f(int idx, int val, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int prev){
        // cout<<idx<<" "<<val<<'\n';
        if(idx==m && val==target) return 0;
        if(idx==m || val>target)return 1e7;
        
        if(dp[idx][val][prev]!=-1) return dp[idx][val][prev];
        
        if(houses[idx]==0){
            int nval=val,tot=1e7;
            
            for(int i=0;i<n;i++){
                if(prev==i+1)tot= min(tot, cost[idx][i]+ f(idx+1, val, houses, cost, m, n, target, prev));
                else tot= min(tot, cost[idx][i]+f(idx+1, val+1, houses, cost, m, n, target, i+1));
            }
            return dp[idx][val][prev]=tot;
        }
        else if(houses[idx]==prev) return dp[idx][val][prev]=f(idx+1, val, houses, cost, m, n, target, prev);
        return dp[idx][val][prev]=f(idx+1, val+1, houses, cost, m, n, target, houses[idx]);
        
        
        
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans= f(0,0, houses, cost, m, n, target,n+1);
        return (ans>=1e7)? -1: ans;
    }
};