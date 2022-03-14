// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void permute(string a, int l, int r, vector<string> &res)
        {
            // Base case
            if (l == r) res.push_back(a);
            else
            {
                // Permutations made
                for (int i = l; i <= r; i++)
                {
         
                    // Swapping done
                    swap(a[l], a[i]);
         
                    // Recursion called
                    permute(a, l+1, r,res);
         
                    //backtrack
                    swap(a[l], a[i]);
                }
            }
        }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> res;
		    permute(S,0,S.size()-1,res);
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