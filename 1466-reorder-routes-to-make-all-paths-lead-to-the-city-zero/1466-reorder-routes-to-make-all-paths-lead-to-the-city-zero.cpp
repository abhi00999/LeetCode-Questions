class Solution {
public:
    int ans;
    
    void dfs(int parent, int idx, vector<vector<int>> &adj, vector<vector<int>> &outgoing, vector<int> &vis){
        vis[idx]=1;
        
        if(parent!=-1){
            if(find(outgoing[idx].begin(),outgoing[idx].end(),parent)==outgoing[idx].end())
                ans++;
        }
        
        for(auto it: adj[idx]){
            if(vis[it]==0){
                dfs(idx, it, adj, outgoing, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connect) {
        vector<vector<int> > adj(n);
        vector<int> vis(n,0);
        vector<vector<int> > outgoing(n);
        
        
        for(auto it: connect){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            outgoing[it[0]].push_back(it[1]);
        }
        
        dfs(-1, 0, adj, outgoing, vis);
        return ans;
    }
};