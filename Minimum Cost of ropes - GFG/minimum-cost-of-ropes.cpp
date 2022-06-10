// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ll long long
class Solution

{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        ll ans=0;
        
        for(ll i=0;i<n;i++) pq.push(arr[i]);
        
        while(pq.size()>=2){
            ll top= pq.top();
            pq.pop();
            ll top2= pq.top();
            pq.pop();
            
            ans+=top+top2;
            pq.push(top+top2);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends