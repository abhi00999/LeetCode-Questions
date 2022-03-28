// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int calc(int dp[], int ind,int n, int arr[]){
        if(ind>=n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int pick= arr[ind]+ calc(dp, ind+2, n, arr);
        
        int non_pick= calc(dp,ind+1, n, arr);
        
        dp[ind]=max(pick,non_pick);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        memset(dp,-1,sizeof(dp));
        
        calc(dp,0,n,arr);
        
        return dp[0];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends