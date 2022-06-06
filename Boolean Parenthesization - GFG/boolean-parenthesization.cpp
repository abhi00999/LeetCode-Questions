// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[205][205][2];
    
    int f(int left, int right, string &s, int need){
        
        if(left>right) return 0;
        if(left==right){
            // return 1 only if we require what is there else return 0;
            // means if we want 1 and there is 'T' present then return 1;
            // similarly if we want 0 and there is 'F' present then return 1;
            if(need==1) return s[left]=='T';
            if(need==0) return s[left]=='F';
        }
        
        
        if(dp[left][right][need]!=-1) return dp[left][right][need];
        
        int ways=0,x=1003;
        int st=left+1, en=right-1;
        for(int i= st; i<=en;i+=2){
            int lt= f(left, i-1, s, 1)%x;
            int lf= f(left, i-1, s, 0)%x;
            int rt= f(i+1, right, s, 1)%x;
            int rf= f(i+1, right, s, 0)%x;
            
            if(s[i]=='&'){
                if(need)ways+= ((lt*rt)%x)%x;
                else ways+= ((lt*rf)%x + (lf*rt)%x + (lf*rf)%x)%x;
            }
            if(s[i]=='|'){
                if(need)ways+= ((lt*rt)%x + (lf*rt)%x + (lt*rf)%x)%x;
                else ways+= ((lf*rf)%x)%x;
            }
            
            if(s[i]=='^'){
                if(need) ways+= ((lt*rf)%x + (lf*rt)%x)%x;
                else ways+= ((lf*rf)%x + (lt*rt)%x)%x;
            }
        }
        
        return dp[left][right][need]=ways%x;
    }
    int countWays(int N, string S){
        // code here
        memset(dp, -1, sizeof(dp));
        int left=0, right=N-1;
        return f(left, right,  S, 1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends