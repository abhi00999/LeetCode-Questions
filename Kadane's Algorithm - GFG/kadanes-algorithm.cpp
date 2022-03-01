// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxi=0,curr_max=0,cnt=0,maxi1=-1e14;
        
        for(int i=0;i<n;i++){
            if(arr[i]<0) cnt++;
            maxi1= max(maxi1,(long long)arr[i]);
            
            curr_max+=arr[i];
            if(curr_max<0) curr_max=0;
            maxi= max(curr_max,(long long)maxi);
        }
        
        if(cnt==n) return maxi1;
        return maxi;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends