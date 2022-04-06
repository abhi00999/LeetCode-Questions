// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool calc( int val, int arr[], int n, int m){
        
        int cnt=0,sum=0;
        
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=val)sum+=arr[i];
            else if(arr[i]>val) return false;
            
            else{
                cnt++;
                sum=arr[i];
            }
        }
        cnt++;
        if(cnt<=m) return true;
        return false;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int left=0,right=1e11;
        int ans;
        while(left<=right){
            int mid= (left+right)/2;
            
            if(calc(mid, A, N,M)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends