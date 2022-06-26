class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        size = multipliers.size();
        nums_size = nums.size();
        vector<vector<int>> dp(1005, vector<int>(1005,INT_MAX));
        return helper(nums, multipliers, 0, 0, dp);
    }

    int helper(vector<int>& nums, vector<int>& multipliers, int L, int R, vector<vector<int>> &dp){
        // L represents the left we have consumed
        // R represents the right we have consumed
        
        if(L + R >= size) return 0;
        if(dp[L][R]!=INT_MAX) return dp[L][R];
        
        int left=helper(nums, multipliers,L+1, R, dp) + nums[L] * multipliers[L+R];
        int right=helper(nums, multipliers, L, R+1, dp) + nums[nums_size-R-1] * multipliers[L+R];

        return dp[L][R]= max(left, right);
    }
private:
    int size, nums_size; 
};