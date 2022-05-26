// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

// we know the usual answer is, In a sorted array, difference between (first element+k ) and (last element -k), is maximum
// adding k and subtracting k is the only way we can bring them closer and thus minimise the difference between them, which is the maximum difference.
// But in cases where K is in order of elements and adding or subtracting K, changes the sorted order, and largest no longer remain largest, and smallest no longer the smallest, then we have to find the correct largest and smallest element.

// we keep them in mi, and ma, they are so far seen smallest(non-negative) and largest values
// and also, we always can either add k or subtract k from a number, so we try both on arr[i] and collect smallest and largest, 
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        
        int smallest=arr[0]+k;
        int largest= arr[n-1]-k;
        int mini,maxi;
        
        for(int i=0;i<n-1;i++){
            maxi= max(largest, arr[i]+k);
            mini= min(smallest, arr[i+1]-k);
            
            if(mini<0) continue;
            ans= min(ans, maxi-mini);
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends