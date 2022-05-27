// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
        int min_so_far = INT_MAX, n=a.size();
    	 
    	//stores the maximum sum of subarray ending at the current position
    
        int min_ending_here = INT_MAX;
    
    	//traverse the given array
    
    	for (int i = 0; i < n; i++)
    	{
     
        	// if min_ending_here > 0, then it could not possibly
            // contribute to the minimum sum further
            if (min_ending_here > 0)
                min_ending_here = a[i];
             
            // else add the value arr[i] to min_ending_here   
            else
                min_ending_here += a[i];
             
            // update min_so_far
            min_so_far = min(min_so_far, min_ending_here);  
    	}
    	
    	return min_so_far;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends