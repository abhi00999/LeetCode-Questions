// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1005][1005];
    int f(int ind, int price[], int n, int cur){
        if(ind==n) return 0;
        
        if(dp[ind][cur]!=-1) return dp[ind][cur];
        int take=INT_MIN,notTake=INT_MIN;
        if(cur>=ind+1){
            take= price[ind]+ f(ind, price, n, cur-ind-1);
        }
        
        notTake= f(ind+1, price, n, cur);
        
        return dp[ind][cur]=max(take, notTake);
        
    }
    int cutRod(int price[], int n) {
        //code here
        memset(dp,-1, sizeof(dp));
        return f(0, price, n, n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends