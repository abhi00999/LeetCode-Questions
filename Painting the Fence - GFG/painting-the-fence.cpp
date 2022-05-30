// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int ans;
    void f(int ind, int n, int k, vector<int> &v){
        if(v.size()==n) {
            ans++; 
            return;
            
        }
        
        if(v.size()<2){
            for(int i=1;i<=k; i++){
                v.push_back(i);
                f(ind+1, n, k, v);
                v.pop_back();
            } 
        }
        else{
            int last=-1;
            if(v[v.size()-1]==v[v.size()-2]){
                last=v[v.size()-1];
            }
            for(int i=1;i<=k; i++){
                if(i!=last){
                v.push_back(i);
                f(ind+1, n, k, v);
                v.pop_back();
                }
            } 
        }
    }
    long long countWays(int n, int k){
        // code here
        int e = 1e9 + 7;
        long long int dp[n+1];
        dp[1] = k%e;
        dp[2] = (k*k)%e;
        for(int i =3;i<=n;i++)
        {
            dp[i] = (((k-1)*dp[i-1])%e + (dp[i-2]*(k-1))%e)%e;
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends