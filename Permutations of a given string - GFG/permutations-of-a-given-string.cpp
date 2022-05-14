// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    
	    void f(int ind, string s, vector<string> &res){
	        if(ind==s.size()){
	           // cout<<s<<"\n";
	            res.push_back(s);
	            return;
	        }
	        
	        for(int i=ind;i<s.size();i++){
	            swap(s[ind],s[i]);
	            f(ind+1, s, res);
	            swap(s[ind],s[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    f(0, S, res);
		    sort(res.begin(),res.end());
		    return res;

		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends