class Solution {
public:
    map<pair<int,int>,int> m;
    int f(int ind, int sum, int target, vector<int> &nums, vector<vector<int>> &dp){
        
        // if(sum==target) return 1;
        if(ind<0){
            if(sum==target)return 1;
            return 0;
        }
        
        if(m.find({ind,sum})!=m.end()) return m[{ind,sum}] ;
        int pos= f(ind-1, sum+nums[ind], target, nums, dp);
        int neg= f(ind-1, sum-nums[ind], target, nums, dp);
        
        return m[{ind,sum}]=pos+neg;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0;
        vector<vector<int>> dp(n, vector<int>(1001,-1));
        
        return f(n-1, sum, target, nums, dp);
    }
};