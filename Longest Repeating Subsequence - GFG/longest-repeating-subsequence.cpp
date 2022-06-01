// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int f(string &s1, string &s2, int i, int j, vector<vector<int> > &dp){
	        if(i<0 || j<0) return 0;
	        
	        if(dp[i][j]!=-1) return dp[i][j];
	        
	        if(s1[i]==s2[j] && i!=j) return dp[i][j]=1+ f(s1, s2, i-1, j-1, dp);
	        
	        return dp[i][j]=max(f(s1,s2, i-1, j, dp) , f(s1,s2, i, j-1, dp));
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    vector<vector<int> > v(n, vector<int> (n,-1));
		    f(str,str, n-1,n-1 , v);
		
		    return v[n-1][n-1];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends