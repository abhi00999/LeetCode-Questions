// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 

class Solution
{
    public:
    vector<vector<int>> adj;
    vector<int> vis;
    int ans;
    
    bool dfs(int ind,int cnt, int vertices){
        if(cnt==vertices) return true;
        vis[ind]=1;
        
        for(auto it: adj[ind]){
            if(vis[it]==0){
                if(dfs(it, cnt+1, vertices)) return true;
            }
        }
        
        vis[ind]=0;
        return false;
    }
    bool check(int n,int m,vector<vector<int>> e)
    {
        // code here
        adj.resize(n+1);
        vis.resize(n+1,0);
        
        for(auto it: e){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=1;i<=n;i++){
            if(dfs(i,1,n)) return 1;
        }
        return 0;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends