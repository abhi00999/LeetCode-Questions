class Solution {
public:
    vector<vector<int> > adj;
    vector<int> vis;
    int ans;
    
    void dfs(int idx, vector<int> &time, int cur){
        vis[idx]=1;
        cur+= time[idx];
        
        for(auto it: adj[idx]){
            if(vis[it]==0){
                dfs(it, time, cur);
            }
        }
        ans=max(ans, cur);
        cur-= time[idx];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n+1);
        vis.resize(n+1,0);
        ans=0;
        
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            
            adj[manager[i]].push_back(i);
            adj[i].push_back(manager[i]);
        }
        
        dfs(headID, informTime, 0);
        return ans;
    }
};