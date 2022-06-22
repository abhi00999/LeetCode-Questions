class Solution {
public:
    long long f(int last, int len, int n, vector<vector<long long> > &dp){
        if(len==n) { 
            return (long long)1;
        }
        
        int mod=1e9+7;
        if(dp[last][len]!=-1) return dp[last][len];
        
        if(last==5) return 0;
        else{
            if(last==0){
                return dp[last][len]=(f(4, len+1, n,dp)%mod+ f(6, len+1, n, dp)%mod+mod)%mod;
            }
            if(last==1){
                return dp[last][len]=(f(6, len+1, n, dp)%mod+ f(8, len+1, n, dp)%mod+mod)%mod;
            }
            if(last==2){
                return dp[last][len]=(f(7, len+1, n, dp)%mod+ f(9, len+1, n,dp)%mod+mod)%mod;
            }
            if(last==3){
                return dp[last][len]=(f(4, len+1, n, dp)%mod+ f(8, len+1, n, dp)%mod+mod)%mod;
            }
            if(last==4){
                return dp[last][len]=(f(0, len+1, n,dp)%mod+ f(3, len+1, n,dp)%mod+f(9,len+1,n,dp)%mod+mod)%mod;
            }
            if(last==6){
                return dp[last][len]=(f(0, len+1, n, dp)%mod+ f(1, len+1, n, dp)%mod+f(7,len+1,n,dp)%mod+mod)%mod;
            }
            if(last==7){
                return dp[last][len]=(f(6, len+1, n,dp)%mod+ f(2, len+1, n,dp)%mod+mod)%mod;
            }
            if(last==8){
                return dp[last][len]=(f(1, len+1, n,dp)%mod+ f(3, len+1, n,dp)%mod+mod)%mod;
            }
            if(last==9){
                return dp[last][len]=(f(2, len+1, n,dp)%mod+ f(4, len+1, n,dp)%mod+mod)%mod;
            }
        }
        return 0;
    }
    int knightDialer(int n) {
        long long ans=0;
        int mod=1e9+7;
        
        vector< vector<long long> > dp(10, vector<long long>(n+1, -1));
        for(int i=0;i<=9;i++){
            ans+=(f(i,1,n,dp)+mod)%mod;
        }
        
        if(ans<0) return (ans+mod)%mod;
        return (ans)%mod;
    }
};