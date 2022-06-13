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
    
    void dfs(int ind,int cnt, int vertices){
        if(ans) return;
        vis[ind]=1;
        
        for(auto it: adj[ind]){
            if(vis[it]==0){
                dfs(it, cnt+1, vertices);
            }
        }
        
        if(cnt==vertices) ans=1;
        vis[ind]=0;
        return;
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
        
        ans=0;
        for(int i=1;i<=n;i++){
            dfs(i,1,n);
            if(ans) break;
        }
        return (ans)? 1:0;
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