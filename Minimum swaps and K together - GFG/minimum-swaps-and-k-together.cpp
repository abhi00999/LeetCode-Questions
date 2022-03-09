// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int cnt=0;
        int pref[n]={0};
        for(int i=0;i<n;i++) if(arr[i]<=k) {cnt++; pref[i]++;}
        
        for(int i=1;i<n;i++) pref[i]+=pref[i-1];
        if(cnt==0) return 0;
        int ans=INT_MAX;
        
        for(int i=0;i<=n-cnt;i++){
            
            int val=pref[i+cnt-1]-pref[i];
            if(arr[i]<=k) val++;
            ans= min(ans, cnt-val);
        }
        return ans;
        
    //mistake that i was doing -- val = val=pref[i+cnt-1]-pref[i]+1;
    // but 1 will be added only if current value<=k not everytime
        
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends