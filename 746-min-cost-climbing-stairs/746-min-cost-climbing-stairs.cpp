class Solution {
public:
    int dp[1001];
    
    int calc(vector<int>& cost,int n,int ind){
        if(ind>=n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int cur= cost[ind];
        
        return dp[ind]= min(cur+calc(cost,n,ind+1),cur+calc(cost,n,ind+2));
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        
        return min(calc(cost,n,0),calc(cost,n,1));
    }
};