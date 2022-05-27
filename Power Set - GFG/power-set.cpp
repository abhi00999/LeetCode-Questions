// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> res;
		    for(int i=1;i<pow(2,s.size());i++){
		        int j=0;
		        string tmp;
		        
		        while(j<s.size()){
		            if(i&(1<<j)) tmp.push_back(s[j]);
		            j++;
		        }
		        
		        res.push_back(tmp);
		        
		    }
		    
		    sort(res.begin(),res.end());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends