class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> dp(n,n+1);
        
        dp[0]=0;
    
        
        for(int i=0;i<n;i++){
            int start= i;
            int end= min(nums[i]+i, n-1);
            
            for(int j=start;j<=end;j++){
                dp[j]= min(dp[j], 1+dp[i]);
            }
        }
        
        return (dp[n-1]==n+1)? -1:dp[n-1];
    }
};