class Solution {
public:
    // int dp[400][400];
    int f(int ind, int m, int n, vector<pair<int,int>> &v, vector<vector<vector<int>>> &dp){
        // cout<<m<<" "<<n<<"\n";
        if(ind==v.size()) return 0;
        
        if(dp[m][n][ind]!=-1) return dp[m][n][ind];
        int notTake= 0+ f(ind+1, m, n,v, dp);
        
        int take=INT_MIN;
        
        if(v[ind].first<=n && v[ind].second<=m){
            take= 1+ f(ind+1, m-v[ind].second, n-v[ind].first, v, dp);
        }
        
        return  dp[m][n][ind]=max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v;
        vector<vector<vector<int>>> dp(105, vector<vector<int>>(105, vector<int>(605,-1)));
        for(auto it: strs){
            string s= it;
            int one=0,zero=0;
            for(auto t: s){
                if(t=='1') one++;
                else zero++;
            }
            
            v.push_back({one,zero});
        }
        // for(auto it: v ) cout<<it.first<<" "<<it.second<<'\n';
        
        return f(0, m, n, v, dp);
    }
};