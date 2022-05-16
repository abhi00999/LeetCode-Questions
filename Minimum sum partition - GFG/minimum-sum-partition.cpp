// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totSum=0;
	   // sort(arr,arr+n);
	    for(int i=0;i<n;i++) totSum+=arr[i];
	    int k=totSum;
	    vector< vector<bool> > dp(n, vector<bool>(k+1,false));
	    
	    
	   //dp[i][j]=true if a sum of j is possible from arr(0,i);
	    for(int i=0;i<n;i++) dp[i][0]=true;
	    dp[0][arr[0]]=true;
	    
	    for(int i=1;i<n;i++){
	        for(int target=1;target<=k;target++){
	            bool notTake= dp[i-1][target];
	            bool take=false;
	            
	            if(arr[i]<=target) take= dp[i-1][target-arr[i]];
	            
	            dp[i][target]= take | notTake;
	        }
	    }
	    
	    int mini=1e9;
	    for(int s=0;s<=totSum;s++){
	        if(dp[n-1][s]){
	            mini= min(mini, abs(totSum-2*s));
	        }
	    }
	    
	    return mini;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends