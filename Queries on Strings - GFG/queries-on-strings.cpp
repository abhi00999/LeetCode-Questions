// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	    vector<int>v;
   for (auto x : Query)
   {
      int l = x[0];
      int r = x[1];
      vector<int>ptr(26,0);
       for (int i = l - 1; i < r; i++)
           ptr[str[i] - 'a']++;
       int count = 0;
       for (int j = 0; j < 26; j++)
           if (ptr[j] != 0)
               count++;
       v.push_back(count);
   }
   return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends