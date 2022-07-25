class Solution {
public:
    stack<int> s;
    vector<vector<int>> adj;
    vector<int> vis,dfsVis;
    
    int checkCycle(int i){
        vis[i]=1;
        dfsVis[i]=1;
        for(auto it: adj[i]){
            if(vis[it]==0){
                if(checkCycle(it)) return 1;
            }
            else if(dfsVis[it]) return 1;
        }
        dfsVis[i]=0;
        s.push(i);
        return 0;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        adj.resize(n);
        vis.resize(n,0);
        dfsVis.resize(n,0);
        
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(checkCycle(i)) return {};
            }
        }
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
        
    }
};