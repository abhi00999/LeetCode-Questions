// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    vector<int> dist(n+1, 1e6);
	    
	   // taking source as zero and marking it's distance as 0
	    int src=0;
	    dist[src]=0;
	    
	   // Now we relax all the edges for n-1 times
	   
	   for(int i=1;i<=n-1;i++){
	       for(auto it: edges){
	           
	           if(dist[it[0]]+it[2]<dist[it[1]]){
	               dist[it[1]]=it[2]+dist[it[0]];
	           }
	       }
	   }
	   
	   int flag=0;
	   
	   //lastly we relax all the edges for one more time 
	   //if this time distance of any node decreases then there is a negative weight cycle
	   for(auto it: edges){
	           
           if(dist[it[0]]+it[2]<dist[it[1]]){
               flag=1;
               break;
           }
       }
       
       return flag;
       
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends