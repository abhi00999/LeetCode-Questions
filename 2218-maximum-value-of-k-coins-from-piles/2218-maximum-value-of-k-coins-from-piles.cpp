class Solution {
public:
    // int maxi;
    int dp[2005][2005];
    int calc(vector<vector<int> > &piles,int k,int ind){
        if(ind>=piles.size()) return 0;
        
        int maxi= 0,non_choose=0,choose=0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        
        non_choose= max(non_choose, calc(piles,k,ind+1));
        
        for(int i=0;i<piles[ind].size();i++){
            choose+=piles[ind][i];
            if(k-(i+1)>=0){
                maxi= max(maxi, choose+ calc(piles,k-(i+1), ind+1));
            }
        }
        
        maxi=max(maxi,non_choose);
        return dp[ind][k]=maxi;
        
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));        
        int ind=0;
        
        return calc(piles,k,ind);
    }
};