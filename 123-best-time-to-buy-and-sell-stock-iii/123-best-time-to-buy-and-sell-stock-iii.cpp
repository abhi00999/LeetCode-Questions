class Solution {
public:
    
    int dp[100005][2][2];
    int f(int ind, int buy, int tr, int k, vector<int> &prices, int n){
        
        if(ind>=n) return 0;
        if(tr==k) return 0;
        
        if(dp[ind][buy][tr]!=-1) return dp[ind][buy][tr];
        
        int op1, op2;
        //buy=1 means we can buy
        if(buy){
            op1= -prices[ind] + f(ind+1, 0, tr, k, prices, n);
            op2= 0+ f(ind+1, 1, tr, k, prices, n);
        }
        
        else{
            op1= prices[ind]+ f(ind+1, 1, tr+1, k, prices, n);
            op2= 0+ f(ind+1, 0, tr, k, prices, n);
        }
        
        return dp[ind][buy][tr]=max(op1, op2);
    }
    
    int maxProfit1(int k, vector<int>& prices) {
        int n=prices.size(), tr=0, buy=1;
        memset(dp,-1,sizeof(dp));
        //f(0, buy, tr, k, prices) will return maximum profit that can be achieved if we start from 0th index and 
        //we have option of buying(buy=1) and at max k transactions(current transaction = 0).
        return f(0, buy, tr, k, prices, n);
    }
    
    int maxProfit(vector<int>& prices) {
        return maxProfit1(2, prices);
    }
};