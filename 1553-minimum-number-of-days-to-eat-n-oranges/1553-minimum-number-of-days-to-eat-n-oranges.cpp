class Solution {
public:
    map<int,int> dp;
    int f(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(dp.count(n)) return dp[n];
        
        int op1=1e9, op2=1e9, op3=1e9;
        
        if(n%2==0) op2= 1+ f(n/2);
        else op2= 2+ f((n-1)/2);
        
        if(n%3==0) op3= 1+ f(n/3);
        else if(n%3==1 ) op3= 2+ f((n-1)/3);
        else  op3= 3+ f((n-2)/3);
        
        
        return dp[n]= min( op2, op3);
        
    }
    int minDays(int n) {
        
        return f(n);
    }
};