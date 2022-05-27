// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

// Double wale ka explanation: jab nth pe honge toh uske paas (n-1) choice honge pair krne ke,
// Jb pair kr lega kisi ek ke saath toh (n-2) friends bachenge toh isiliye recurrence kar denge aage ke liye
// aur multiply kar denge dono ko
    
    int mod=1000000007;
    long long int f(int n, long long int dp[]){
        if(n<=2) return n;
        
        if(dp[n]!=-1) return dp[n];
        
        long long int single= f(n-1, dp)%mod;
        long long int doublee= ((f(n-2, dp)%mod) *( (n-1)%mod) )%mod;
        
        return dp[n]= single%mod + doublee%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n+1];
        memset(dp, -1, sizeof(dp));
        
        return f(n, dp)%mod;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends