class Solution {
public:
    
    int f(int ind, int n, vector<int> &arr, vector<int> &dp, int k){
        
        if(ind==n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int maxi=INT_MIN, ans=INT_MIN;
        
        for(int j=ind; j<min(n, ind+k); j++){
            maxi= max(maxi, arr[j]);
            int curVal= (j-ind+1)*maxi + f(j+1, n, arr, dp, k);
            ans= max(ans, curVal);            
        }
        
        return dp[ind]=ans;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        
        vector<int> dp(n,-1);
        
        return f(0,n, arr, dp, k);
    }
};