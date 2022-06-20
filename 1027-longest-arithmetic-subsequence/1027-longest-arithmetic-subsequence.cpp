class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > dp(n, vector<int>(2000, 0));
        int res=2;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+500;
                
                // if at index j there was already a sequence ending with difference "diff" then we just add it to 
                // the current index 
                if(dp[j][diff]){
                    dp[i][diff]=1+dp[j][diff];    
                }
                
                // Else we form a new sequence with length of 2 at current index with diff= "diff"
                else dp[i][diff]=2;
                res= max(res, dp[i][diff]);
            }
        }
        return res;
    }
};