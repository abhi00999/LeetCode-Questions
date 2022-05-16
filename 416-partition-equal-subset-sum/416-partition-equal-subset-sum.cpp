class Solution {
public:
    int f(int ind, int target, int n, vector<int> &arr, vector<vector<int>> &dp){
        
        if(target==0) return 1;
        
        if(ind==n-1) return (target==arr[ind])?1:0;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int pick=0, nonpick=0;
        
        nonpick= f(ind+1, target, n, arr,dp);
        
        if(arr[ind]<=target) pick= f(ind+1, target-arr[ind], n, arr,dp);
        
        return dp[ind][target]= pick || nonpick;
        
    }
    
    bool canPartition(vector<int>&arr) {
        int sum=0,N=arr.size();
        for(int i=0;i<N;i++) sum+=arr[i];
        
        if(sum%2==1) return 0;
        
        int target=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return f(0, target, N, arr,dp);
    }
};