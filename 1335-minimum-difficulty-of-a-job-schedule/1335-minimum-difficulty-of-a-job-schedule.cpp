class Solution {
public:
    
    int dp[305][15];
    // dp[last][d]--> means the last is the index of the last cut and d is the remaining no. of cuts
    int f(int last, int n, vector<int> &job,int d){
        
        if(d==1){
            int maxi=0;
            for(int i=last;i<n;i++) maxi= max(maxi, job[i]);
            return maxi;
        }
        
        if(dp[last][d]!=-1) return dp[last][d];
        
        int res=INT_MAX,maxi=0;
    
        for(int i=last;i<n-d+1;i++){
            maxi= max(maxi, job[i]);
            res= min(res, maxi+ f(i+1, n, job, d-1));
        }
        
        return dp[last][d]=res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n=jobDifficulty.size();
        memset(dp,-1,sizeof(dp));
        if(n<d) return -1;
        return f(0, n, jobDifficulty, d);
        
    }
};