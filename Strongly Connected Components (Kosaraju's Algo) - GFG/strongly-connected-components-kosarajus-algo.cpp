// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void revDfs(int node, vector<int> &vis, vector<int> transpose[]){
        vis[node]=1;
        for(auto it: transpose[node]){
            if(!vis[it]) revDfs(it, vis, transpose);
        }
    }
    void dfs(int ind, stack<int> &st, vector<int> &vis, vector<int> adj[]){
        vis[ind]=1;
        
        for(auto it: adj[ind]){
            if(vis[it]==0){
                dfs(it, st, vis, adj);
            }
        }
        
        st.push(ind);
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<int> vis(V,0);
        
        //Step1
        for(int i=0;i<=V-1;i++){
            if(vis[i]==0){
                dfs(i,st,vis,adj);
            }
        }
        
        // Step2
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            //remarking vis array to 0 so that we can use it in next step
            vis[i]=0;
            for(auto it: adj[i]){
                transpose[it].push_back(i);
            }
        }
        
        //Step3- Go on the nodes according to their finishing time
        int ans=0;
        while(!st.empty()){
            int node= st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                revDfs(node, vis, transpose);
            }
        }
        return ans;
    }
    
    
    
    
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends