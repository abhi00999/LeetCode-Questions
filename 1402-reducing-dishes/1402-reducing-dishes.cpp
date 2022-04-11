class Solution {
public:
    int dp[505][505];
    int fun(vector<int> &v, int ind, int time){
        
        if(ind>=v.size()) return 0;
        if(dp[ind][time]!=-1) return dp[ind][time];
        
        int pick= v[ind]*time + fun(v, ind+1, time+1);
        int non_pick= fun(v, ind+1, time);
        
        return dp[ind][time]=max(pick,non_pick);
    }
    
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        
        memset(dp,-1,sizeof(dp));
        int ans= fun(v, 0,1);
        return ans;
    }
};