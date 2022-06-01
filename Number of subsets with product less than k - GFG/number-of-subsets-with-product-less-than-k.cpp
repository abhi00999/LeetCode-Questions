// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
//   res-1 for the result cz ek empty subset bhi rha hoga

    int res = 0;
    void helper(int arr[],int N , int ind , int k , int pro){
            if(ind == N)
            {
                if(pro <= k){res++;}
                return;
            }
            if(pro > k){
                return;
            }
            helper(arr,N,ind +  1,k,pro);
            helper(arr,N,ind + 1,k , pro * arr[ind]);
    }
    int numOfSubsets(int arr[], int N, int K) {
        res = 0;
        helper(arr,N,0,K,1);
        return res - 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends