class Solution {
public:
    int dp[100000];
    
    int fun(map<int,int> &m, int ind, vector<int> v,int last){
        if(ind>=v.size()) return 0;
        
        if(last+1==v[ind]) return fun(m,ind+1,v,-1);
        if(dp[ind]!=-1) return dp[ind];
        
        
        int take= m[v[ind]]*v[ind]+ fun(m,ind+1,v,v[ind]);
        int not_take= fun(m,ind+1,v,-1);
        
        
        return dp[ind]=max(take, not_take);
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int, int > m;
        vector<int> tmp;
        
        memset(dp,-1,sizeof(dp));
        
        for(auto it: nums) m[it]++;        
        for(auto it: m) tmp.push_back(it.first);
        
        int ans= fun(m, 0,tmp,-1);
        return ans;
    }
};