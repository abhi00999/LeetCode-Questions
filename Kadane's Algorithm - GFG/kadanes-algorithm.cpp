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
        //stores maximum sum subarray found so far
	 
    	long long max_so_far = 0;
    	 
    	//stores the maximum sum of subarray ending at the current position
    
        long long max_ending_here = 0,cnt=0,maxi=-1e13;
    
    	//traverse the given array
    
    	for (int i = 0; i < n; i++)
    	{
        	/* update maximum sum of subarray "ending" at index i (by adding the current element to maximum sum ending at previous index i-1) */
    
        	max_ending_here = max_ending_here + arr[i];
     
        	/* if maximum sum is negative, set it to 0 (which represents an empty sub-array) */
        	if(max_ending_here < 0)
        	{
            	max_ending_here = 0;
        	}
         	 
        	//update result if current subarray sum is found to be greater
        	if(max_so_far < max_ending_here)
        	{
            	max_so_far = max_ending_here;    
        	}
        	
        	//to cater for the case if all elements are negative
        	if(arr[i]<0) {cnt++; maxi= max(maxi, (long long)arr[i]);}
    	}
    	
    	if(cnt==n) return maxi;
    	return max_so_far;
        
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