// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind, int target, int n, int arr[], vector<vector<int>> &dp){
        
        if(target==0) return 1;
        
        if(ind==n-1) return (target==arr[ind])?1:0;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int pick=0, nonpick=0;
        
        nonpick= f(ind+1, target, n, arr,dp);
        
        if(arr[ind]<=target) pick= f(ind+1, target-arr[ind], n, arr,dp);
        
        return dp[ind][target]= pick || nonpick;
        
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        
        if(sum%2==1) return 0;
        
        int target=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return f(0, target, N, arr,dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends