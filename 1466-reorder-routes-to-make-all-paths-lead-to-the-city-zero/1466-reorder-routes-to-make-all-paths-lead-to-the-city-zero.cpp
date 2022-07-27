class Solution {
public:
    int ans;
    
    void dfs(int idx, vector<vector<int>> &adj, vector<vector<int>> &outgoing, vector<int> &vis){
        vis[idx]=1;
        
        for(auto it: adj[idx]){
            if(vis[it]==0){
                int flag=0;
                for(auto i: outgoing[it]) if(i==idx) flag++;
                if(!flag) ans++;
                dfs(it, adj, outgoing, vis);
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
        
        dfs(0, adj, outgoing, vis);
        return ans;
    }
};