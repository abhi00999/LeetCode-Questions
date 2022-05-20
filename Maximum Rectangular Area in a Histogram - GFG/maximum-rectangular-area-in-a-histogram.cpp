// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s;
        long long ans=-1e15;
        for(int i=0;i<=n;i++){
            while(!s.empty() &&  (i==n ||arr[s.top()]> arr[i])){
                long long height= arr[s.top()];
                s.pop();
                
                long long width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                
                ans=max(ans, height*width);
            }
            
            s.push(i);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends